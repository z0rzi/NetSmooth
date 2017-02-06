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

    this->setBaseSize(400,500);
    this->setMaximumWidth(500);


    QGridLayout* layoutGlobal = new QGridLayout();

    this->m_routes = new VueRoutes();

    this->m_vueIP = new VueIP();

    layoutGlobal->addWidget(this->m_vueIP,0,0);
    layoutGlobal->addLayout(m_routes,1,0);

    this->m_allumer = new QPushButton();
    m_allumer->setText("Allumer");


    layoutGlobal->addWidget(m_allumer,2,0,Qt::AlignHCenter);

    this->setLayout(layoutGlobal);
}

void VueInformation::refresh(QGraphicsPixmapItem *s)
{
    this->setSource(s);
    this->m_routes->refresh();
    this->m_vueIP->refresh();
}

void VueInformation::allumer()
{
    QPixmap* img = new QPixmap();
    VueEntitee* vueE = VueEntitee::getLabelEnSelection();
    if (vueE == NULL)
    {
        cout << "erreur selection" << endl;
        return;
    }
    if(vueE->getModele()->getType()==TYPE_ORDINATEUR)
    {
        if (vueE->etat == false)
        {
            vueE->etat = true;

            //TODO ajouter les nouvelles ip rentrées

            vueE->getModele()->launchEntitee();
            img->load("../build-NetSmoothMVC-Desktop-Debug/images/ordinateuron.png");
            *img = img->scaled(130,130);
            vueE->setPixmap(*img);
        }
        else
        {
            vueE->etat = false;
            vueE->getModele()->stopEntitee();
            img->load("../build-NetSmoothMVC-Desktop-Debug/images/ordinateuroff.png");
            *img = img->scaled(130,130);
            vueE->setPixmap(*img);
        }
    }
    else if(vueE->getModele()->getType()==TYPE_PASSERELLE)
    {
        if (vueE->etat == false)
        {
            vueE->etat = true;

            //TODO ajouter les nouvelles ip rentrées

            vueE->getModele()->launchEntitee();
            img->load("../build-NetSmoothMVC-Desktop-Debug/images/passerelleon.png");
            *img = img->scaled(130,130);
            vueE->setPixmap(*img);
        }
        else
        {
            vueE->etat = false;
            vueE->getModele()->stopEntitee();
            img->load("../build-NetSmoothMVC-Desktop-Debug/images/passerelleoff.png");
            *img = img->scaled(130,130);
            vueE->setPixmap(*img);
        }
    }
    else if(vueE->getModele()->getType()==TYPE_HUB)
    {
        if (vueE->etat == false)
        {
            vueE->etat = true;
            Hub* p = (Hub*)vueE->getModele();
            vueE->getModele()->launchEntitee();
            img->load("../build-NetSmoothMVC-Desktop-Debug/images/Hubon.png");
            *img = img->scaled(130,130);
            vueE->setPixmap(*img);
        }
        else
        {
            vueE->etat = false;
            vueE->getModele()->stopEntitee();
            img->load("../build-NetSmoothMVC-Desktop-Debug/images/Huboff.png");
            *img = img->scaled(130,130);
            vueE->setPixmap(*img);
        }
    }
}

void VueInformation::setSource(QGraphicsPixmapItem *s)
{
    this->m_source = s;
}
QGraphicsPixmapItem* VueInformation::getSource()
{
    return this->m_source;
}

void VueInformation::setAllumer(QPushButton * p)
{
    this->m_allumer = p;
}

QPushButton* VueInformation::getAllumer()
{
    return this->m_allumer;
}

VueRoutes* VueInformation::getRoutes()
{
    return this->m_routes;
}

void VueInformation::setRoutes(VueRoutes *v)
{
    this->m_routes = v;
}

VueIP* VueInformation::getVueIP()
{
    return this->m_vueIP;
}

void VueInformation::setVueIP(VueIP *v)
{
    this->m_vueIP = v;
}
