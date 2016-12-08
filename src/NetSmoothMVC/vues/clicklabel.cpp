#include "clicklabel.h"

ClickLabel* ClickLabel::LabelEnSelection = NULL;

ClickLabel::ClickLabel(QLabel *parent) : QLabel(parent)
{
    this->setMouseTracking(true);
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
    if (e->buttons() == Qt::LeftButton)
    {
        this->move(e->pos());
        int x = e->pos().x();
        int y = e->pos().y();
        cout << "x:" << e->pos().x() << "y:" << e->pos().y() << endl;
    }

}

void ClickLabel::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->buttons() == Qt::LeftButton)
        this->move(QWidget::mapFromGlobal(QCursor::pos()));
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
