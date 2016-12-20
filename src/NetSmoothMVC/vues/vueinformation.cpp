#include "vueinformation.h"

VueInformation* VueInformation::instance = NULL;

VueInformation* VueInformation::getInstanceOf()
{
    if(VueInformation::instance==NULL)
        VueInformation::instance=new VueInformation();
    return VueInformation::instance;
}

VueInformation::VueInformation(QWidget *parent) : QWidget(parent)
{

    this->setFixedSize(400,500);

    QGridLayout* layoutGlobal = new QGridLayout();
    QGridLayout* layoutIP = new QGridLayout();

    QLabel* ParamIP = new QLabel("Paramètres IP :");
    QLabel* ipv4 = new QLabel("ipv4 :");
    QLabel* mipv4 = new QLabel("masque ipv4 :");
    QLabel* ipv6 = new QLabel("ipv6 :");

    eipv4 = new QTextEdit();
    emipv4 = new QTextEdit();
    eipv6 = new QTextEdit();

    eipv4->setFixedHeight(25);
    emipv4->setFixedHeight(25);
    eipv6->setFixedHeight(25);

    layoutIP->addWidget(ipv4,0,0);
    layoutIP->addWidget(eipv4,0,1);
    layoutIP->addWidget(mipv4,1,0);
    layoutIP->addWidget(emipv4,1,1);
    layoutIP->addWidget(ipv6,2,0);
    layoutIP->addWidget(eipv6,2,1);

    this->routes4 = new VueRoutes();
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
    layoutGlobal->addLayout(routes4,2,0);
    layoutGlobal->addWidget(v6,3,0);
    layoutGlobal->addLayout(layoutRoute6,4,0);

    this->allumer = new QPushButton();
    allumer->setText("Allumer");

    layoutGlobal->addWidget(allumer,7,0,Qt::AlignHCenter);

    this->setLayout(layoutGlobal);
}

void VueInformation::refresh(QWidget *s)
{
    this->setSource(s);
    this->getRoutes()->setSource(VueEntitee::getLabelEnSelection()->getModele());
    emit refresh();
}

void VueInformation::setSource(QWidget *s)
{
    this->source = s;
}
QWidget* VueInformation::getSource()
{
    return this->source;
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

QTextEdit* VueInformation::getEipv4()
{
    return this->eipv4;
}

QTextEdit* VueInformation::getEmipv4()
{
    return this->emipv4;
}

QTextEdit* VueInformation::getEipv6()
{
    return this->eipv6;
}

void VueInformation::vider()
{
    this->eipv4->setText("");
    this->emipv4->setText("");
    this->eipv6->setText("");
}

void VueInformation::setLayout4(QGridLayout *l4)
{
    this->layoutRoute4 = l4;
}

void VueInformation::setAllumer(QPushButton * p)
{
    this->allumer = p;
}

QPushButton* VueInformation::getAllumer()
{
    return this->allumer;
}

VueRoutes* VueInformation::getRoutes()
{
    return this->routes4;
}

void VueInformation::setRoutes(VueRoutes *v)
{
    this->routes4 = v;
}
