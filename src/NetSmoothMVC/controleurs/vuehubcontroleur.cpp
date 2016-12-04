#include "vuehubcontroleur.h"

VueHubControleur::VueHubControleur(VueHub* vue0, VueEntiteeControleur *parent) : VueEntiteeControleur(parent)
{
    vue = vue0;

    connect(vue->zoneImg,SIGNAL(doubleClick()),this,SLOT(allumer()));
}

void VueHubControleur::allumer()
{
    QPixmap* img = new QPixmap();
    if (vue->etat == false)
    {
        vue->etat = true;
        img->load("../build-NetSmoothMVC-Desktop-Debug/images/Hubon");
    }
    else
    {
        vue->etat = false;
        img->load("../build-NetSmoothMVC-Desktop-Debug/images/Huboff");
    }
    *img = img->scaled(130,100);
    vue->zoneImg->setPixmap(*img);
}

