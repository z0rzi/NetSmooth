#include "vueprincipale.h"

QWidget* VuePrincipale::ca = NULL;

VuePrincipale::VuePrincipale(QWidget *parent) : QWidget(parent)
{
    this->setMinimumSize(600,600);
    this->setMaximumSize(800,800);

    this->m_scene = new QGraphicsScene(this);
    this->m_view = new QGraphicsView(m_scene,this);
    this->m_vpc = new VuePrincipaleControleur(this);

    this->m_scene->setSceneRect(0,0,2000,2000);
    this->m_scene->setBackgroundBrush(Qt::white);

    this->m_view->show();
    this->ca=this;
}

void VuePrincipale::mousePressEvent(QMouseEvent *e)
{
    if(Selection::getEnSelection()==CABLE){
        Selection::setEnSelection(SOURIS);
        VueCable::setPremiereSelection(NULL);
        VueCable::setSecondeSelection(NULL);
    }
    if (e->buttons() == Qt::LeftButton)
    {
        this->m_pos = QWidget::mapFromGlobal(QCursor::pos());
        emit clickSouris(m_pos);
    }

}

void VuePrincipale::mouseDoubleClickEvent(QMouseEvent *e)
{
}

QWidget* VuePrincipale::getwidget()
{
    return ca;
}

void VuePrincipale::paintEntitee(QPoint m_posSouris)
{
    if(Selection::getEnSelection() == MACHINE)
    {
        VueMachine* e = new VueMachine();
        VueMachineControleur* c = new VueMachineControleur(e);
        e->setGeometry(m_posSouris.x(),m_posSouris.y(),130,130);
        QGraphicsProxyWidget* proxy = this->m_scene->addWidget(e);
    }
    if(Selection::getEnSelection() == PASSERELLE)
    {
        VuePasserelle* e = new VuePasserelle();
        VuePasserelleControleur* c = new VuePasserelleControleur(e);
        e->setGeometry(m_posSouris.x(),m_posSouris.y(),130,130);
        QGraphicsProxyWidget* proxy = this->m_scene->addWidget(e);
    }
    if(Selection::getEnSelection() == HUB)
    {
        VueHub* e = new VueHub();
        VueHubControleur* c = new VueHubControleur(e);
        e->setGeometry(m_posSouris.x(),m_posSouris.y(),130,130);
        QGraphicsProxyWidget* proxy = this->m_scene->addWidget(e);
    }

    this->m_view->setScene(this->m_scene);
    this->m_view->show();

    Selection::setEnSelection(SOURIS);
}

QGraphicsScene* VuePrincipale::getScene()
{

    return this->m_scene;
}

QGraphicsView* VuePrincipale::getView()
{
    return this->m_view;
}
