#include <iostream>
#include <string>
#include <cstdlib>
#include <signal.h>
#include <lxc/lxccontainer.h>
#include <unistd.h>
#include <strings.h>

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
}

void separerContainerEtBridge(lxc_container* c, const char* bridge)
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
		execl("./unjoinCntAndBridge.sh", "joinCntBridge", cntName, bridge, NULL);
		exit(0);
	}
}

/* 
*	lance un xterm representnt le terminal d'une Machine (donc d'un container)
*/
void lancerXterm(Machine* m)
{
	int x=fork();
	lxc_container* c=m->getContainer();

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

/*
 *	ATTENTION Fonction compliquée (plus ou moins)
 *	
 *	permet de modifier tous les bridges d'un sous-réseau
 *	
 *
 *		ARGS:
 *	
 *	-e: 		entitée (passerelle hub ou machine) de laquel on commence a modifier les bridge
 *	
 *	-bridge:	doit toujours etre egal a "\0", cette fonction est recursive, l'argument bridge
 *			sera utilisé quand la fonction va se rappeller elle meme (lignes 229 231 au moment ou j'ecris)
 *	
 *	
 *		RETURN VALUE
 *	
 *	la valeur de retour est le bridge (string) auquel tout le monde s'est associé
 *	OU
 *	"\0" en cas d'erreur
 */
string modifBridgesSousReseau(Entitee* e, string bridge)
{
	sleep(1);
	cout << "je passe : " << e->getType() << endl;
	int i;
	vector<Cable*> listCable;
	if(bridge=="\0")
	{			/* ne s'execute que au premier passage: permet de determiner le bridge a adopter par
				 * le sous-reseau*/
		cout << "premier tour" << endl;
		int ok=-1;
		listCable=e->getCables();
		for(i=0 ; i<listCable.size() && ok==-1 ; i++)
		{					/* on verifie qu'il y a des machines allumées connectées*/
			Entitee* ext[2];
			listCable[i]->getExtremites(ext);
			if(ext[0]->getEtatMachine()==1 && ext[1]->getEtatMachine()==1)
			{
				ok=i;
			}
		}
		if(ok==-1)
		{					/* si y a pas de liens, on prend le bridge 'virtuel', et on
							 * a personne d'autre a modifier, donc on quitte  */
			cout << "aucunes connexions" << endl;
			bridge=e->getBridge_vir();
			creerBridge(bridge.c_str());
			lxc_container* cont;
			if(e->getType()=='M')
			{
				cont=((Machine*)e)->getContainer();
				if(e->getBridge_reel()!="\0")			/* si y a deja un bridge, on l'enleve */
				{						/* mais normalement ca devrias pas passer
										 * par la: c'est le premier tour, donc 
										 * bridge_reel devrait etre egal a "\0" */
					separerContainerEtBridge(cont, e->getBridge_reel().c_str());
					e->setBridge_reel("\0");
					cout << e->getType() << " prend bridge " << "NULL" << endl;
				}
				sleep(1);
				lierContainerEtBridge(cont, bridge.c_str());
				cout << "ici" << endl;
			}
			if(e->getType()=='P')
			{
				cont=((Passerelle*)e)->getContainer();
				if(e->getBridge_reel()!="\0")			/* si y a deja un bridge, on l'enleve*/
				{						/* mais meme chose qu'au dessus */
					separerContainerEtBridge(cont, e->getBridge_reel().c_str());
					cout << e->getType() << " separe bridge " << e->getBridge_reel() << endl;
					e->setBridge_reel("\0");
					cout << e->getType() << " prend bridge NULL " << endl;
				}
				sleep(1);
				lierContainerEtBridge(cont, bridge.c_str());
				cout << e->getType() << " prend bridge " << bridge << endl;
			}
			e->setBridge_reel(bridge);
			cout << e->getType() << " prend bridge " << bridge << endl;
			return "\0";
		}
		/* si y a des liens, le bridge a 'adopter' est le bridge
		 ** de la premiere machine allumée connectée*/
		Entitee* ext[2];
		listCable[ok]->getExtremites(ext);
		if(ext[0]->getBridge_vir()!=e->getBridge_vir())	/* on regarde quelle extremité du cable est    */
			bridge=ext[0]->getBridge_reel();		/* le container en argument de cette fonction  */
		else
			bridge=ext[1]->getBridge_reel();
		creerBridge(bridge.c_str());
	}
	else
		listCable=e->getCables();

	lxc_container* cont;
	if(e->getType()=='M')
	{
		cont=((Machine*)e)->getContainer();
		if(e->getBridge_reel()!="\0")			/*si y a deja un bridge, on l'enleve*/
		{
			separerContainerEtBridge(cont, e->getBridge_reel().c_str());
			cout << e->getType() << " separe bridge " << e->getBridge_reel() << endl;
			e->setBridge_reel("\0");
			cout << e->getType() << " prend bridge NULL " << endl;
		}
		sleep(1);					
		lierContainerEtBridge(cont, bridge.c_str());	/* et on se lie au bon bridge */
		cout << e->getType() << " prend bridge " << bridge << endl;
	}
	if(e->getType()=='P')
	{
		cont=((Passerelle*)e)->getContainer();
		if(e->getBridge_reel()!="\0")			/*si y a deja un bridge, on l'enleve*/
		{
			separerContainerEtBridge(cont, e->getBridge_reel().c_str());
			cout << e->getType() << " separe bridge " << e->getBridge_reel() << endl;
			e->setBridge_reel("\0");
			cout << e->getType() << " prend bridge NULL " << endl;
		}
		sleep(1);
		lierContainerEtBridge(cont, bridge.c_str());	/* et on se lit au bon bridge */
		cout << e->getType() << " prend bridge " << bridge << endl;
	}

	e->setBridge_reel(bridge);
	for(i=0 ; i<listCable.size() ; i++)
	{
		Entitee* extremitees[2];
		listCable[i]->getExtremites(extremitees);

		if(extremitees[0]->getBridge_reel()!=bridge && extremitees[0]->getEtatMachine()==1)
			modifBridgesSousReseau(extremitees[0], bridge);
		if(extremitees[1]->getBridge_reel()!=bridge && extremitees[1]->getEtatMachine()==1)
			modifBridgesSousReseau(extremitees[1], bridge);
	}

	return bridge;	/*retourne le bridge auquel tout le monde s'est attaché*/
}

int lancerCommande(char** commande, struct lxc_container *c)
{	/* ex: lancerCommance({"ifconfig", "eth0", "192.168.0.15", "up"}, c);
	 *   pas convaincu, que le premier 
	 *   arg fonctionne comme ca*/
	lxc_attach_options_t options = LXC_ATTACH_OPTIONS_DEFAULT;
	lxc_attach_command_t cmd={commande[0], commande};		/* rien de compliqué par ici, juste */
	pid_t pid=c->init_pid(c);					/* transférer les arguments la ou il faut
									 * pour lancer une commande dans le container*/

	c->attach(c, lxc_attach_run_command, &cmd, &options, &pid);
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

void launchMachine(Machine *m)
{
	if(m->getEtatMachine()==1)
		return;			/*si l'entitee est deja lancé, on s'en va*/

	lancerContainer(m->getContainer());

	m->setEtatMachine(MACHINE_LANCEE);	/* modifie flag dans entitee */

	modifBridgesSousReseau(m, "\0");
}

void launchHub(Hub *h)
{
	if(h->getEtatMachine()==1)
		return;			/*si l'entitee est deja lancé, on s'en va*/

	h->setEtatMachine(MACHINE_LANCEE);

	modifBridgesSousReseau(h, "\0");
}

int main(void)
{
	struct lxc_container* cnt1=lxc_container_new("machine0", NULL);
	struct lxc_container* cnt2=lxc_container_new("machine1", NULL);

	Machine m0(cnt1), m1(cnt2);

	Hub h;

	Cable c0(&m0, &h);
	m0.addCable(&c0);
	h.addCable(&c0);

	Cable c1(&m1, &h);
	m0.addCable(&c1);
	h.addCable(&c1);

	launchMachine(&m0);
	launchMachine(&m1);
	launchHub(&h);

	lancerXterm(&m0);
	lancerXterm(&m1);

	cout << "entrez quelque chose pour finir" << endl;
	int bobo;
	cin >> bobo;

	return 0;
}
