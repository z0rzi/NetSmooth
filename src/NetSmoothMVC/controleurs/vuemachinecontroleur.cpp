#include "vuemachinecontroleur.h"
#include "modeles/DataBase.h"

VueMachineControleur::VueMachineControleur(VueMachine* vue0, VueEntiteeControleur *parent) : VueEntiteeControleur(parent)
{
    vue = vue0;

    connect(vue,SIGNAL(rightClick()),this,SLOT(allumer()));
    connect(vue,SIGNAL(doubleClick()),this,SLOT(terminal()));
}

void VueMachineControleur::allumer()
{
	QPixmap* img = new QPixmap();
	if (vue->etat == false)
	{
		this->vue->etat = true;
        this->vue->getModele()->launchEntitee();
		img->load("../build-NetSmoothMVC-Desktop-Debug/images/ordinateuron.png");
	}
	else
	{
		vue->etat = false;
        this->vue->getModele()->stopEntitee();
		img->load("../build-NetSmoothMVC-Desktop-Debug/images/ordinateuroff.png");
	}
	*img = img->scaled(130,100);
    vue->setPixmap(*img);
}

void VueMachineControleur::terminal()
{
        if (vue->etat == true)
                this->vue->getModele()->lancerXterm();
}
