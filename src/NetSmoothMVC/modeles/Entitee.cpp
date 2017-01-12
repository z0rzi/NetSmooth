#include "Entitee.h"
#include "Ordinateur.h"
#include "Passerelle.h"

#include "Cable.h"
#include "vues/vueentitee.h"

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
        if(this->getConnexion()==true)
                this->separerDeBridge();
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
                        this->appliquerBridgeEntiteeSuivante(superieur->getBridgeInit());
                else
                        this->appliquerBridgeEntiteeSuivante(superieur->getBridgeActuel());
        }
}

bool Entitee::verifAlone(Entitee* source)
{
        int i;
        bool alone=true;
        vector<Cable*> listCable=this->getCables();
        for(i=0 ; i<listCable.size() && alone ; i++)
        {
                Entitee* ext[2];
                Entitee* autre;
                listCable[i]->getExtremites(ext);
                autre=(this==ext[0])?ext[1]:ext[0];
                if(autre->getEtatEntitee()==MACHINE_LANCEE && autre!=source)
                {
                        alone=false;
                        cout << "po tout seul" << endl;
                }
        }
        return alone;
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

        /* si son bridge actuel est un bridge init de son entourage, on le
         * supprime pas
         */
        for(i=0 ; i<listCable.size() ; i++)
        {
                Entitee* ext[2];
                Entitee* autre;
                listCable[i]->getExtremites(ext);
                autre=(this==ext[0])?ext[1]:ext[0];
                if(autre->getEtatEntitee()==true && this->getBridgeActuel().compare(autre->getBridgeInit())==0 && autre->verifAlone(this)==false)    /* ce sont les memes */
                {
                        supprBridge=false;
                }
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
                        if(autre->verifAlone(this)==true)
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
        this->appliquerParamRoutage4();
        this->appliquerParamRoutage6();

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


void Entitee::setVue(VueEntitee* v)
{
    this->m_vue=v;
}

VueEntitee* Entitee::getVue()
{
    return this->m_vue;
}

Entitee::~Entitee()
{
}
