#include "vuemachine.h"
#include "modeles/DataBase.h"

VueMachine::VueMachine(VueEntitee *parent) : VueEntitee(parent)
{
    this->ordinateur = DataBase::getNewOrdinateur();
	etat = false;
	zoneImg = new ClickLabel();
	QPixmap* img = new QPixmap();
	img->load("../build-NetSmoothMVC-Desktop-Debug/images/ordinateuroff.png");
	*img = img->scaled(130,100);
	zoneImg->setPixmap(*img);
}

Ordinateur* VueMachine::getOrdinateur()
{
  return this->ordinateur;
}

