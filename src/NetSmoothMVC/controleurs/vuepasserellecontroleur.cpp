#include "vuepasserellecontroleur.h"

VuePasserelleControleur::VuePasserelleControleur(VuePasserelle* vue0, VueEntiteeControleur *parent) : VueEntiteeControleur(parent)
{
	vue = vue0;

//	connect(vue->zoneImg,SIGNAL(doubleClick()),this,SLOT(allumer()));
}

void VuePasserelleControleur::allumer()
{
	QPixmap* img = new QPixmap();
	if (vue->etat == false)
	{
		vue->etat = true;
        this->vue->getPasserelle()->launchEntitee();
		img->load("../build-NetSmoothMVC-Desktop-Debug/images/passerelleon");
	}
	else
	{
		vue->etat = false;
        this->vue->getPasserelle()->stopEntitee();
		img->load("../build-NetSmoothMVC-Desktop-Debug/images/passerelleoff");
	}
	*img = img->scaled(130,100);
	vue->zoneImg->setPixmap(*img);
}
