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
#include "constantes.h"
#include "../vues/vueentitee.h"
#include "vues/Scene.h"
#include "MaGraphicsView.h"


class VuePrincipaleControleur;

#include "controleurs/vueprincipalecontroleur.h"

class VuePrincipale : public QWidget
{
    Q_OBJECT
public:
    void mousePressEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *e);
    static QWidget* getwidget();
    void paintEntitee(QPoint posSouris);
    VueEntitee *ajoutEntitee(int x, int y, int type);
    QGraphicsScene* getScene();
    MaGraphicsView* getView();
    static VuePrincipale* getInstanceOf();
    bool deplacerEntitee(VueEntitee* v,QPoint* posRelativeToparent);

protected:
    void resizeEvent(QResizeEvent *);

private:
    static QWidget* ca;
    QGraphicsScene *m_scene;
    MaGraphicsView *m_view;
    QPoint m_pos;
    VuePrincipaleControleur *m_vpc;
    static VuePrincipale* instance;
    explicit VuePrincipale(QWidget *parent = 0);

    int grille[NB_CASE_Y][NB_CASE_X];
    int largeurCase;
    int hauteurCase;
    QPoint* localFromGlobal(QPoint* pos);

signals:
    void clickSouris(QPoint pos);

};

#endif // VUEPRINCIPALE_H
