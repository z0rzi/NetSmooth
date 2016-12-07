#include "Machine.h"
#include "Cable.h"
#include "Entitee.h"
#include "ElementListeChainee.h"
#include "DataBase.h"
#include "Ordinateur.h"
#include "Passerelle.h"


//!\\ Refaire la classe Machine(nécessite uniquement id).

using namespace std;

int DataBase::m_nbreOrdinateur = 0;
int DataBase::m_nbrePasserelle = 0;
int DataBase::m_nbreHub = 0;

ElementListeChainee* DataBase::m_premierOrdinateur=NULL;
ElementListeChainee* DataBase::m_premierePasserelle=NULL;
ElementListeChainee* DataBase::m_premierHub=NULL;

Ordinateur* DataBase::getNewOrdinateur(void)
{
  int id;
  bool idAvailable=false;//ID de nouvelle machine trouvé
  for(id=0 ; id < DataBase::m_nbreOrdinateur && !idAvailable; id++)
  {
    ElementListeChainee* elemActuel = DataBase::m_premierOrdinateur;
    idAvailable=true;

    while(elemActuel!=NULL && idAvailable){
      if(elemActuel->getEntitee()->getID()==id)
        idAvailable=false;

      elemActuel=elemActuel->getNextElement();
    } 
  }

  if(id==0)//Cas où aucun ordinateur n'existe
    DataBase::m_premierOrdinateur = new ElementListeChainee(new Ordinateur(id),NULL);//On remplace le premier maillon de la liste par le nouvel ordinateur.
  else
    DataBase::m_premierOrdinateur = new ElementListeChainee(new Ordinateur(id-1),DataBase::m_premierOrdinateur);//On remplace le premier maillon de la liste par le nouvel ordinateur.

  DataBase::m_nbreOrdinateur+=1;
  return (Ordinateur*) DataBase::m_premierOrdinateur->getEntitee();
}




Passerelle* DataBase::getNewPasserelle(void)
{
  int id;
  bool idAvailable=false;//ID de nouvelle machine trouvé
  for(id=0 ; id < DataBase::m_nbrePasserelle && !idAvailable; id++)
  {
    ElementListeChainee* elemActuel = DataBase::m_premierePasserelle;
    idAvailable=true;

    while(elemActuel!=NULL && idAvailable){
      if(elemActuel->getEntitee()->getID()==id)
        idAvailable=false;

      elemActuel=elemActuel->getNextElement();
    } 
  }
  if(id==0)//Cas où aucune passerelle n'existe
    DataBase::m_premierePasserelle = new ElementListeChainee(new Passerelle(id),NULL);
  else
    DataBase::m_premierePasserelle = new ElementListeChainee(new Passerelle(id-1),DataBase::m_premierePasserelle);

  DataBase::m_nbrePasserelle+=1;
  return (Passerelle*) DataBase::m_premierePasserelle->getEntitee();
}


Hub* DataBase::getNewHub(void)
{
  int id;
  bool idAvailable=false;//ID de nouvelle machine trouvé
  for(id=0 ; id < DataBase::m_nbreHub && !idAvailable; id++)
  {
    ElementListeChainee* elemActuel = DataBase::m_premierePasserelle;
    idAvailable=true;

    while(elemActuel!=NULL && idAvailable){
      if(elemActuel->getEntitee()->getID()==id)
        idAvailable=false;

      elemActuel=elemActuel->getNextElement();
    } 
  }
  if(id==0)//Cas où aucun hub n'existe
    DataBase::m_premierHub = new ElementListeChainee(new Hub(id),NULL);
  else
    DataBase::m_premierHub = new ElementListeChainee(new Hub(id-1),DataBase::m_premierHub);

  DataBase::m_nbreHub+=1;
  return (Hub*) DataBase::m_premierHub->getEntitee();
}



void DataBase::detruireOrdinateur(Ordinateur* ordi)
{
  int id = ordi->getID();//A coder
  ElementListeChainee* elemActuel = DataBase::m_premierOrdinateur;
  if(elemActuel==NULL)
    return;
  else if(elemActuel->getEntitee()->getID()==id)//Cas où c'est le premier élément à supprimer
  {
    DataBase::m_premierOrdinateur = elemActuel->getNextElement();
    delete elemActuel;

    DataBase::m_nbreOrdinateur-=1;
    return;
  }
  else
    while(elemActuel->getNextElement()!=NULL)
    {
      if(elemActuel->getNextElement()->getEntitee()->getID()==id)//ID Machine de Element suivant est le bon
      {
        elemActuel->setNextElement(elemActuel->getNextElement()->getNextElement());//Element actuel prend comme suivant le suivant de l'élément détruit
        delete elemActuel->getNextElement();

        DataBase::m_nbreOrdinateur-=1;
        return;
      }
      else
      {
        elemActuel = elemActuel->getNextElement();
      }
    }
}

void DataBase::detruirePasserelle(Passerelle* passerelle)
{
  int id = passerelle->getID();//A coder
  ElementListeChainee* elemActuel = DataBase::m_premierePasserelle;
  if(elemActuel==NULL)
    return;
  else if(elemActuel->getEntitee()->getID()==id)//Cas où c'est le premier élément à supprimer
  {
    DataBase::m_premierePasserelle = elemActuel->getNextElement();
    delete elemActuel;

    DataBase::m_nbrePasserelle-=1;
    return;
  }
  else
    while(elemActuel->getNextElement()!=NULL)
    {
      if(elemActuel->getNextElement()->getEntitee()->getID()==id)//ID Machine de Element suivant est le bon
      {
        elemActuel->setNextElement(elemActuel->getNextElement()->getNextElement());//Element actuel prend comme suivant le suivant de l'élément détruit
        delete elemActuel->getNextElement();

        DataBase::m_nbrePasserelle-=1;
        return;
      }
      else
      {
        elemActuel = elemActuel->getNextElement();
      }
    }
}

void DataBase::detruireHub(Hub* hub)
{
  int id = hub->getID();//A coder
  ElementListeChainee* elemActuel = DataBase::m_premierHub;
  if(elemActuel==NULL)
    return;
  else if(elemActuel->getEntitee()->getID()==id)//Cas où c'est le premier élément à supprimer
  {
    DataBase::m_premierHub = elemActuel->getNextElement();
    delete elemActuel;

    DataBase::m_nbreHub-=1;
    return;
  }
  else
    while(elemActuel->getNextElement()!=NULL)
    {
      if(elemActuel->getNextElement()->getEntitee()->getID()==id)//ID Machine de Element suivant est le bon
      {
        elemActuel->setNextElement(elemActuel->getNextElement()->getNextElement());//Element actuel prend comme suivant le suivant de l'élément détruit
        delete elemActuel->getNextElement();

        DataBase::m_nbreHub-=1;
        return;
      }
      else
      {
        elemActuel = elemActuel->getNextElement();
      }
    }
}


