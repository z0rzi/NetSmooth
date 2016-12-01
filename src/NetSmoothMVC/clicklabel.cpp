#include "clicklabel.h"

ClickLabel::ClickLabel(QLabel *parent) : QLabel(parent)
{

}

void ClickLabel::mouseDoubleClickEvent(QMouseEvent *e)
{
    if (e->buttons() == Qt::LeftButton)
    {
        emit doubleClick();
    }
}
