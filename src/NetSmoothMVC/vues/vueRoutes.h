#ifndef VUEROUTES_H
#define VUEROUTES_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QTextEdit>
#include <QLabel>
#include "vues/ligneroute.h"
#include "modeles/Entitee.h"
#include "modeles/Machine.h"
#include "controleurs/vueRoutesControleur.h"
#include <QScrollArea>

class VueRoutesControleur;

class VueRoutes : public QGridLayout
{
    Q_OBJECT
public:
    explicit VueRoutes(QWidget *parent=0);
    void refresh();
    void deleteRoutes();
    void addRoutes();
    void setSource(Entitee* e);
    Entitee* getSource();

private:
    Entitee* m_source;
    VueRoutesControleur* controleur = NULL;
    QWidget* routesVersion4;
    QWidget* routesVersion6;

signals:

public slots:
    void deleteRoute4();
    void addRoute4();
    void deleteRoute6();
    void addRoute6();
};

#endif
