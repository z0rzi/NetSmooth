#include "vuepasserellecontroleur.h"

VuePasserelleControleur::VuePasserelleControleur(VuePasserelle* vue0, VueEntiteeControleur *parent) : VueEntiteeControleur(parent)
{
	vue = vue0;

    connect(vue,SIGNAL(doubleClick()),this,SLOT(terminal()));

}


void VuePasserelleControleur::terminal()
{
        if (vue->etat == true)
                this->vue->getModele()->lancerXterm();
}
