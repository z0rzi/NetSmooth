#include "vueRoutes.h"

VueRoutes::VueRoutes(QWidget *parent) :
    QGridLayout(parent)
{
    this->m_source = NULL;
    this->routesVersion4 = new QWidget();
    this->routesVersion6 = new QWidget();

    this->routesVersion4->setLayout(new QGridLayout());
    this->routesVersion6->setLayout(new QGridLayout());

    this->controleur = new VueRoutesControleur(this);

    QLabel* paramRoute = new QLabel("Paramètres routage : ");

    /*** ROUTES VERSION 4 ***/
    QLabel* v4 = new QLabel("V4 :");
    QLabel* dest4 = new QLabel("destination");
    QLabel* pass4 = new QLabel("passerelle");
    QLabel* inter4 = new QLabel("interface");

    LigneRoute* newLine = new LigneRoute();
    QGridLayout* l = (QGridLayout*)this->routesVersion4->layout();
    l->addWidget(newLine,0,0);

    this->controleur->connect(newLine->getValider(),SIGNAL(clicked(bool)),this->controleur,SLOT(addRoute4()));

    this->addWidget(paramRoute,0,0); //!\\ mettre dans vue information pour centrer
    this->addWidget(v4,1,0);
    this->addWidget(dest4,2,0);
    this->addWidget(pass4,2,1);
    this->addWidget(inter4,2,2);

    this->addWidget(this->routesVersion4,3,0,1,4);

    /*** ROUTES VERSION 6 ***/
    QLabel* v6 = new QLabel("V6 :");
    QLabel* dest6 = new QLabel("destination");
    QLabel* pass6 = new QLabel("passerelle");
    QLabel* inter6 = new QLabel("interface");

    newLine = new LigneRoute();
    l = (QGridLayout*)this->routesVersion6->layout();
    l->addWidget(newLine,0,0);

    this->controleur->connect(newLine->getValider(),SIGNAL(clicked(bool)),this->controleur,SLOT(addRoute6()));

    this->addWidget(v6,4,0);
    this->addWidget(dest6,5,0);
    this->addWidget(pass6,5,1);
    this->addWidget(inter6,5,2);

    this->addWidget(this->routesVersion6,6,0,1,4);
}

void VueRoutes::refresh()
{
    this->deleteRoutes();
    this->addRoutes();
}


//delete view of routes version 4 and 6
void VueRoutes::deleteRoutes()
{
    /*** ROUTE VERSION 4 ***/
    QLayoutItem * child;
    QGridLayout* l = (QGridLayout*)this->routesVersion4->layout();
    while((child = l->takeAt(0)) != 0)
    {
        std::cout <<" deleteRoutes" << std::endl;
        child->widget()->deleteLater();
        delete child;
    }

    /*** ROUTE VERSION 6 ***/
    l = (QGridLayout*)this->routesVersion6->layout();
    while((child = l->takeAt(0)) != 0)
    {
        std::cout <<" deleteRoutes" << std::endl;
        child->widget()->deleteLater();
        delete child;
    }
}


//add view of routes version 4 and 6
void VueRoutes::addRoutes()
{
    if(VueEntitee::getLabelEnSelection()->getModele()->getType() == TYPE_HUB)
    {

    }
    else
    {
        QGridLayout* l = NULL;
        int numLine = 0;
        std::vector<struct paramRoutage> routeConf;
        LigneRoute* newLine;
        Machine* m = (Machine*)VueEntitee::getLabelEnSelection()->getModele();

        /*** ROUTE VERSION 4 ***/
        routeConf = m->getRouteConfig4();
        l = (QGridLayout*)this->routesVersion4->layout();

        for(numLine=0;numLine<routeConf.size();numLine++)
        {
            newLine = new LigneRoute();
            const char* interface = routeConf[numLine].interface.c_str();
            const char* destination = routeConf[numLine].destination.c_str();
            const char* passerelle = routeConf[numLine].passerelle.c_str();
            newLine->getEdest()->setText(destination);
            newLine->getEpass()->setText(passerelle);
            newLine->getEinter()->setText(interface);
            newLine->setId(routeConf[numLine].id);
            newLine->bloquer();

            l->addWidget(newLine,numLine,0);
            this->controleur->connect(newLine->getValider(),SIGNAL(clicked(bool)),this->controleur,SLOT(deleteRoute4()));
        }

        newLine = new LigneRoute();
        l->addWidget(newLine,numLine,0);
        this->controleur->connect(newLine->getValider(),SIGNAL(clicked(bool)),this->controleur,SLOT(addRoute4()));


        /*** ROUTE VERSION 6 ***/
        routeConf = m->getRouteConfig6();
        l = (QGridLayout*)this->routesVersion6->layout();

        for(numLine=0;numLine<routeConf.size();numLine++)
        {
            newLine = new LigneRoute();
            const char* interface = routeConf[numLine].interface.c_str();
            const char* destination = routeConf[numLine].destination.c_str();
            const char* passerelle = routeConf[numLine].passerelle.c_str();
            newLine->getEdest()->setText(destination);
            newLine->getEpass()->setText(passerelle);
            newLine->getEinter()->setText(interface);
            newLine->setId(routeConf[numLine].id);
            newLine->bloquer();

            l->addWidget(newLine,numLine,0);
            this->controleur->connect(newLine->getValider(),SIGNAL(clicked(bool)),this->controleur,SLOT(deleteRoute6()));
        }

        newLine = new LigneRoute();
        l->addWidget(newLine,numLine,0);
        this->controleur->connect(newLine->getValider(),SIGNAL(clicked(bool)),this->controleur,SLOT(addRoute6()));

    }
}
/*void VueRoutes::setSource(Entitee* e)
{
    this->m_source = e;
}

Entitee* VueRoutes::getSource()
{
    return this->m_source;
}
*/
