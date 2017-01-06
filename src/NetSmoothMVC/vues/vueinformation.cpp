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

    this->routes = new VueRoutes();

    this->vueIP = new VueIP();

    layoutGlobal->addLayout(this->vueIP,0,0);
    layoutGlobal->addLayout(routes,1,0);

    this->allumer = new QPushButton();
    allumer->setText("Allumer");

    layoutGlobal->addWidget(allumer,2,0,Qt::AlignHCenter);

    this->setLayout(layoutGlobal);
}

void VueInformation::refresh(QWidget *s)
{
    this->setSource(s);
    this->routes->refresh();
    this->vueIP->refresh();
}

void VueInformation::setSource(QWidget *s)
{
    this->source = s;
}
QWidget* VueInformation::getSource()
{
    return this->source;
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
    return this->routes;
}

void VueInformation::setRoutes(VueRoutes *v)
{
    this->routes = v;
}

VueIP* VueInformation::getVueIP()
{
    return this->vueIP;
}

void VueInformation::setVueIP(VueIP *v)
{
    this->vueIP = v;
}
