#include "vuepasserellecontroleur.h"

VuePasserelleControleur::VuePasserelleControleur(VuePasserelle* vue0, VueEntiteeControleur *parent) : VueEntiteeControleur(parent)
{
    vue = vue0;

    connect(vue->zoneImg,SIGNAL(doubleClick()),this,SLOT(allumer()));
}

void VuePasserelleControleur::allumer()
{
    QPixmap* img = new QPixmap();
    if (vue->etat == false)
    {
        vue->etat = true;
        img->load("/home/user/NetSmooth/NetSmoothMVC/images/passerelleon");
    }
    else
    {
        vue->etat = false;
        img->load("/home/user/NetSmooth/NetSmoothMVC/images/passerelleoff");
    }
    *img = img->scaled(130,100);
    vue->zoneImg->setPixmap(*img);
}
