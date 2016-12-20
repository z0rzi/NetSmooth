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
    QLabel* ParamRoute = new QLabel("Paramètres routage : ");
    QLabel* v4 = new QLabel("V4 :");
    QLabel* dest4 = new QLabel("destination");
    QLabel* pass4 = new QLabel("passerelle");
    QLabel* inter4 = new QLabel("interface");

    LigneRoute* newLine = new LigneRoute();
    QGridLayout* l = (QGridLayout*)this->routesVersion4->layout();
    l->addWidget(newLine,0,0);

    this->controleur->connect(newLine->getValider(),SIGNAL(clicked(bool)),this->controleur,SLOT(addRoute4()));

    this->addWidget(v4,0,0);
    this->addWidget(dest4,1,0);
    this->addWidget(pass4,1,1);
    this->addWidget(inter4,1,2);

    this->addWidget(this->routesVersion4,2,0,1,4);
}

void VueRoutes::refresh()
{
    this->deleteRoutes();
    this->addRoutes();
}

void VueRoutes::deleteRoutes()
{
    QLayoutItem * child;
    QGridLayout* l = (QGridLayout*)this->routesVersion4->layout();
    int a;
    while((child = l->takeAt(0)) != 0)
    {
        std::cout <<" deleteRoutes" << std::endl;
        child->widget()->deleteLater();
        delete child;
    }
}

void VueRoutes::addRoutes()
{
    if(this->m_source->getType()==TYPE_HUB)
    {

    }
    else
    {
    QGridLayout* l = (QGridLayout*)this->routesVersion4->layout();
        int numLine;
        LigneRoute* newLine;
        Machine* m = (Machine*)this->m_source;
        std::vector<struct paramRoutage> routeConf = m->getRouteConfig4();
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


    }
}
void VueRoutes::setSource(Entitee* e)
{
    this->m_source = e;
}

Entitee* VueRoutes::getSource()
{
    return this->m_source;
}

bool VueRoutes::isRouteVersion4(struct paramRoutage* p)
{
    if(p->passerelle.find('.') != std::string::npos)
        return true;
    return false;
}
