#include "Entitee.h"
#include "Ordinateur.h"
#include "Passerelle.h"

using namespace std;

Entitee::Entitee(int id, int type) :m_id(id)

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
                sprintf(nomBridge, "br%c%d", caratype, id);
                m_bridgeInit=nomBridge;
        }
        m_type=type;
        m_bridgeActuel=m_bridgeInit;
        m_running=false;
        m_estConnecteAuBridge=false;
}

string Entitee::getBridgeInit(void) const
{
        return this->m_bridgeInit;
}

string Entitee::getBridgeActuel(void) const
{
        return this->m_bridgeActuel;
}

void Entitee::setBridgeActuel(string bridge)
{
        this->m_bridgeActuel=bridge;
}

void Entitee::setEtatEntitee(bool etat)
{
        this->m_running=etat;
}

bool Entitee::getEtatEntitee()
{
        return this->m_running;
}

int Entitee::getType()
{
        return this->m_type;
}

void Entitee::addCable(Cable *cable)
{
        m_cableList.push_back(cable);
}

vector<Cable*> Entitee::getCables(void)
{
        return this->m_cableList;
}

void Entitee::setConnexion(bool con)
{
        this->m_estConnecteAuBridge=con;
}

bool Entitee::getConnexion(void) const
{
        return this->m_estConnecteAuBridge;
}

void Entitee::setID(int id)
{
        this->m_id = id;
}

int Entitee::getID(void)
{
        return this->m_id;
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
                autre=(this==ext[0])?ext[1]:ext[0];

                if(autre->getEtatEntitee()==MACHINE_LANCEE && autre->getBridgeActuel()!=bridge)
                        autre->appliquerBridgeEntiteeSuivante(bridge);
        }
}


void Entitee::modifBridgesSousReseau_entiteeLancee()
{
        vector<Cable*> listCable=this->getCables();
        int i=0;
        Entitee* superieur=NULL;
        bool machineValide=false;
        bool qqnAutour=false;

        for(i=0 ; i<listCable.size() && superieur==NULL ; i++)
        {
                Entitee* autre;
                Entitee* ext[2];
                machineValide=false;
                while(!machineValide && i<listCable.size())   /* permet de ne prendre en consideeration que les machines allumees */
                {
                        listCable[i]->getExtremites(ext);
                        autre=(this==ext[0])?ext[1]:ext[0];
                        if(autre->getEtatEntitee()==MACHINE_LANCEE)
                        {
                                machineValide=true;
                                qqnAutour=true;
                        }
                        else
                                i++;
                }
                if(autre->getType()>this->getType())
                {
                        superieur=autre;
                        i=-1;
                }
        }
        if(!qqnAutour)        /* personne dans les environs */
        {
                cout << "personne de valable autour" << endl ;
                return;
        }
        this->setConnexion(true);
        if(superieur==NULL)
        {
                cout << "je suis le plus fort" << endl;
                for(i=0 ; i<listCable.size() && superieur==NULL ; i++)
                {
                        Entitee* autre;
                        Entitee* ext[2];
                        listCable[i]->getExtremites(ext);
                        autre=(this==ext[0])?ext[1]:ext[0];
                        if(autre->getEtatEntitee()==true)
                        {
                                if(autre->getConnexion()==false)
                                        autre->setConnexion(true);
                                else
                                        Bridge::detruireBridge(autre->getBridgeActuel().c_str());
                        }
                }
                Bridge::creerBridge(this->getBridgeInit().c_str());
                this->appliquerBridgeEntiteeSuivante(this->getBridgeInit());
        }
        else
        {
                cout << "quelqu'un est plus fort que moi : " << superieur->getBridgeInit() << endl;
                cout << "son etat est : " << ((superieur->getConnexion())?"connecte":"non connecte") << endl;
                bool supAlone=false;
                if(superieur->getConnexion()==false)
                {
                        superieur->setConnexion(true);
                        Bridge::creerBridge(superieur->getBridgeInit().c_str());
                        supAlone=true;
                }
                for(i=0 ; i<listCable.size(); i++)
                {
                        Entitee* autre;
                        Entitee* ext[2];
                        listCable[i]->getExtremites(ext);
                        autre=(this==ext[0])?ext[1]:ext[0];
                        if(autre->getEtatEntitee()==true && autre!=superieur)
                        {
                                if(autre->getConnexion()==false)
                                        autre->setConnexion(true);
                                else
                                        Bridge::detruireBridge(autre->getBridgeActuel().c_str());
                        }
                }
                if(supAlone)
                        superieur->appliquerBridgeEntiteeSuivante(superieur->getBridgeInit());
                else
                        this->appliquerBridgeEntiteeSuivante(superieur->getBridgeActuel());
        }

        // vector<Cable*> listCable=this->getCables();
        //vector<Cable*> listCableValables;	/* represente tous les cables dont les deux extrémitées sont allumées */
        //int i;
        //Entitee* superieur=NULL;
        //
        //   for(i=0 ; i<listCable.size() ; i++)
        //   {
        //       Entitee* ext[2];
        //       listCable[i]->getExtremites(ext);
        //       if(ext[0]->getEtatEntitee()==MACHINE_LANCEE && ext[1]->getEtatEntitee()==MACHINE_LANCEE)
        //       {
        //           listCableValables.push_back(listCable[i]);
        //           if(ext[0]->getType() > this->getType())	/* si y a des machines de prioritée plus haute que moi dans mes environs */
        //               superieur=ext[0];
        //           if(ext[1]->getType() > this->getType())
        //               superieur=ext[1];
        //       }
        //   }
        //   if(listCable.size()==0)
        //   {
        //           cout << "connecte a personne" << endl;
        //           return;		/* est connecté a personne */
        //   }
        //
        //   if(listCableValables.size()==0)	/* est connecté a personne d'allumé */
        //   {
        //           cout << "connecte a personne d'allume" << endl;
        //           return;
        //   }
        //
        //   /* est connecté a qqn d'allumé */
        //
        //   this->setConnexion(true);
        //
        //   if(superieur!=NULL)	/* donc y a qqn de plus haute prioritée que moi dans mon entourage */
        //   {
        //           cout << "j'ai un superieur dans les environs : " << superieur->getBridgeInit() << endl;
        //           for(i=0 ; i<listCableValables.size() ; i++)
        //           {
        //                   Entitee* ext[2];
        //                   Entitee* autre;
        //                   listCableValables[i]->getExtremites(ext);
        //                   if(this == ext[0])
        //                           autre=ext[1];
        //                   else
        //                           autre=ext[0];
        //                   cout << "autre = " << autre->getBridgeInit() << endl;
        //                   if(autre->getConnexion()!=true)
        //                   {
        //                           autre->setConnexion(true);
        //                           Bridge::creerBridge(autre->getBridgeInit().c_str());
        //                           autre->setBridgeActuel(autre->getBridgeInit());
        //                   }
        //                   if(this->getType()!=TYPE_ORDINATEUR)
        //                           Bridge::detruireBridge(this->getBridgeActuel().c_str());
        //           }
        //           this->appliquerBridgeEntiteeSuivante(superieur->getBridgeActuel());
        //   }
        //   else
        //   {
        //           this->setBridgeActuel(this->getBridgeInit());
        //           Bridge::creerBridge(this->getBridgeActuel().c_str());
        //
        //           this->lierABridge();
        //
        //           for(i=0 ; i<listCableValables.size() ; i++)
        //           {
        //                   Entitee* ext[2];
        //                   Entitee* autre;
        //                   listCableValables[i]->getExtremites(ext);
        //
        //                   if(this == ext[0])
        //                           autre=ext[1];
        //                   else
        //                           autre=ext[0];
        //                   if((autre->getConnexion())==false)
        //                   {
        //                           autre->setConnexion(true);
        //                           autre->setBridgeActuel(this->getBridgeActuel());
        //                           autre->lierABridge();
        //                   }
        //                   else
        //                   {
        //                           cout << "pas de superieur -> je detruis les bridges autour" << endl;
        //                           Bridge::detruireBridge(autre->getBridgeActuel().c_str());
        //                           autre->appliquerBridgeEntiteeSuivante(this->getBridgeActuel());
        //                   }
        //           }
        //   }
}

