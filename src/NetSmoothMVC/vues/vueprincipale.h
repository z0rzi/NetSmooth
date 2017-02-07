#ifndef VUEPRINCIPALE_H
#define VUEPRINCIPALE_H

#include <QMainWindow>
#include <QGridLayout>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QPen>
#include <iostream>
#include <QMouseEvent>
#include <QKeyEvent>
#include <math.h>

#include "constantes.h"
#include "../vues/vueentitee.h"


class VuePrincipaleControleur;

#include "controleurs/vueprincipalecontroleur.h"

class VuePrincipale : public QWidget
{
    Q_OBJECT
public:
    static QWidget* getwidget();
    void paintEntitee(QPoint posSouris);
    VueEntitee *ajoutEntitee(int x, int y, int type);
    QGraphicsScene* getScene();
    QGraphicsView* getView();
    static VuePrincipale* getInstanceOf();
    bool deplacerEntitee(VueEntitee* v,QPoint* posRelativeToparent);
    int getHauteurCaseEntiere();
    int getLargeurCaseEntiere();

protected:
    void resizeEvent(QResizeEvent *);
    void mousePressEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent* e);
    bool eventFilter(QObject *obj, QEvent *event);

private:
    static QWidget* ca;
    QGraphicsScene *m_scene;
    QGraphicsView *m_view;

    VuePrincipaleControleur *m_vpc;
    static VuePrincipale* instance;
    explicit VuePrincipale(QWidget *parent = 0);

    int grille[NB_CASE_Y][NB_CASE_X];
    double largeurCase;
    double hauteurCase;
    QPoint* getPosInGrille(QPoint pos);

    QSet<int> pressedKeys;

signals:
    void clickSouris(QPoint pos);

};

#endif // VUEPRINCIPALE_H
