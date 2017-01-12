#include "vueinformationcontroleur.h"

VueInformationControleur::VueInformationControleur(VueInformation* vue0, QObject *parent) : QObject(parent)
{
    vue = vue0;
    connect(this->vue->getAllumer(),SIGNAL(clicked(bool)),this,SLOT(actionClickAllumer()));
    connect(this->vue->getSauvegarder(),SIGNAL(clicked(bool)),this,SLOT(actionClickSauvegarder()));
}

void VueInformationControleur::actionClickAllumer()
{
   this->vue->allumer();
}

void VueInformationControleur::actionClickSauvegarder()
{
   this->vue->sauvegarder();
}
