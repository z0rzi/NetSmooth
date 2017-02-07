#include "vueentiteecontroleur.h"
#include "vues/vueprincipale.h"

VueEntiteeControleur::VueEntiteeControleur(VueEntitee* v,QObject *parent) : QObject(parent)
{
    this->vue = v;
    this->connect(this->vue,SIGNAL(moveLeftButton()),this,SLOT(actionMoveLeftButton()));
}

void VueEntiteeControleur::actionMoveLeftButton()
{
    this->vue->moveOnCursor();
}
