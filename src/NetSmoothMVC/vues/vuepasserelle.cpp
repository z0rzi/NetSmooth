#include "vuepasserelle.h"

VuePasserelle::VuePasserelle(VueEntitee *parent) : VueEntitee(parent)
{
	this->passerelle=DataBase::getNewPasserelle();
	etat = false;
	zoneImg = new ClickLabel();
	QPixmap* img = new QPixmap();
	img->load("../build-NetSmoothMVC-Desktop-Debug/images/passerelleoff.png");
	*img = img->scaled(130,100);
	zoneImg->setPixmap(*img);
}
