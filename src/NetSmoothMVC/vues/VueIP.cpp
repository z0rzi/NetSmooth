#include "VueIP.h"

VueIP::VueIP(QWidget *parent) :
    QGridLayout(parent)
{
    /***TEST DONC AJOUT UN FORMULAIRE***/
    QLabel* paramIP = new QLabel("Paramètres IP :");
    VueFormulaireIP* v = new VueFormulaireIP();

    this->addWidget(paramIP,0,0,Qt::AlignHCenter);
    this->addLayout(v,1,0);
}

void VueIP::refresh()
{

    Entitee* modele = VueEntitee::getLabelEnSelection()->getModele();

    /***ACTUALISER LE NOMBRE DE FORMULAIRES***/
    this->m_formulairesIP.clear();

    if(modele->getType()==TYPE_HUB)
        return;
    else if(modele->getType() == TYPE_ORDINATEUR)
    {
        for(int i = 0 ; i < NOMBRE_INTERFACES_ORDINATEUR ; i++)
        this->m_formulairesIP.push_back(new VueFormulaireIP());
    }
    else if(modele->getType() == TYPE_HUB)
    {
        for(int i = 0 ; i < NOMBRE_INTERFACES_PASSERELLE ; i++)
            this->m_formulairesIP.push_back(new VueFormulaireIP());
    }

    /***REMPLIR LES FORMULAIRES***/

    if(modele->getType() != TYPE_HUB)
    {
    for( int i = 0 ; i < modele->getIpConfig().size() ; i++)
        this->m_formulairesIP[i]->setIpv4(modele->getIpConfig()[i].ipv4);

    }

   

}

