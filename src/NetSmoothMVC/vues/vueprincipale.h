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

using namespace std;

class VuePrincipaleControleur;

#include "controleurs/vueprincipalecontroleur.h"

class VuePrincipale : public QWidget
{
    Q_OBJECT
public:
    explicit VuePrincipale(QWidget *parent = 0);
    void mouseDoubleClickEvent(QMouseEvent *e);
    QGraphicsScene *scene;
    QGraphicsView *view;
    QPoint pos;
    VuePrincipaleControleur *vpc;
    static VuePrincipale* getwidget();
    static QPoint* getPosition();

private:
    static VuePrincipale* ca;

signals:
    void clickSouris(QPoint pos);

};

#endif // VUEPRINCIPALE_H
