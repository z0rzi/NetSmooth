#include "vuepasserellecontroleur.h"

VuePasserelleControleur::VuePasserelleControleur(VuePasserelle* vue0, VueEntiteeControleur *parent) : VueEntiteeControleur(parent)
{
	vue = vue0;

    connect(vue,SIGNAL(rightClick()),this,SLOT(allumer()));
    connect(vue,SIGNAL(doubleClick()),this,SLOT(terminal()));

}

void VuePasserelleControleur::allumer()
{
	QPixmap* img = new QPixmap();
	if (vue->etat == false)
	{
		vue->etat = true;
        this->vue->getModele()->launchEntitee();
		img->load("../build-NetSmoothMVC-Desktop-Debug/images/passerelleon");
	}
	else
	{
		vue->etat = false;
        this->vue->getModele()->stopEntitee();
		img->load("../build-NetSmoothMVC-Desktop-Debug/images/passerelleoff");
	}
    *img = img->scaled(130,130);
    vue->setPixmap(*img);
}


void VuePasserelleControleur::terminal()
{
        if (vue->etat == true)
                this->vue->getModele()->lancerXterm();
}
