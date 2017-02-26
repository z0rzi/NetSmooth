#ifndef VUECABLE_H
#define VUECABLE_H

#include <iostream>
#include <QWidget>
#include <QGraphicsPathItem>
#include <QGraphicsView>
#include "modeles/Cable.h"
#include "vues/vueentitee.h"

using namespace std;

class VueCable : public QObject, QGraphicsPathItem
{
    Q_OBJECT
public:
    explicit VueCable(VueEntitee* v1, VueEntitee* v2, QGraphicsItem *parent = 0);
    Cable* getModele(void);

//void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    static void creerVueCable(VueEntitee *v);
    static VueEntitee* getPremiereSelection();
    static VueEntitee* getSecondeSelection();
    static void setPremiereSelection(VueEntitee* v);
    static void setSecondeSelection(VueEntitee* v);
    void mousePressEvent(QGraphicsSceneMouseEvent *e);
    void updatePath();

private:
    VueEntitee *m_v1 = NULL;
    VueEntitee *m_v2 = NULL;
    Cable* cable = NULL;
    bool isSeq(int xinit, int yinit, double coef, int x1, int y1, int x2, int y2);
    static VueEntitee* PremiereSelection;//Pour créer cables
    static VueEntitee* SecondeSelection;//Pour créer cables

};

#endif // VUECABLE_H
