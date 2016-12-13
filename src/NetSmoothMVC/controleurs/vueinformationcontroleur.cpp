#include "vueinformationcontroleur.h"

VueInformationControleur::VueInformationControleur(VueInformation* vue0, QObject *parent) : QObject(parent)
{
    vue = vue0;
    connect(this->vue->getLastV4()->getValider(),SIGNAL(clicked(bool)),this,SLOT(ajoutLigne4()));
    connect(this->vue->getLastV6()->getValider(),SIGNAL(clicked(bool)),this,SLOT(ajoutLigne6()));
}

void VueInformationControleur::ajoutLigne4()
{
    QPushButton* b = qobject_cast<QPushButton*>(sender());
    if(b->text() == "OK")
    {
        int n;
        vue->getLastV4()->bloquer();
        LigneRoute* newLigne = new LigneRoute();
        QGridLayout* layout = new QGridLayout();
        layout = vue->getLayoutRoute4();
        n = vue->getNbr4()+1;
        vue->getLastV4()->getValider()->setText("X");
        layout->addWidget(newLigne,n,0,1,3);
        vue->setNbr4(n+1);
        connect(newLigne->getValider(),SIGNAL(clicked(bool)),this,SLOT(ajoutLigne4()));
        vue->setlastV4(newLigne);
    }
    else if(b->text() == "X")
    {
        b->parentWidget()->deleteLater();
        vue->setNbr4(vue->getNbr4()-1);
    }
}

void VueInformationControleur::ajoutLigne6()
{
    QPushButton* b = qobject_cast<QPushButton*>(sender());
    if(b->text() == "OK")
    {
        int n;
        vue->getLastV6()->bloquer();
        LigneRoute* newLigne = new LigneRoute();
        QGridLayout* layout = new QGridLayout();
        layout = vue->getLayoutRoute6();
        n = vue->getNbr6()+1;
        vue->getLastV6()->getValider()->setText("X");
        layout->addWidget(newLigne,n,0,1,3);
        vue->setNbr6(n+1);
        connect(newLigne->getValider(),SIGNAL(clicked(bool)),this,SLOT(ajoutLigne6()));
        vue->setlastV6(newLigne);
    }
    else if(b->text() == "X")
    {
        b->parentWidget()->deleteLater();
        vue->setNbr6(vue->getNbr6()-1);
    }
}
