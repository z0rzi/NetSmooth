#ifndef VUEENTITEE_H
#define VUEENTITEE_H

#include <QObject>
#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include "modeles/Machine.h"
#include "modeles/Bridge.h"
#include "modeles/Cable.h"
#include "modeles/Constantes.h"
#include "modeles/DataBase.h"
#include "modeles/Hub.h"
#include "modeles/Ordinateur.h"
#include "modeles/Passerelle.h"
#include "modeles/Entitee.h"
#include <lxc/lxccontainer.h>

class VueEntitee : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit VueEntitee(QGraphicsItem *parent = 0);
    bool etat;

    virtual Entitee* getModele();

    static VueEntitee* getLabelEnSelection();
    static void setLabelEnSelection(VueEntitee* label);

private:
    static VueEntitee* labelEnSelection;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *e) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *e) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *e) override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *e) override;

signals:
    void rightClick();
    void doubleClick();
};

#endif // VUEENTITEE_H
