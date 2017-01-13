#include "VueIP.h"

VueIP::VueIP(QWidget *parent) :
        QGridLayout(parent)
{
    /***TEST DONC AJOUT UN FORMULAIRE***/
    QLabel* paramIP = new QLabel("Paramètres IP :");

    this->addWidget(paramIP,0,0,Qt::AlignHCenter);
}

void VueIP::refresh()
{
    Entitee* modele = VueEntitee::getLabelEnSelection()->getModele();

    /***CREER LES NOUVEAUX FORMULAIRES***/
    this->m_formulairesIP.clear();

    if(modele->getType()==TYPE_HUB);
    else if(modele->getType() == TYPE_ORDINATEUR)
    {
        for(int numInterface = 0 ; numInterface < NOMBRE_INTERFACES_ORDINATEUR ; numInterface++)
            this->m_formulairesIP.push_back(new VueFormulaireIP(numInterface,modele));
    }
    else if(modele->getType() == TYPE_PASSERELLE)
    {
        for(int numInterface = 0 ; numInterface < NOMBRE_INTERFACES_PASSERELLE ; numInterface++)
            this->m_formulairesIP.push_back(new VueFormulaireIP(numInterface,modele));
    }

    /***SUPPRIMER LES FORMULAIRES DÉJÀ AFFICHÉES***/
    this->clearLayout(this);


    /***AFFICHER LES FORMULAIRES***/
    this->addWidget(new QLabel("Paramètres IP :"),0,0,Qt::AlignHCenter);

    for(unsigned int i = 0 ; i < this->m_formulairesIP.size() ;i++)
        this->addLayout(this->m_formulairesIP[i],i+1,0);

    /***RAFRAICHIR LES FORMULAIRES***/
    for(unsigned int i = 0 ; i < this->m_formulairesIP.size() ;i++)
        this->m_formulairesIP[i]->refresh();
}

void VueIP::clearLayout(QLayout *layout)
{
    QLayoutItem *item;
    while ((item = layout->takeAt(0)))
    {
        if (item->layout())
        {
            clearLayout(item->layout());
            delete item->layout();
        }
        delete item->widget();
        // delete item;
    }
}

