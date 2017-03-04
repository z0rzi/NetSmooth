#include "vuemachine.h"
#include "modeles/DataBase.h"
#include <iostream>

using namespace std;

VueMachine::VueMachine(VueEntitee *parent) : VueEntitee(parent)
{
    this->ordinateur = DataBase::getNewOrdinateur();
	etat = false;

	QPixmap* img = new QPixmap();
    img->load(QCoreApplication::applicationDirPath()+"/images/ordinateuroff.png");
    cout << QCoreApplication::applicationDirPath().toStdString() << "/images/ordinateuroff.png" << endl;
    *img = img->scaled(130,130);
    this->setPixmap(*img);
    this->ordinateur->setVue(this);
}

Ordinateur* VueMachine::getModele()
{
  return this->ordinateur;
}

void VueMachine::terminal()
{
    if (this->etat == true)
            this->getModele()->lancerXterm();
}

