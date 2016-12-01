#include "Entitee.h"
#include "Ordinateur.h"
#include "Passerelle.h"

using namespace std;

Entitee::Entitee(int numType, int type)
{
	char nomBridge[10];
	char caratype='\0';
	if(type==TYPE_ORDINATEUR)
		m_bridgeInit="\0";
	else
	{
		if(type==TYPE_PASSERELLE)
			caratype='P';
		if(type==TYPE_HUB)
			caratype='H';
		sprintf(nomBridge, "br%c%d", caratype, numType);
		m_bridgeInit=nomBridge;
	}
	m_type=type;
	m_bridgeActuel=m_bridgeInit;
	m_running=false;
	m_estConnecteAuBridge=false;
}

string Entitee::getBridgeInit(void) const
{
	return m_bridgeInit;
}

string Entitee::getBridgeActuel(void) const
{
	return m_bridgeActuel;
}

void Entitee::setBridgeActuel(string bridge)
{
	m_bridgeActuel=bridge;
}

void Entitee::setEtatEntitee(bool etat)
{
	m_running=etat;
}

bool Entitee::getEtatEntitee()
{
	return m_running;
}

int Entitee::getType()
{
	return m_type;
}

void Entitee::addCable(Cable *cable)
{
	m_cableList.push_back(cable);
}

vector<Cable*> Entitee::getCables(void)
{
	return m_cableList;
}

void Entitee::setConnexion(bool con)
{
	m_estConnecteAuBridge=con;
}

bool Entitee::getConnexion(void) const
{
	return m_estConnecteAuBridge;
}

void Entitee::appliquerBridgeEntiteeSuivante(string bridge)
{
	int i;
	vector<Cable*> listCable=this->m_cableList;
	this->setBridgeActuel(bridge);
	this->lierABridge();
	for(i=0 ; i<listCable.size() ; i++)
	{
		Entitee* ext[2];
		Entitee* autre;
		listCable[i]->getExtremites(ext);

		if(this == ext[0])			/* ATTENTION PAS SUR QUE CA MARCHE MAIS Y A PAS DE RAISONS POUR QUE CA MARCHE PAS, LES ADRESSES DEVRAIENT ETRE LES MEMES */
			autre=ext[1];
		else
			autre=ext[0];

		if(autre->getEtatEntitee()==MACHINE_LANCEE && autre->getBridgeActuel()!=bridge)
			autre->appliquerBridgeEntiteeSuivante(bridge);
	}
}

void Entitee::modifBridgesSousReseau_entiteeStoppee()
{
	vector<Cable*> listCable=this->getCables();
	vector<Cable*> listCableValables;	/* represente tous les cables dont les deux extrémitées sont allumées */
	int i;
	
	if(this->getType()!=TYPE_HUB)
		Bridge::detruireBridge(this->getBridgeActuel().c_str());

	this->setConnexion(false);

	for(i=0 ; i<listCable.size() ; i++)
	{
		Entitee* ext[2];
		Entitee* autre;
		listCable[i]->getExtremites(ext);
		if(this == ext[0])
			autre=ext[1];
		else
			autre=ext[0];
		if(autre->getEtatEntitee()==MACHINE_LANCEE)
		{
			Bridge::creerBridge(autre->getBridgeInit().c_str());
			autre->appliquerBridgeEntiteeSuivante(autre->getBridgeInit());
		}
	}
}

void Entitee::modifBridgesSousReseau_entiteeLancee()
{
	vector<Cable*> listCable=this->getCables();
	vector<Cable*> listCableValables;	/* represente tous les cables dont les deux extrémitées sont allumées */
	int i;
	Entitee* superieur=NULL;

	for(i=0 ; i<listCable.size() ; i++)
	{
		Entitee* ext[2];
		listCable[i]->getExtremites(ext);
		if(ext[0]->getEtatEntitee()==MACHINE_LANCEE && ext[1]->getEtatEntitee()==MACHINE_LANCEE)
		{
			listCableValables.push_back(listCable[i]);
			if(ext[0]->getType() > this->getType())	/* si y a des machines de prioritée plus haute que moi dans mes environs */
				superieur=ext[0];
			if(ext[1]->getType() > this->getType())
				superieur=ext[1];
		}
	}
	if(listCable.size()==0)
		return;		/* est connecté a personne */

	if(listCableValables.size()==0)	/* est connecté a personne d'allumé */
		return;

	/* est connecté a qqn d'allumé */

	this->setConnexion(true);

	if(superieur!=NULL)	/* donc y a qqn de plus haute prioritée que mois dans mon entourage */
	{
		for(i=0 ; i<listCableValables.size() ; i++)
		{
			Entitee* ext[2];
			Entitee* autre;
			listCableValables[i]->getExtremites(ext);
			if(this == ext[0])			/* ATTENTION PAS SUR QUE CA MARCHE MAIS Y A PAS DE RAISONS POUR QUE CA MARCHE PAS, LES ADRESSES DEVRAIENT ETRE LES MEMES */
				autre=ext[1];
			else
				autre=ext[0];
			if(autre->getConnexion()==true)
			{
				cout << "superieur -> je detruis les bridges autour" << endl;
				Bridge::detruireBridge(autre->getBridgeActuel().c_str());
			}
		}
		this->appliquerBridgeEntiteeSuivante(superieur->getBridgeActuel());
	}
	else
	{
		this->setBridgeActuel(this->getBridgeInit());
		Bridge::creerBridge(this->getBridgeActuel().c_str());

		this->lierABridge();

		for(i=0 ; i<listCableValables.size() ; i++)
		{
			Entitee* ext[2];
			Entitee* autre;
			listCableValables[i]->getExtremites(ext);

			if(this == ext[0])
				autre=ext[1];
			else
				autre=ext[0];
			if((autre->getConnexion())==false)
			{
				autre->setConnexion(true);
				autre->setBridgeActuel(this->getBridgeActuel());
				autre->lierABridge();
			}
			else
			{
				cout << "pas de superieur -> je detruis les bridges autour" << endl;
				Bridge::detruireBridge(autre->getBridgeActuel().c_str());
				autre->appliquerBridgeEntiteeSuivante(this->getBridgeActuel());
			}
		}
	}
}


void Entitee::launchEntitee()
{
	cout << "lancement de " << this->getBridgeInit() << endl;
	if(this->getEtatEntitee()==MACHINE_LANCEE)
		return;

	this->lancerContainer();	/*ces 3 lignes ne font rien si c'est un Hub*/
	this->appliquerParamIp();
	this->appliquerParamRoutage();

	this->setEtatEntitee(MACHINE_LANCEE);	/* modifie flag dans entitee */
	this->modifBridgesSousReseau_entiteeLancee();

}

void Entitee::stopEntitee()
{
	cout << "arret de " << this->getBridgeInit() << endl;

	if(this->getEtatEntitee()==MACHINE_STOPEE)
		return;


	this->stopperContainer();

	this->setEtatEntitee(MACHINE_STOPEE);	/* modifie flag dans entitee */
	this->modifBridgesSousReseau_entiteeStoppee();

	/*reste a supprimer les cables*/
}
