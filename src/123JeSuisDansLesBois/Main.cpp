#include <iostream>
#include <string>
#include <cstdlib>
#include <signal.h>
#include <lxc/lxccontainer.h>
#include <unistd.h>
#include <strings.h>
#include <sys/wait.h>
#include <sys/types.h>

#include "Constantes.h"
#include "Machine.h"
#include "Passerelle.h"
#include "Cable.h"
#include "Hub.h"

using namespace std;

void creerBridge(const char* nomPont)
{
	int x=fork();

	if(x==-1)
	{
		perror("fork");
		exit(1);
	}
	if(x==0)
	{
		execl("./creerBridge.sh", "createBridge", nomPont, NULL);
		exit(0);
	}
	int useless;
	while(waitpid(0, &useless, WUNTRACED)<0);
}

void detruireBridge(const char* nomPont)
{
	int x=fork();

	if(x==-1)
	{
		perror("fork");
		exit(1);
	}
	if(x==0)
	{
		execl("./detruireBridge.sh", "destroyBridge", nomPont, NULL);
		exit(0);
	}
	int useless;
	while(waitpid(0, &useless, WUNTRACED)<0);
}

void lierContainerEtBridge(lxc_container* c, const char* bridge)
{
	int x=fork();

	if(x==-1)
	{
		perror("fork");
		exit(1);
	}
	if(x==0)
	{
		char cntName[20];
		c->get_config_item(c, "lxc.utsname", cntName, 20);
		execl("./joinCntAndBridge.sh", "joinCntBridge", cntName, bridge, NULL);
		exit(0);
	}
	int useless;
	while(waitpid(0, &useless, WUNTRACED)<0);
}

/* 
*	lance un xterm representnt le terminal d'une Machine (donc d'un container)
*/
void lancerXterm(Entitee* e)
{
	int x=fork();
	lxc_container* c;
	if(e->getType()==TYPE_MACHINE)
		c=((Machine*)e)->getContainer();
	if(e->getType()==TYPE_PASSERELLE)
		c=((Passerelle*)e)->getContainer();
	if(e->getType()==TYPE_HUB)
		return;

	if(x==-1)
	{
		perror("fork");
		exit(1);
	}
	if(x==0)
	{
		char cntName[20];
		c->get_config_item(c, "lxc.utsname", cntName, 20);
		execl("./launchXtermRoot.sh", "launchCnt", cntName, NULL);
		exit(0);
	}
}

void appliquerBridgeEntiteeSuivante(Entitee* e, string bridge)
{
	int i;
	vector<Cable*> listCable=e->getCables();
	e->setBridgeActuel(bridge);
	if(e->getType()==TYPE_MACHINE)
		lierContainerEtBridge(((Machine*)e)->getContainer(), e->getBridgeActuel().c_str());
	if(e->getType()==TYPE_PASSERELLE)
		lierContainerEtBridge(((Passerelle*)e)->getContainer(), e->getBridgeActuel().c_str());
	for(i=0 ; i<listCable.size() ; i++)
	{
		Entitee* ext[2];
		Entitee* autre;
		listCable[i]->getExtremites(ext);

		if(e == ext[0])			/* ATTENTION PAS SUR QUE CA MARCHE MAIS Y A PAS DE RAISONS POUR QUE CA MARCHE PAS, LES ADRESSES DEVRAIENT ETRE LES MEMES */
			autre=ext[1];
		else
			autre=ext[0];

		if(autre->getEtatMachine()==MACHINE_LANCEE && autre->getBridgeActuel()!=bridge)
			appliquerBridgeEntiteeSuivante(autre, bridge);
	}

}

