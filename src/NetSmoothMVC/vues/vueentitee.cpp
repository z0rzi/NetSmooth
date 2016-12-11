#include "vueentitee.h"
#include "vueprincipale.h"

VueEntitee* VueEntitee::LabelEnSelection = NULL;

VueEntitee::VueEntitee(QLabel *parent) : QLabel(parent)
{

}

void VueEntitee::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        VueEntitee::setLabelEnSelection(this);
        QPalette* palette = new QPalette();
        palette->setColor(QPalette::Background,Qt::red);
        this->setPalette(*palette);
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
        cout << "x:" << x << "y:" << y << endl;
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
    return LabelEnSelection;
}
