#ifndef MA_GRAPHICS_VIEW
#define MA_GRAPHICS_VIEW

#include <QMouseEvent>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPointF>
#include <QGraphicsItem>
#include <QObject>
#include <QWidget>
#include <lxc/lxccontainer.h>

class MaGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MaGraphicsView(QGraphicsScene* q,QWidget *parent = 0);

protected:
    void mouseMoveEvent(QMouseEvent *e) override;
    void mousePressEvent(QMouseEvent *e) override;

private:
};

#endif

