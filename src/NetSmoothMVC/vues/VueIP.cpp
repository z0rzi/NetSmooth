#include "VueIP.h"

VueIP::VueIP(QWidget *parent) :
        QGridLayout(parent)
{
    /***TEST DONC AJOUT UN FORMULAIRE***/
    QLabel* paramIP = new QLabel("Paramètres IP :");
    VueFormulaireIP* v = new VueFormulaireIP();

    this->addWidget(paramIP,0,0,Qt::AlignHCenter);
}

void VueIP::refresh()
{
    Entitee* modele = VueEntitee::getLabelEnSelection()->getModele();

    /***ACTUALISER LE NOMBRE DE FORMULAIRES***/
    this->m_formulairesIP.clear();

    if(modele->getType()==TYPE_HUB);
    else if(modele->getType() == TYPE_ORDINATEUR)
    {
        for(int i = 0 ; i < NOMBRE_INTERFACES_ORDINATEUR ; i++)
        {
            VueFormulaireIP* v = new VueFormulaireIP();
            std::cout << v << std::endl;
            this->m_formulairesIP.push_back(v);
            //this->m_formulairesIP.push_back(new VueFormulaireIP());
        }
    }
    else if(modele->getType() == TYPE_PASSERELLE)
    {
        for(int i = 0 ; i < NOMBRE_INTERFACES_PASSERELLE ; i++)
            this->m_formulairesIP.push_back(new VueFormulaireIP());
    }

    /***REMPLIR LES FORMULAIRES***/
    if(modele->getType() != TYPE_HUB)
    {
        for( unsigned int i = 0 ; i < modele->getIpConfig().size() ; i++)
        {
            this->m_formulairesIP[i]->setIpv4(QString::fromStdString(modele->getIpConfig()[i].ipv4));
            this->m_formulairesIP[i]->setIpv6(QString::fromStdString(modele->getIpConfig()[i].ipv6));
            this->m_formulairesIP[i]->setMask(QString::fromStdString(modele->getIpConfig()[i].maskv4));
        }
    }
    /***SUPPRIMER LES FORMULAIRES DÉJÀ AFFICHÉES***/
    this->clearLayout(this);


    /***AFFICHER LES FORMULAIRES***/
    this->addWidget(new QLabel("Paramètres IP :"),0,0,Qt::AlignHCenter);

    for(unsigned int i = 0 ; i < this->m_formulairesIP.size() ;i++)
        this->addLayout(this->m_formulairesIP[i],i+1,0);

}


void VueIP::clearLayout(QLayout *layout)
{
    QLayoutItem *item;
    while ((item = layout->takeAt(1)))
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
