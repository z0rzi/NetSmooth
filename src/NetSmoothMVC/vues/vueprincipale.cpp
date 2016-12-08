#include "vueprincipale.h"

VuePrincipale* VuePrincipale::ca = NULL;

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

    ca = this;
}

void VuePrincipale::mouseDoubleClickEvent(QMouseEvent *e)
{
    if (e->buttons() == Qt::LeftButton)
    {
        this->pos = QWidget::mapFromGlobal(QCursor::pos());
        //cout << "x:" << pos.x() << endl << "y:" << pos.y() << endl << endl;
        emit clickSouris(pos);
    }
}

VuePrincipale* VuePrincipale::getwidget()
{
    return ca;
}

QPoint* VuePrincipale::getPosition()
{
    return new QPoint(QWidget::mapToGlobal(getwidget()->pos).x(), QWidget::mapToGlobal(ca->pos).y());
}
