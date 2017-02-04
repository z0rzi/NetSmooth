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
#include "modeles/Save.h"


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
    void allumer();

    VueRoutes* getRoutes();
    void setRoutes(VueRoutes* v);

    VueIP* getVueIP(void);
    void setVueIP(VueIP* v);

private:
    static VueInformation* instance;
    explicit VueInformation(QWidget *parent = 0);
    QWidget* m_source;
    QPushButton* m_allumer;
    VueRoutes* m_routes;
    VueIP* m_vueIP;

signals:
    void refresh();

public slots:
};

#endif // VUEINFORMATION_H
