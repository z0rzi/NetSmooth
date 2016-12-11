#include "vuemachinecontroleur.h"
#include "modeles/DataBase.h"

VueMachineControleur::VueMachineControleur(VueMachine* vue0, VueEntiteeControleur *parent) : VueEntiteeControleur(parent)
{
    vue = vue0;

    //connect(vue->zoneImg,SIGNAL(doubleClick()),this,SLOT(allumer()));
    connect(vue->zoneImg,SIGNAL(rightClick()),this,SLOT(allumer()));
    connect(vue->zoneImg,SIGNAL(doubleClick()),this,SLOT(terminal()));
}

void VueMachineControleur::allumer()
{
	QPixmap* img = new QPixmap();
	if (vue->etat == false)
	{
		this->vue->etat = true;
        this->vue->getOrdinateur()->launchEntitee();
		img->load("../build-NetSmoothMVC-Desktop-Debug/images/ordinateuron.png");
	}
	else
	{
		vue->etat = false;
        this->vue->getOrdinateur()->stopEntitee();
		img->load("../build-NetSmoothMVC-Desktop-Debug/images/ordinateuroff.png");
	}
	*img = img->scaled(130,100);
	vue->zoneImg->setPixmap(*img);
}

void VueMachineControleur::terminal()
{
        if (vue->etat == true)
                this->vue->getOrdinateur()->lancerXterm();
}
