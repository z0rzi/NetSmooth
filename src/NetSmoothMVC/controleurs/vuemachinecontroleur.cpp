#include "vuemachinecontroleur.h"

VueMachineControleur::VueMachineControleur(VueMachine* vue0, VueEntiteeControleur *parent) : VueEntiteeControleur(parent)
{
	vue = vue0;

	connect(vue->zoneImg,SIGNAL(doubleClick()),this,SLOT(allumer()));
}

void VueMachineControleur::allumer()
{
	QPixmap* img = new QPixmap();
	if (vue->etat == false)
	{
		this->vue->etat = true;
		this->vue->ordinateur->launchEntitee();
		img->load("../build-NetSmoothMVC-Desktop-Debug/images/ordinateuron.png");
	}
	else
	{
		vue->etat = false;
		this->vue->ordinateur->stopEntitee();
		img->load("../build-NetSmoothMVC-Desktop-Debug/images/ordinateuroff.png");
	}
	*img = img->scaled(130,100);
	vue->zoneImg->setPixmap(*img);
}

