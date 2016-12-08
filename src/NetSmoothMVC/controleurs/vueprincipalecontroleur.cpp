#include "vueprincipalecontroleur.h"

VuePrincipaleControleur::VuePrincipaleControleur(VuePrincipale *vue0,QObject *parent) : QObject(parent)
{
    vue = vue0;

    connect(vue,SIGNAL(clickSouris(QPoint)),this,SLOT(paintMachine(QPoint)));
}

void VuePrincipaleControleur::paintMachine(QPoint pos)
{
    if(Selection::getEnSelection() == 1)
    {
        VueMachine* e = new VueMachine();
        VueMachineControleur* c = new VueMachineControleur(e);
        e->zoneImg->setGeometry(pos.x(),pos.y(),130,100);
        QGraphicsProxyWidget* proxy = vue->scene->addWidget(e->zoneImg);
    }
    if(Selection::getEnSelection() == 2)
    {
        VuePasserelle* e = new VuePasserelle();
        VuePasserelleControleur* c = new VuePasserelleControleur(e);
        e->zoneImg->setGeometry(pos.x(),pos.y(),130,100);
        QGraphicsProxyWidget* proxy = vue->scene->addWidget(e->zoneImg);
    }
    if(Selection::getEnSelection() == 4)
    {
        VueHub* e = new VueHub();
        VueHubControleur* c = new VueHubControleur(e);
        e->zoneImg->setGeometry(pos.x(),pos.y(),130,100);
        QGraphicsProxyWidget* proxy = vue->scene->addWidget(e->zoneImg);
    }

    vue->view->setScene(vue->scene);
    vue->view->show();

    Selection::setEnSelection(SOURIS);
}
