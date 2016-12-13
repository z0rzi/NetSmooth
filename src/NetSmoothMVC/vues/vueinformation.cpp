#include "vueinformation.h"

VueInformation::VueInformation(QWidget *parent) : QWidget(parent)
{
    this->source = NULL;

    this->setFixedSize(400,500);

    QGridLayout* layoutGlobal = new QGridLayout();
    QGridLayout* layoutIP = new QGridLayout();

    QLabel* ParamIP = new QLabel("Paramètres IP :");
    QLabel* ipv4 = new QLabel("ipv4 :");
    QLabel* mipv4 = new QLabel("masque ipv4 :");
    QLabel* ipv6 = new QLabel("ipv6 :");

    QTextEdit* eipv4 = new QTextEdit();
    QTextEdit* emipv4 = new QTextEdit();
    QTextEdit* eipv6 = new QTextEdit();

    eipv4->setFixedHeight(25);
    emipv4->setFixedHeight(25);
    eipv6->setFixedHeight(25);

    layoutIP->addWidget(ipv4,0,0);
    layoutIP->addWidget(eipv4,0,1);
    layoutIP->addWidget(mipv4,1,0);
    layoutIP->addWidget(emipv4,1,1);
    layoutIP->addWidget(ipv6,2,0);
    layoutIP->addWidget(eipv6,2,1);


    layoutRoute4 = new QGridLayout();

    QLabel* ParamRoute = new QLabel("Paramètres routage : ");
    QLabel* v4 = new QLabel("V4 :");
    QLabel* dest4 = new QLabel("destination");
    QLabel* pass4 = new QLabel("passerelle");
    QLabel* inter4 = new QLabel("interface");
    LigneRoute* route4 = new LigneRoute();

    this->setlastV4(route4);

    layoutRoute4->addWidget(dest4,0,0);
    layoutRoute4->addWidget(pass4,0,1);
    layoutRoute4->addWidget(inter4,0,2);
    layoutRoute4->addWidget(route4,1,0,1,3);
    nbrLigne4 = 1;

    layoutRoute6 = new QGridLayout();

    QLabel* v6 = new QLabel("V6 :");
    QLabel* dest6 = new QLabel("destination");
    QLabel* pass6 = new QLabel("passerelle");
    QLabel* inter6 = new QLabel("interface");
    LigneRoute* route6 = new LigneRoute();

    this->setlastV6(route6);

    layoutRoute6->addWidget(dest6,0,0);
    layoutRoute6->addWidget(pass6,0,1);
    layoutRoute6->addWidget(inter6,0,2);
    layoutRoute6->addWidget(route6,1,0,1,3);
    nbrLigne6 = 1;

    layoutGlobal->addWidget(ParamIP,0,0);
    layoutGlobal->addLayout(layoutIP,1,0);
    layoutGlobal->addWidget(ParamRoute,2,0);
    layoutGlobal->addWidget(v4,3,0);
    layoutGlobal->addLayout(layoutRoute4,4,0);
    layoutGlobal->addWidget(v6,5,0);
    layoutGlobal->addLayout(layoutRoute6,6,0);

    QLabel* allumer = new QLabel("Allumer");

    layoutGlobal->addWidget(allumer,7,0,Qt::AlignHCenter);

    this->setLayout(layoutGlobal);
}


QGridLayout* VueInformation::getLayoutRoute4()
{
    return this->layoutRoute4;
}

QGridLayout* VueInformation::getLayoutRoute6()
{
    return this->layoutRoute6;
}

int VueInformation::getNbr4()
{
    return this->nbrLigne4;
}

int VueInformation::getNbr6()
{
    return this->nbrLigne6;
}

void VueInformation::setNbr4(int n)
{
    this->nbrLigne4=n;
}

void VueInformation::setNbr6(int n)
{
    this->nbrLigne6=n;
}

void VueInformation::setlastV4(LigneRoute *lr)
{
    this->lastV4 = lr;
}

void VueInformation::setlastV6(LigneRoute *lr)
{
    this->lastV6 = lr;
}

LigneRoute* VueInformation::getLastV4()
{
    return this->lastV4;
}

LigneRoute* VueInformation::getLastV6()
{
    return this->lastV6;
}
