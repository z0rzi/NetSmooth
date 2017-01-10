#include "vueprincipalecontroleur.h"

VuePrincipaleControleur::VuePrincipaleControleur(VuePrincipale *vue0,QObject *parent) : QObject(parent)
{
    vue = vue0;

    connect(vue,SIGNAL(clickSouris(QPoint)),this,SLOT(actionClickSouris(QPoint)));
}

void VuePrincipaleControleur::actionClickSouris(QPoint pos)
{
    vue->paintEntitee(pos);
}
