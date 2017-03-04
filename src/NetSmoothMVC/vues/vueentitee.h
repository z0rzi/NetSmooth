#ifndef VUEENTITEE_H
#define VUEENTITEE_H

#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QCoreApplication>
#include <math.h>
#include "modeles/Machine.h"
#include "modeles/Bridge.h"
#include "modeles/Cable.h"
#include "modeles/Constantes.h"
#include "modeles/DataBase.h"
#include "modeles/Hub.h"
#include "modeles/Ordinateur.h"
#include "modeles/Passerelle.h"
#include "modeles/Entitee.h"
#include "vues/vuecable.h"
#include <lxc/lxccontainer.h>


class VueEntitee : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    ~VueEntitee();
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
    explicit VueEntitee(QGraphicsItem *parent = 0);
    explicit VueEntitee(int x, int y, QGraphicsItem *parent = 0);
    bool etat;

    virtual Entitee* getModele();
    static VueEntitee* getLabelEnSelection();

    int getLigneGrille();
    void setLigneGrille(int l);
    int getColGrille();
    void setColGrille(int c);
    void detruire();

    static void setLabelEnSelection(VueEntitee* label);
    void moveOnCursor();



private:
    static VueEntitee* labelEnSelection;
    int colonne;
    int ligne;
    bool isDeleted;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *e) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *e) override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* e) override;

signals:
    void rightClick();
    void doubleClick();
    void moveLeftButton();
};

#endif // VUEENTITEE_H
