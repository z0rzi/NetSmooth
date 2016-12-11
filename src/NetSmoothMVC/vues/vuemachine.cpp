#include "vuemachine.h"
#include "modeles/DataBase.h"

VueMachine::VueMachine(VueEntitee *parent) : VueEntitee(parent)
{
    this->ordinateur = DataBase::getNewOrdinateur();
	etat = false;

	QPixmap* img = new QPixmap();
	img->load("../build-NetSmoothMVC-Desktop-Debug/images/ordinateuroff.png");
	*img = img->scaled(130,100);
    this->setPixmap(*img);
}

Ordinateur* VueMachine::getModele()
{
  return this->ordinateur;
}

