#include "VueFormulaireIPControleur.h"

VueFormulaireIPControleur::VueFormulaireIPControleur(VueFormulaireIP* vue0, QPushButton* refr, QPushButton* valider,QObject *parent) : QObject(parent)
{
    this->vue = vue0;
    connect(valider,SIGNAL(clicked()),this,SLOT(appliquerModif()));
    connect(refr,SIGNAL(clicked()),this,SLOT(refresh()));
}

void VueFormulaireIPControleur::appliquerModif()
{
    this->vue->appliquerModification();
}

void VueFormulaireIPControleur::refresh()
{
    this->vue->getModele()->lireModifContainer();
    this->vue->refresh();
}
