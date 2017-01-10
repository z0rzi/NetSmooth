#include "vueRoutesControleur.h"

VueRoutesControleur::VueRoutesControleur(VueRoutes* vue0, QObject *parent) : QObject(parent)
{
    vue = vue0;
}

void VueRoutesControleur::deleteRoute4()
{
    QPushButton* b = qobject_cast<QPushButton*>(sender());
    LigneRoute* parent = (LigneRoute*)b->parentWidget();

    if(VueEntitee::getLabelEnSelection()->getModele()->getType()!=TYPE_HUB)
    {
        Machine* m = (Machine*)VueEntitee::getLabelEnSelection()->getModele();
        std::cout << "id : " << parent->getId() << std::endl;
        m->removeParamRoute4(parent->getId());
    }

    vue->refresh();
}

void VueRoutesControleur::addRoute4()
{
<<<<<<< HEAD
    if (this->vue->getSource() != NULL)
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
=======
    std::cout << "addRoute" << std::endl;
    QPushButton* b = qobject_cast<QPushButton*>(sender());
    LigneRoute* parent = (LigneRoute*)b->parentWidget();

    if(VueEntitee::getLabelEnSelection()->getModele()->getType()!=TYPE_HUB)
    {
        Machine* m = (Machine*)VueEntitee::getLabelEnSelection()->getModele();
        struct paramRoutage route = {m->getNewIdRoute4(),
                            parent->getEinter()->toPlainText().toStdString(),
                            parent->getEdest()->toPlainText().toStdString(),
                            parent->getEpass()->toPlainText().toStdString()};
>>>>>>> df2f011b1137d51d8e73679b86788c724bcb54d6

            m->addRouteConfig4(route);
            m->appliquerParamRoutage4();
        }
        vue->refresh();
    }
}

void VueRoutesControleur::deleteRoute6()
{
    QPushButton* b = qobject_cast<QPushButton*>(sender());
    LigneRoute* parent = (LigneRoute*)b->parentWidget();

    if(VueEntitee::getLabelEnSelection()->getModele()->getType()!=TYPE_HUB)
    {
        Machine* m = (Machine*)VueEntitee::getLabelEnSelection()->getModele();
        m->removeParamRoute6(parent->getId());
    }

    vue->refresh();
}

void VueRoutesControleur::addRoute6()
{
<<<<<<< HEAD
    if (this->vue->getSource() != NULL)
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
=======
    QPushButton* b = qobject_cast<QPushButton*>(sender());
    LigneRoute* parent = (LigneRoute*)b->parentWidget();

    if(VueEntitee::getLabelEnSelection()->getModele()->getType()!=TYPE_HUB)
    {
        Machine* m = (Machine*)VueEntitee::getLabelEnSelection()->getModele();
        struct paramRoutage route = {m->getNewIdRoute4(),
                            parent->getEinter()->toPlainText().toStdString(),
                            parent->getEdest()->toPlainText().toStdString(),
                            parent->getEpass()->toPlainText().toStdString()};
>>>>>>> df2f011b1137d51d8e73679b86788c724bcb54d6

            m->addRouteConfig6(route);
            m->appliquerParamRoutage6();
        }
        vue->refresh();
    }
}


