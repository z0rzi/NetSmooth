#include "vueprincipale.h"

QWidget* VuePrincipale::ca = NULL;

VuePrincipale::VuePrincipale(QWidget *parent) : QWidget(parent)
{
    setFixedSize(800,600);

    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene,this);
    vpc = new VuePrincipaleControleur(this);

    scene->setSceneRect(0,0,750,550);
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