void modifBridgesSousReseau(Entitee* e)
{
	vector<Cable*> listCable=e->getCables();
	vector<Cable*> listCableValables;	/* represente tous les cables dont les deux extrémitées sont allumées */
	int i;
	Entitee* supperieur=NULL;

	for(i=0 ; i<listCable.size() ; i++)
	{
		Entitee* ext[2];
		listCable[i]->getExtremites(ext);
		if(ext[0]->getEtatMachine()==MACHINE_LANCEE && ext[1]->getEtatMachine()==MACHINE_LANCEE)
		{
			listCableValables.push_back(listCable[i]);
			if(ext[0]->getType() > e->getType())	/* si y a des machines de prioritée plus haute que moi dans mes environs */
				supperieur=ext[0];
			if(ext[1]->getType() > e->getType())
				supperieur=ext[1];
		}
	}
	if(listCable.size()==0)
		return;		/* est connecté a personne */

	if(listCableValables.size()==0)	/* est connecté a personne d'allumé */
		return;

	/* est connecté a qqn d'allumé */

	e->setConnexion(true);

	if(supperieur!=NULL)	/* donc y a qqn de plus haute prioritée que mois dans mon entourage */
	{
		for(i=0 ; i<listCableValables.size() ; i++)
		{
			Entitee* ext[2];
			Entitee* autre;
			listCableValables[i]->getExtremites(ext);
			if(e == ext[0])			/* ATTENTION PAS SUR QUE CA MARCHE MAIS Y A PAS DE RAISONS POUR QUE CA MARCHE PAS, LES ADRESSES DEVRAIENT ETRE LES MEMES */
				autre=ext[1];
			else
				autre=ext[0];
			if(autre->getConnexion()==true)
			{
				cout << "superieur -> je detruit les bridges autour" << endl;
				detruireBridge(autre->getBridgeActuel().c_str());
			}
		}
		appliquerBridgeEntiteeSuivante(e, supperieur->getBridgeActuel());
	}
	else
	{
		e->setBridgeActuel(e->getBridgeInit());
		creerBridge(e->getBridgeActuel().c_str());
		if(e->getType()==TYPE_MACHINE)	/* ne devrais pas passer par la car si il a pas de supperieur et que c'est une machine, ca veut dire pas de connexions */
			lierContainerEtBridge(((Machine*)e)->getContainer(), e->getBridgeActuel().c_str());
		if(e->getType()==TYPE_PASSERELLE)
			lierContainerEtBridge(((Passerelle*)e)->getContainer(), e->getBridgeActuel().c_str());
		for(i=0 ; i<listCableValables.size() ; i++)
		{
			Entitee* ext[2];
			Entitee* autre;
			listCableValables[i]->getExtremites(ext);

			if(e == ext[0])			/* ATTENTION PAS SUR QUE CA MARCHE MAIS Y A PAS DE RAISONS POUR QUE CA MARCHE PAS, LES ADRESSES DEVRAIENT ETRE LES MEMES */
				autre=ext[1];
			else
				autre=ext[0];
			if(autre->getConnexion()==false)
			{
				autre->setConnexion(true);
				autre->setBridgeActuel(e->getBridgeActuel());
				if(autre->getType()==TYPE_MACHINE)
					lierContainerEtBridge(((Machine*)autre)->getContainer(), autre->getBridgeActuel().c_str());
				if(autre->getType()==TYPE_PASSERELLE)
					lierContainerEtBridge(((Passerelle*)autre)->getContainer(), autre->getBridgeActuel().c_str());
			}
			else
			{
				cout << "pas de superieur -> je detruit les bridges autour" << endl;
				detruireBridge(autre->getBridgeActuel().c_str());
				appliquerBridgeEntiteeSuivante(autre, e->getBridgeActuel());
			}
		}
	}
}

int lancerCommandeDansContainer(const char** commande, struct lxc_container *c)
{	/* ex: lancerCommance({"ifconfig", "eth0", "192.168.0.15", "up"}, c);
	 *   pas convaincu, que le premier 
	 *   arg fonctionne comme ca*/
	lxc_attach_options_t options = LXC_ATTACH_OPTIONS_DEFAULT;
	lxc_attach_command_t cmd={(char*)commande[0], (char**)commande};		/* rien de compliqué par ici, juste */
	pid_t pid=c->init_pid(c);					/* transférer les arguments la ou il faut
									 * pour lancer une commande dans le container*/

	c->attach(c, lxc_attach_run_command, &cmd, &options, &pid);
}

