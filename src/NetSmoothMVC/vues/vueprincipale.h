#ifndef VUEPRINCIPALE_H
#define VUEPRINCIPALE_H

#include <QMainWindow>
#include <QGridLayout>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QPen>
#include <iostream>
#include <QMouseEvent>
#include "constantes.h"
#include "../vues/vueentitee.h"



using namespace std;

class VuePrincipaleControleur;

#include "controleurs/vueprincipalecontroleur.h"

class VuePrincipale : public QWidget
{
    Q_OBJECT
public:
    explicit VuePrincipale(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *e);
    static QWidget* getwidget();
    void paintEntitee(QPoint posSouris);
    VueEntitee *ajoutEntitee(int x, int y, int type);
    QGraphicsScene* getScene();
    QGraphicsView* getView();
    static VuePrincipale* getInstanceOf();


private:
    static QWidget* ca;
    QGraphicsScene *m_scene;
    QGraphicsView *m_view;
    QPoint m_pos;
    VuePrincipaleControleur *m_vpc;

signals:
    void clickSouris(QPoint pos);
    static VuePrincipale* instance;


};

#endif // VUEPRINCIPALE_H
