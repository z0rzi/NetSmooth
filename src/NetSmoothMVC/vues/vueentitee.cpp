#include "vueentitee.h"
#include "vueinformation.h"
#include "vueprincipale.h"

VueEntitee* VueEntitee::labelEnSelection = NULL;// A quoi LabelEnSelection sert? Vincent

VueEntitee::VueEntitee(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    this->setFlag(QGraphicsItem::ItemIsFocusable,true);
    this->setFlag(QGraphicsItem::ItemIsSelectable,true);
}

Entitee* VueEntitee::getModele(){
}

void VueEntitee::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    if(Selection::getEnSelection()==SUPPRIMER)
    {
        this->getModele()->~Entitee();
        this->deleteLater();
    }
    else if (e->button() == Qt::LeftButton)
    {
        if(VueEntitee::getLabelEnSelection()!=this)
        {
                VueEntitee::setLabelEnSelection(this);
                VueInformation::getInstanceOf()->refresh(this);
        }

        if(Selection::getEnSelection()==CABLE)
            VueCable::creerVueCable(this);
    }
    else if (e->button() == Qt::RightButton)
          emit rightClick();

    qDebug("pressItem");
    QGraphicsItem::mousePressEvent(e);
}

void VueEntitee::mouseMoveEvent(QGraphicsSceneMouseEvent *e)
{
    QGraphicsItem::mouseMoveEvent(e);
    QWidget* vp=VuePrincipale::getwidget();
    QWidget* vq=vp->parentWidget();
    QWidget *vFenetre = vq->parentWidget();

    if (e->buttons() == Qt::LeftButton)
    {
        QPoint viewPoint = VuePrincipale::getInstanceOf()->getView()->mapFromGlobal(QCursor::pos());
        QPointF scenePoint = VuePrincipale::getInstanceOf()->getView()->mapToScene(viewPoint);

        VuePrincipale::getInstanceOf()->deplacerEntitee(this,
                                                        new QPoint(trunc(scenePoint.x()),trunc(scenePoint.y())));

    }
}

void VueEntitee::setLabelEnSelection(VueEntitee* label)
{
    VueEntitee::labelEnSelection = label;
}

VueEntitee* VueEntitee::getLabelEnSelection()
{
    return VueEntitee::labelEnSelection;
}
