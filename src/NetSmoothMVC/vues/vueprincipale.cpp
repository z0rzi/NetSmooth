#include "vueprincipale.h"

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

}

void VuePrincipale::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        this->pos = QWidget::mapFromGlobal(QCursor::pos());
        //cout << "x:" << pos.x() << endl << "y:" << pos.y() << endl << endl;
        emit clickSouris(pos);
    }
}
