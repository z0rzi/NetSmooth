#ifndef VUEINFORMATION_H
#define VUEINFORMATION_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QTextEdit>
#include <QLabel>
#include <QCoreApplication>
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
    void refresh(QGraphicsPixmapItem* s);
    void setSource(QGraphicsPixmapItem* s);
    QGraphicsPixmapItem* getSource();
    void vider();
    void setAllumer(QPushButton*);
    QPushButton* getAllumer();
    void allumer();

    VueRoutes* getRoutes();
    void setRoutes(VueRoutes* v);

    VueIP* getVueIP(void);
    void setVueIP(VueIP* v);
    void addNewInfos();
    Entitee* getModele();
    std::string getName();

private:
    static VueInformation* instance;
    explicit VueInformation(QWidget *parent = 0);
    QGraphicsPixmapItem* m_source;
    QPushButton* m_allumer;
    VueRoutes* m_routes;
    VueIP* m_vueIP;
    QTextEdit* m_name;

signals:
    void refresh();

public slots:
};

#endif // VUEINFORMATION_H
