#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QPointF>
#include <QGraphicsItem>
#include <QObject>
#include <QWidget>
#include <lxc/lxccontainer.h>
#include <vues/vueprincipale.h>

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = 0);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *e);

private:
};

#endif // VUEENTITEE_H