void Entitee::modifBridgesSousReseau_entiteeStoppee()
{
        vector<Cable*> listCable=this->getCables();
        vector<Entitee*> alones;
        int i, j;
        bool supprBridge=true, onlyAlones=true;

        if(this->getConnexion()==false)
                return;

        this->setConnexion(false);

        for(i=0 ; i<listCable.size() ; i++)
        {
                Entitee* ext[2];
                Entitee* autre;
                listCable[i]->getExtremites(ext);
                autre=(this==ext[0])?ext[1]:ext[0];
                if(autre->getEtatEntitee()==true && this->getBridgeActuel().compare(autre->getBridgeInit())==0)    /* ce sont les memes */
                        supprBridge=false;
        }
        if(supprBridge)
        {
                Bridge::detruireBridge(this->getBridgeActuel().c_str());
                cout << "bridgeActuel de " << this->getBridgeInit() << " detruit" << endl;
        }
        this->setBridgeActuel("\0");

        for(i=0 ; i<listCable.size() ; i++)
        {
                Entitee* ext[2];
                Entitee* autre;
                listCable[i]->getExtremites(ext);
                autre=(this==ext[0])?ext[1]:ext[0];
                if(autre->getEtatEntitee()==MACHINE_LANCEE)
                {
                        bool alone=true;
                        vector<Cable*> a_listCable=autre->getCables();
                        for(j=0 ; j<a_listCable.size() && alone ; j++)
                        {
                                Entitee* a_ext[2];
                                Entitee* a_autre;
                                a_listCable[j]->getExtremites(a_ext);
                                a_autre=(autre==a_ext[0])?a_ext[1]:a_ext[0];
                                if(a_autre->getEtatEntitee()==MACHINE_LANCEE && a_autre!=this)
                                {
                                        alone=false;
                                        cout << "po tout seul" << endl;
                                }
                        }
                        if(alone)
                        {
                                cout << "autre tout seul" << endl;
                                if(supprBridge)
                                        Bridge::detruireBridge(autre->getBridgeActuel().c_str());
                                autre->separerDeBridge();
                                //autre->setBridgeActuel("\0");
                                autre->setConnexion(false);
                                alones.push_back(autre);
                        }
                        else
                        {
                                Bridge::creerBridge(autre->getBridgeInit().c_str());
                                autre->appliquerBridgeEntiteeSuivante(autre->getBridgeInit());
                                onlyAlones=false;
                        }
                }
        }
        if(onlyAlones)
        {
                for(i=0 ; i<alones.size() ; i++)
                {
                        Bridge::detruireBridge(alones[i]->getBridgeActuel().c_str());
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

Entitee::~Entitee()
{
}
