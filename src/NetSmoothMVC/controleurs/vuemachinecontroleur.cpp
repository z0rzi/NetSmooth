#include "vuemachinecontroleur.h"
#include "modeles/DataBase.h"

VueMachineControleur::VueMachineControleur(VueMachine* vue0, VueEntiteeControleur *parent) : VueEntiteeControleur(vue0,parent)
{
    vue = vue0;

    this->connect(vue,SIGNAL(doubleClick()),this,SLOT(actionDoubleClick()));
}

void VueMachineControleur::actionDoubleClick()
{
    vue->terminal();
}
