#include "vueentitee.h"
#include "vueinformation.h"
#include "vueprincipale.h"

VueEntitee* VueEntitee::labelEnSelection = NULL;// A quoi LabelEnSelection sert? Vincent

VueEntitee::VueEntitee(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    /**********TRANSPARENCE****************/
    //this->setAttribute( Qt::WA_TranslucentBackground);
    //this->setWindowFlags (Qt::FramelessWindowHint);
    //this->setAutoFillBackground(false);
    /*************************************/

}

Entitee* VueEntitee::getModele(){
}

void VueEntitee::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        if(VueEntitee::getLabelEnSelection()!=this)
        {
                VueEntitee::setLabelEnSelection(this);
                VueInformation::getInstanceOf()->refresh(this);
        }

        if(Selection::getEnSelection()==CABLE)
            VueCable::creerVueCable(this);
    }
    if (e->button() == Qt::RightButton)
          emit rightClick();

    qDebug("pressItem");
    QGraphicsItem::mousePressEvent(e);
}

void VueEntitee::mouseMoveEvent(QGraphicsSceneMouseEvent *e)
{
    QWidget* vp=VuePrincipale::getwidget();
    QWidget* vq=vp->parentWidget();
    QWidget *vFenetre = vq->parentWidget();

    if (e->buttons() == Qt::LeftButton)
    {
        int x = QCursor::pos().x()-vp->pos().x()-vq->pos().x()-vFenetre->pos().x();
        int y = QCursor::pos().y()-vp->pos().y()-vq->pos().y()-vFenetre->pos().y();
        //y-=this->height()/2+35;	/*35 = hauteur bandeau en haut fenetre*/
        //x-=this->width()/2;
        VuePrincipale::getInstanceOf()->deplacerEntitee(this,new QPoint(x,y));
    }
    qDebug("moveItem");
    QGraphicsItem::mouseMoveEvent(e);
}

void VueEntitee::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *e)
{
    emit doubleClick();
}

void VueEntitee::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{
   // if (e->buttons() == Qt::LeftButton)
     //   this->setOffset(e->globalPos());
  //  QPalette* palette = new QPalette();
   // palette->setColor(QPalette::Background,Qt::white);
    //this->setPalette(*palette);
}

void VueEntitee::setLabelEnSelection(VueEntitee* label)
{
    VueEntitee::labelEnSelection = label;
}

VueEntitee* VueEntitee::getLabelEnSelection()
{
    return VueEntitee::labelEnSelection;
}
