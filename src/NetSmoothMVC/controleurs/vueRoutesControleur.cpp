#include "vueRoutesControleur.h"

VueRoutesControleur::VueRoutesControleur(VueRoutes* vue0, QObject *parent) : QObject(parent)
{
    vue = vue0;
}

void VueRoutesControleur::deleteRoute4()
{
    QPushButton* b = qobject_cast<QPushButton*>(sender());
    LigneRoute* parent = (LigneRoute*)b->parentWidget();

    if(this->vue->getSource()->getType()!=TYPE_HUB)
    {
        Machine* m = (Machine*)this->vue->getSource();
        std::cout << "id : " << parent->getId() << std::endl;
        m->removeParamRoute4(parent->getId());
    }

    vue->refresh();
}

void VueRoutesControleur::addRoute4()
{
    std::cout << "addRoute" << std::endl;
    QPushButton* b = qobject_cast<QPushButton*>(sender());
    LigneRoute* parent = (LigneRoute*)b->parentWidget();

    if(this->vue->getSource()->getType()!=TYPE_HUB)
    {
        Machine* m = (Machine*)this->vue->getSource();
        struct paramRoutage route = {m->getNewIdRoute4(),
                            parent->getEinter()->toPlainText().toStdString(),
                            parent->getEdest()->toPlainText().toStdString(),
                            parent->getEpass()->toPlainText().toStdString()};

        m->addRouteConfig4(route);
        m->appliquerParamRoutage4();
    }
    vue->refresh();
}

void VueRoutesControleur::deleteRoute6()
{
    QPushButton* b = qobject_cast<QPushButton*>(sender());
    LigneRoute* parent = (LigneRoute*)b->parentWidget();

    if(this->vue->getSource()->getType()!=TYPE_HUB)
    {
        Machine* m = (Machine*)this->vue->getSource();
        m->removeParamRoute6(parent->getId());
    }

    vue->refresh();
}

void VueRoutesControleur::addRoute6()
{
    QPushButton* b = qobject_cast<QPushButton*>(sender());
    LigneRoute* parent = (LigneRoute*)b->parentWidget();

    if(this->vue->getSource()->getType()!=TYPE_HUB)
    {
        Machine* m = (Machine*)this->vue->getSource();
        struct paramRoutage route = {m->getNewIdRoute4(),
                            parent->getEinter()->toPlainText().toStdString(),
                            parent->getEdest()->toPlainText().toStdString(),
                            parent->getEpass()->toPlainText().toStdString()};

        m->addRouteConfig6(route);
        m->appliquerParamRoutage6();
    }
    vue->refresh();
}


