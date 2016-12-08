#include "clicklabel.h"
#include "vueprincipale.h"

ClickLabel* ClickLabel::LabelEnSelection = NULL;

ClickLabel::ClickLabel(QLabel *parent) : QLabel(parent)
{

}

void ClickLabel::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        ClickLabel::setLabelEnSelection(this);
        QPalette* palette = new QPalette();
        palette->setColor(QPalette::Background,Qt::red);
        this->setPalette(*palette);
    }
}

void ClickLabel::mouseMoveEvent(QMouseEvent *e)
{
    VuePrincipale* parent = VuePrincipale::getwidget();
    int x = e->globalPos().x();
    int y = e->globalPos().y();
    cout << "x:" << parent->pos.x() << " ; y:" << parent->pos.y() << endl;

    if (e->buttons() == Qt::LeftButton)
    {
        int x = e->globalPos().x();
        int y = e->globalPos().y();
        this->move(*(VuePrincipale::getPosition()));
        //cout << "x:" << x << "y:" << y << endl;
    }

}

void ClickLabel::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->buttons() == Qt::LeftButton)
        this->move(e->globalPos());
    ClickLabel::setLabelEnSelection(NULL);
    QPalette* palette = new QPalette();
    palette->setColor(QPalette::Background,Qt::white);
    this->setPalette(*palette);
}

void ClickLabel::setLabelEnSelection(ClickLabel* label)
{
    ClickLabel::LabelEnSelection = label;
}

ClickLabel* ClickLabel::getLabelEnSelection()
{
    return LabelEnSelection;
}
