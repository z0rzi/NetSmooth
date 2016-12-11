#include "vuecable.h"
#include "modeles/DataBase.h"
#include <qpainter.h>

VueCable::VueCable(QWidget *parent) : QWidget(parent)
{
  //this->cable = NULL;//à faire

}

void VueCable::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    QPen myPen(Qt::black, 2, Qt::SolidLine);
    painter.setPen(myPen);
    painter.drawLine(100,100,100,1);

}

/*Cable* VueCable::getCable()
{
  return this->cable;
}
*/
