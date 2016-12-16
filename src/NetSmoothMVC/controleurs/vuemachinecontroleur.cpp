#include "vuemachinecontroleur.h"
#include "modeles/DataBase.h"

VueMachineControleur::VueMachineControleur(VueMachine* vue0, VueEntiteeControleur *parent) : VueEntiteeControleur(parent)
{
    vue = vue0;

    connect(vue,SIGNAL(doubleClick()),this,SLOT(terminal()));
}

void VueMachineControleur::terminal()
{
        if (vue->etat == true)
                this->vue->getModele()->lancerXterm();
}
