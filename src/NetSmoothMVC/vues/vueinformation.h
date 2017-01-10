#ifndef VUEINFORMATION_H
#define VUEINFORMATION_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QTextEdit>
#include <QLabel>
#include "vues/vueRoutes.h"
#include "vues/ligneroute.h"
#include "controleurs/vueRoutesControleur.h"
#include "selection.h"
#include "vues/VueIP.h"


class VueInformation : public QWidget
{
    Q_OBJECT
public:
    static VueInformation* getInstanceOf();
    void refresh(QWidget* s);
    void setSource(QWidget* s);
    QWidget* getSource();
    void vider();
    void setAllumer(QPushButton*);
    QPushButton* getAllumer();

    VueRoutes* getRoutes();
    void setRoutes(VueRoutes* v);

    VueIP* getVueIP(void);
    void setVueIP(VueIP* v);

private:
    static VueInformation* instance;
    explicit VueInformation(QWidget *parent = 0);
    QWidget* source;
    QPushButton* allumer;
    VueRoutes* routes;
    VueIP* vueIP;

signals:
    void refresh();

public slots:
};

#endif // VUEINFORMATION_H
