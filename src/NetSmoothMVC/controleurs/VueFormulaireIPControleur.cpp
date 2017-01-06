#include "VueFormulaireIPControleur.h"

VueFormulaireIPControleur::VueFormulaireIPControleur(VueFormulaireIP* vue0, QObject *parent) : QObject(parent)
{
    this->vue = vue0;
    connect(this->vue,SIGNAL(valider()),this,SLOT(refresh()));
}


void VueFormulaireIPControleur::appliquerModif()
{
    //TODO
}
