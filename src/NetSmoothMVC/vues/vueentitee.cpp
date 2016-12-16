#include "vueentitee.h"
#include "vueinformation.h"
#include "vueprincipale.h"

VueEntitee* VueEntitee::LabelEnSelection = NULL;// A quoi LabelEnSelection sert? Vincent

VueEntitee::VueEntitee(QLabel *parent) : QLabel(parent)
{
    /**********TRANSPARENCE****************/
    this->setAttribute( Qt::WA_TranslucentBackground);
    this->setWindowFlags (Qt::FramelessWindowHint);
    this->setAutoFillBackground(false);
    /*************************************/

}

Entitee* VueEntitee::getModele(){

}

void VueEntitee::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        VueEntitee::setLabelEnSelection(this);

        VueInformation::getInstanceOf()->refresh(this);

        QPalette* palette = new QPalette();
        palette->setColor(QPalette::Background,Qt::red);
        this->setPalette(*palette);
        if(Selection::getEnSelection()==CABLE)
        {
            VueCable::creerVueCable(this);
        }
    }
    if (e->button() == Qt::RightButton)
      {
          emit rightClick();
      }
}

void VueEntitee::mouseMoveEvent(QMouseEvent *e)
{
    QWidget* vp=VuePrincipale::getwidget();
    QWidget* vq=vp->parentWidget();

    if (e->buttons() == Qt::LeftButton)
    {
        int x = e->globalPos().x()-vp->pos().x()-vq->pos().x();
        int y = e->globalPos().y()-vp->pos().y()-vq->pos().y();
        y-=this->height()/2+35;	/*35 = hauteur bandeau en haut fenetre*/
        x-=this->width()/2;
        this->move(x, y);
    }
}
void VueEntitee::mouseDoubleClickEvent(QMouseEvent *e)
{
    emit doubleClick();
}

void VueEntitee::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->buttons() == Qt::LeftButton)
        this->move(e->globalPos());
    VueEntitee::setLabelEnSelection(NULL);
    QPalette* palette = new QPalette();
    palette->setColor(QPalette::Background,Qt::white);
    this->setPalette(*palette);
}

void VueEntitee::setLabelEnSelection(VueEntitee* label)
{
    VueEntitee::LabelEnSelection = label;
}

VueEntitee* VueEntitee::getLabelEnSelection()
{
    return VueEntitee::LabelEnSelection;
}