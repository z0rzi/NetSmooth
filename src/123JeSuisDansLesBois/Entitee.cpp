#include "Entitee.h"
#include "Ordinateur.h"
#include "Passerelle.h"

using namespace std;

Entitee::Entitee(int numType, int type)
{
  char nomBridge[10];
  char caratype='\0';
  if(type==TYPE_MACHINE)
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

void Entitee::setEtatMachine(bool etat)
{
  m_running=etat;
}

bool Entitee::getEtatMachine()
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
  if(this->getType()==TYPE_MACHINE)
    ((Ordinateur*)this)->lierABridge();
  if(this->getType()==TYPE_PASSERELLE)
    ((Passerelle*)this)->lierABridge();
  for(i=0 ; i<listCable.size() ; i++)
  {
    Entitee* ext[2];
    Entitee* autre;
    listCable[i]->getExtremites(ext);

    if(this == ext[0])			/* ATTENTION PAS SUR QUE CA MARCHE MAIS Y A PAS DE RAISONS POUR QUE CA MARCHE PAS, LES ADRESSES DEVRAIENT ETRE LES MEMES */
      autre=ext[1];
    else
      autre=ext[0];

    if(autre->getEtatMachine()==MACHINE_LANCEE && autre->getBridgeActuel()!=bridge)
      autre->appliquerBridgeEntiteeSuivante(bridge);
  }
}
void Entitee::modifBridgesSousReseau()
{
  vector<Cable*> listCable=this->getCables();
  vector<Cable*> listCableValables;	/* represente tous les cables dont les deux extrémitées sont allumées */
  int i;
  Entitee* superieur=NULL;

  for(i=0 ; i<listCable.size() ; i++)
  {
    Entitee* ext[2];
    listCable[i]->getExtremites(ext);
    if(ext[0]->getEtatMachine()==MACHINE_LANCEE && ext[1]->getEtatMachine()==MACHINE_LANCEE)
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

    if(this->getType()==TYPE_MACHINE)	/* ne devrais pas passer par la car si il a pas de superieur et que c'est une machine, ca veut dire pas de connexions */
      ((Ordinateur*)this)->lierABridge();
    if(this->getType()==TYPE_PASSERELLE)
      ((Passerelle*)this)->lierABridge();

    for(i=0 ; i<listCableValables.size() ; i++)
    {
      Entitee* ext[2];
      Entitee* autre;
      listCableValables[i]->getExtremites(ext);

      if(this == ext[0])			/* ATTENTION PAS SUR QUE CA MARCHE MAIS Y A PAS DE RAISONS POUR QUE CA MARCHE PAS, LES ADRESSES DEVRAIENT ETRE LES MEMES */
        autre=ext[1];
      else
        autre=ext[0];
      if((autre->getConnexion())==false)
      {
        autre->setConnexion(true);
        autre->setBridgeActuel(this->getBridgeActuel());
        if(autre->getType()==TYPE_MACHINE)
          ((Ordinateur*)autre)->lierABridge();
        if(autre->getType()==TYPE_PASSERELLE)
          ((Passerelle*)autre)->lierABridge();
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
  if(this->getEtatMachine()==MACHINE_LANCEE)//avant, c'était ==1, mais je suppose que c'était pour dire machine_lancee (vincent)
    return;

  if(this->getType()==TYPE_MACHINE)
  {
    ((Ordinateur*)this)->lancerContainer();
    ((Ordinateur*)this)->appliquerParamIp();
    ((Ordinateur*)this)->appliquerParamRoutage();
  }
  if(this->getType()==TYPE_PASSERELLE)
  {
    ((Passerelle*)this)->lancerContainer();
    ((Passerelle*)this)->appliquerParamIp();
    ((Passerelle*)this)->appliquerParamRoutage();
  }

  this->setEtatMachine(MACHINE_LANCEE);	/* modifie flag dans entitee */
  this->modifBridgesSousReseau();

}
