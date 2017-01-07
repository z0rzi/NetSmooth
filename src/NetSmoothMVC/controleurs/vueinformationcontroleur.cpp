#include "vueinformationcontroleur.h"

VueInformationControleur::VueInformationControleur(VueInformation* vue0, QObject *parent) : QObject(parent)
{
    vue = vue0;
    //connect(this->vue->getLastV4()->getValider(),SIGNAL(clicked(bool)),this,SLOT(ajoutLigne4()));
  //  connect(this->vue->getLastV6()->getValider(),SIGNAL(clicked(bool)),this,SLOT(ajoutLigne6()));
    //connect(this->vue->getRoutes(),SIGNAL(refresh()),this,SLOT(refreshVue()));
    connect(this->vue->getAllumer(),SIGNAL(clicked(bool)),this,SLOT(allumer()));
}

void VueInformationControleur::allumer()
{
    QPixmap* img = new QPixmap();
    VueEntitee* vueE = VueEntitee::getLabelEnSelection();
    if (vueE == NULL)
    {
        cout << "erreur selection" << endl;
        return;
    }
    if(vueE->getModele()->getType()==TYPE_ORDINATEUR)
    {
        if (vueE->etat == false)
        {
            vueE->etat = true;
            struct paramIp ip;
            ip.ipv4=vue->getEipv4()->toPlainText().toStdString();
            ip.maskv4=vue->getEmipv4()->toPlainText().toStdString();
            ip.ipv6=vue->getEipv6()->toPlainText().toStdString();
            ip.interface="eth0";
            Machine* m = (Machine*)vueE->getModele();
            m->addIpConfig(ip);
            vueE->getModele()->launchEntitee();
            img->load("../build-NetSmoothMVC-Desktop-Debug/images/ordinateuron.png");
            *img = img->scaled(130,130);
            vueE->setPixmap(*img);
        }
        else
        {
            vueE->etat = false;
            vueE->getModele()->stopEntitee();
            img->load("../build-NetSmoothMVC-Desktop-Debug/images/ordinateuroff.png");
            *img = img->scaled(130,130);
            vueE->setPixmap(*img);
        }
    }
    else if(vueE->getModele()->getType()==TYPE_PASSERELLE)
    {
        if (vueE->etat == false)
        {
            vueE->etat = true;
            struct paramIp ip;
            ip.ipv4=vue->getEipv4()->toPlainText().toStdString();
            ip.maskv4=vue->getEmipv4()->toPlainText().toStdString();
            ip.ipv6=vue->getEipv6()->toPlainText().toStdString();
            ip.interface="eth0";
            Passerelle* p = (Passerelle*)vueE->getModele();
            p->addIpConfig(ip);
            vueE->getModele()->launchEntitee();
            img->load("../build-NetSmoothMVC-Desktop-Debug/images/passerelleon.png");
            *img = img->scaled(130,130);
            vueE->setPixmap(*img);
        }
        else
        {
            vueE->etat = false;
            vueE->getModele()->stopEntitee();
            img->load("../build-NetSmoothMVC-Desktop-Debug/images/passerelleoff.png");
            *img = img->scaled(130,130);
            vueE->setPixmap(*img);
        }
    }
    else if(vueE->getModele()->getType()==TYPE_HUB)
    {
        if (vueE->etat == false)
        {
            vueE->etat = true;
            Hub* p = (Hub*)vueE->getModele();
            vueE->getModele()->launchEntitee();
            img->load("../build-NetSmoothMVC-Desktop-Debug/images/Hubon.png");
            *img = img->scaled(130,130);
            vueE->setPixmap(*img);
        }
        else
        {
            vueE->etat = false;
            vueE->getModele()->stopEntitee();
            img->load("../build-NetSmoothMVC-Desktop-Debug/images/Huboff.png");
            *img = img->scaled(130,130);
            vueE->setPixmap(*img);
        }
    }
}
