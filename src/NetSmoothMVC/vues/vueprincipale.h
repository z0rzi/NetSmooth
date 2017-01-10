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
    void mousePressEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *e);
    QGraphicsScene *scene;
    QGraphicsView *view;
    QPoint pos;
    VuePrincipaleControleur *vpc;
    static QWidget* getwidget();
    void paintEntitee(QPoint posSouris);

private:
    static QWidget* ca;

signals:
    void clickSouris(QPoint pos);

};

#endif // VUEPRINCIPALE_H
