#include "vuepasserelle.h"
#include "modeles/DataBase.h"

VuePasserelle::VuePasserelle(VueEntitee *parent) : VueEntitee(parent)
{
	this->passerelle=DataBase::getNewPasserelle();
    this->etat = false;
	QPixmap* img = new QPixmap();
	img->load("../build-NetSmoothMVC-Desktop-Debug/images/passerelleoff.png");
    *img = img->scaled(130,130);
    this->setPixmap(*img);
    this->passerelle->setVue(this);
}

Passerelle* VuePasserelle::getModele()
{
    return this->passerelle;
}

void VuePasserelle::setPasserelle(Passerelle *passerelle0)
{
    this->passerelle = passerelle0;
}

void VuePasserelle::terminal()
{
    if (this->etat == true)
            this->getModele()->lancerXterm();
}
