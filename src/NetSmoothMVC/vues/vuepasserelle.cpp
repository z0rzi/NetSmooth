#include "vuepasserelle.h"
#include "modeles/DataBase.h"

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

Passerelle* VuePasserelle::getPasserelle()
{
    return this->passerelle;
}

void VuePasserelle::setPasserelle(Passerelle *passerelle0)
{
    this->passerelle = passerelle0;
}
