#include "vueprincipale.h"

QWidget* VuePrincipale::ca = NULL;

VuePrincipale::VuePrincipale(QWidget *parent) : QWidget(parent)
{
    setFixedSize(800,600);

    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene,this);
    vpc = new VuePrincipaleControleur(this);

    scene->setSceneRect(0,0,1500,1000);
    scene->setBackgroundBrush(Qt::white);

    view->setGeometry(0,0,750,550);
    view->show();
    ca=this;
}

void VuePrincipale::mousePressEvent(QMouseEvent *e)
{
    if(Selection::getEnSelection()==CABLE){
        Selection::setEnSelection(SOURIS);
        VueCable::setPremiereSelection(NULL);
        VueCable::setSecondeSelection(NULL);
    }

}

void VuePrincipale::mouseDoubleClickEvent(QMouseEvent *e)
{
    if (e->buttons() == Qt::LeftButton)
    {
        this->pos = QWidget::mapFromGlobal(QCursor::pos());
        emit clickSouris(pos);
    }
}

QWidget* VuePrincipale::getwidget()
{
    return ca;
}

void VuePrincipale::paintEntitee(QPoint posSouris)
{
    if(Selection::getEnSelection() == MACHINE)
    {
        VueMachine* e = new VueMachine();
        cout << e->getModele()->getContainer() << endl;
        VueMachineControleur* c = new VueMachineControleur(e);
        e->setGeometry(posSouris.x(),posSouris.y(),130,130);
        QGraphicsProxyWidget* proxy = this->scene->addWidget(e);
    }
    if(Selection::getEnSelection() == PASSERELLE)
    {
        VuePasserelle* e = new VuePasserelle();
        VuePasserelleControleur* c = new VuePasserelleControleur(e);
        e->setGeometry(posSouris.x(),posSouris.y(),130,130);
        QGraphicsProxyWidget* proxy = this->scene->addWidget(e);
    }
    if(Selection::getEnSelection() == HUB)
    {
        VueHub* e = new VueHub();
        VueHubControleur* c = new VueHubControleur(e);
        e->setGeometry(posSouris.x(),posSouris.y(),130,130);
        QGraphicsProxyWidget* proxy = this->scene->addWidget(e);
    }

    this->view->setScene(this->scene);
    this->view->show();

    Selection::setEnSelection(SOURIS);
}
