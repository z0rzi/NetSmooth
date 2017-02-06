#include "Scene.h"

Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *e)
{
    QWidget* vp=VuePrincipale::getwidget();
    QWidget* vq=vp->parentWidget();
    QWidget *vFenetre = vq->parentWidget();

    QPointF mousePosition = e->scenePos();
    QGraphicsPixmapItem*  pItem = (QGraphicsPixmapItem *) itemAt(mousePosition.x(), mousePosition.y());

    if (pItem == NULL)
    {
        QGraphicsScene::mouseMoveEvent(e);
        return;
    }

    if (pItem->isSelected() == false)
    {
        QGraphicsScene::mouseMoveEvent(e);
        return;
    }


    if (e->buttons() == Qt::LeftButton)
    {
        int x = QCursor::pos().x()-vp->pos().x()-vq->pos().x()-vFenetre->pos().x();
        int y = QCursor::pos().y()-vp->pos().y()-vq->pos().y()-vFenetre->pos().y();
        //y-=this->height()/2+35;	/*35 = hauteur bandeau en haut fenetre*/
        //x-=this->width()/2;
   /* QList<QGraphicsPixmapItem *> items = (QList<QGraphicsPixmapItem *>) selectedItems();

        for (unsigned i=0; i<items.count(); i++)
            items[i]->setOffset(x,y);
    }*/
    }
    QGraphicsScene::mouseMoveEvent(e);
}