void appliquerParamIp(Entitee* e)
{
	if(e->getType()==TYPE_HUB)
		return;

	lxc_container* c;
	int i;

	c=((Ordinateur*)e)->getContainer();
	vector<struct paramIp> tab=((Ordinateur*)e)->getIpConfig();
	for(i=0 ; i<tab.size() ; i++)
	{
		const char* cmd[]={"ifconfig", tab[i].interface.c_str(), tab[i].ipv4.c_str(), "netmask", tab[i].maskv4.c_str(), "up"};
		cout << "i = " << i << endl;
		cout << "cmd = " << cmd [0] << cmd [1] << cmd [2] << cmd [3] << cmd [4] << cmd [5] << endl;
		sleep(1);

		lxc_attach_options_t options = LXC_ATTACH_OPTIONS_DEFAULT;
		lxc_attach_command_t commande={(char*)cmd[0], (char**)cmd};		/* rien de compliqué par ici, juste */
		pid_t pid=c->init_pid(c);					/* transférer les arguments la ou il faut
										 * pour lancer une commande dans le container*/

		c->attach(c, lxc_attach_run_command, &commande, &options, &pid);
	}
}

void appliquerParamRoutage(Entitee* e)
{
}

int stoperContainer(struct lxc_container* cnt)
{
	int tst;

	tst = cnt->shutdown(cnt, 10);
	if(!tst)
	{
		printf("Failed to cleanly stop the container, forcing.\n");
		tst = cnt->stop(cnt);	/*plus violent que shutdown*/
		if(!tst) {
			cout << "Failed to stop the container, forcing even more" << endl;
			pid_t pid = cnt->init_pid(cnt);
			tst = kill(pid, SIGINT);	/* kill le PID en dernier recours */
			if(tst==-1)
			{
				cout << "impossible to close the container, I give up" << endl;
				exit(1);
			}
		}
	}
	cout << "container succefully stopped" << endl;
	return 0;
}

int lancerContainer(struct lxc_container* cnt)
{
	int tst;

	tst = cnt->start(cnt, 0, NULL);
	if(!tst)
	{
		cout << "Failed to start the container" << endl;
		return -1;
	}
	cout << "container succefully started" << endl;
	return 0;
}

void launchEntitee(Entitee* e)
{
	cout << "lancement de " << e->getBridgeInit() << endl;
	if(e->getEtatMachine()==1)
		return;

	if(e->getType()==TYPE_MACHINE)
		lancerContainer(((Machine*)e)->getContainer());
	if(e->getType()==TYPE_PASSERELLE)
		lancerContainer(((Passerelle*)e)->getContainer());

	e->setEtatMachine(MACHINE_LANCEE);	/* modifie flag dans entitee */

	modifBridgesSousReseau(e);

	appliquerParamIp(e);
	appliquerParamRoutage(e);
}

int main(void)
{
	struct lxc_container* cnt1=lxc_container_new("machine0", NULL);
	struct lxc_container* cnt2=lxc_container_new("machine1", NULL);
	struct lxc_container* cnt3=lxc_container_new("gateway0", NULL);

	Machine m0(cnt1), m1(cnt2);
	Passerelle p(cnt3);

	struct paramIp ip={"eth0", "192.168.0.10", "255.255.255.0", "", ""};
	m0.addIpConfig(ip);

	ip.ipv4="172.16.0.10";
	m1.addIpConfig(ip);

	ip.ipv4="172.16.0.1";
	p.addIpConfig(ip);
	ip.interface="eth1";
	ip.ipv4="192.168.0.1";
	p.addIpConfig(ip);


	Hub h0, h1;

	Cable c0(&m0, &h0);
	m0.addCable(&c0);
	h0.addCable(&c0);

	Cable c1(&m1, &h1);
	m1.addCable(&c1);
	h1.addCable(&c1);

	Cable c2(&p, &h0);
	p.addCable(&c2);
	h0.addCable(&c2);

	Cable c3(&p, &h1);
	p.addCable(&c3);
	h1.addCable(&c3);

	launchEntitee(&m0);
	launchEntitee(&m1);
	launchEntitee(&h0);
	launchEntitee(&h1);
	launchEntitee(&p);

	lancerXterm(&m0);
	lancerXterm(&m1);
	lancerXterm(&p);

	cout << "entrez quelque chose pour finir" << endl;
	int bobo;
	cin >> bobo;

	stoperContainer(cnt1);
	stoperContainer(cnt2);
	stoperContainer(cnt3);


	return 0;
}
