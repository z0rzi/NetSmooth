#include "vues/MaGraphicsView.h"

MaGraphicsView::MaGraphicsView(QGraphicsScene* q,QWidget *parent) : QGraphicsView(q,parent)
{
}

void MaGraphicsView::mousePressEvent(QMouseEvent *e)
{
    qDebug("pressView");
    QGraphicsView::mousePressEvent(e);
}

void MaGraphicsView::mouseMoveEvent(QMouseEvent *e)
{
    qDebug("moveView");
    QGraphicsView::mouseMoveEvent(e);
}

