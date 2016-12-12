#include "vueprincipalecontroleur.h"

VuePrincipaleControleur::VuePrincipaleControleur(VuePrincipale *vue0,QObject *parent) : QObject(parent)
{
    vue = vue0;

    connect(vue,SIGNAL(clickSouris(QPoint)),this,SLOT(paintMachine(QPoint)));
}

void VuePrincipaleControleur::paintMachine(QPoint pos)
{
    if(Selection::getEnSelection() == MACHINE)
    {
        VueMachine* e = new VueMachine();
        VueMachineControleur* c = new VueMachineControleur(e);
        e->setGeometry(pos.x(),pos.y(),130,100);
        QGraphicsProxyWidget* proxy = vue->scene->addWidget(e);
    }
    if(Selection::getEnSelection() == PASSERELLE)
    {
        VuePasserelle* e = new VuePasserelle();
        VuePasserelleControleur* c = new VuePasserelleControleur(e);
        e->setGeometry(pos.x(),pos.y(),130,100);
        QGraphicsProxyWidget* proxy = vue->scene->addWidget(e);
    }
    if(Selection::getEnSelection() == HUB)
    {
        VueHub* e = new VueHub();
        VueHubControleur* c = new VueHubControleur(e);
        e->setGeometry(pos.x(),pos.y(),130,130);
        QGraphicsProxyWidget* proxy = vue->scene->addWidget(e);
    }

    vue->view->setScene(vue->scene);
    vue->view->show();

    Selection::setEnSelection(SOURIS);
}
