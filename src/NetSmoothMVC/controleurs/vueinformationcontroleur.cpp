#include "vueinformationcontroleur.h"

VueInformationControleur::VueInformationControleur(VueInformation* vue0, QObject *parent) : QObject(parent)
{
    vue = vue0;
    connect(this->vue->getAllumer(),SIGNAL(clicked(bool)),this,SLOT(actionClickAllumer()));
}

void VueInformationControleur::actionClickAllumer()
{
   this->vue->allumer();
}
