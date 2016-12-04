#include "vuemachinecontroleur.h"

VueMachineControleur::VueMachineControleur(VueMachine* vue0, VueEntiteeControleur *parent) : VueEntiteeControleur(parent)
{
    vue = vue0;

    connect(vue->zoneImg,SIGNAL(doubleClick()),this,SLOT(allumer()));
}

void VueMachineControleur::allumer()
{
    QPixmap* img = new QPixmap();
    if (vue->etat == false)
    {
        vue->etat = true;
        img->load("images/ordinateuron.png");
    }
    else
    {
        vue->etat = false;
        img->load("images/ordinateuroff.png");
    }
    *img = img->scaled(130,100);
    vue->zoneImg->setPixmap(*img);
}

