#include "vuemachine.h"

VueMachine::VueMachine(VueEntitee *parent) : VueEntitee(parent)
{
	this->ordi = DataBase::getNewOrdinateur();
	etat = false;
	zoneImg = new ClickLabel();
	QPixmap* img = new QPixmap();
	img->load("../build-NetSmoothMVC-Desktop-Debug/images/ordinateuroff.png");
	*img = img->scaled(130,100);
	zoneImg->setPixmap(*img);
}

