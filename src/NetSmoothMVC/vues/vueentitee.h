#ifndef VUEENTITEE_H
#define VUEENTITEE_H

#include <QObject>
#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
#include "modeles/Machine.h"
#include "modeles/Bridge.h"
#include "modeles/Cable.h"
#include "modeles/Constantes.h"
#include "modeles/DataBase.h"
#include "modeles/Hub.h"
#include "modeles/Ordinateur.h"
#include "modeles/Passerelle.h"
#include "modeles/Entitee.h"
#include <lxc/lxccontainer.h>

class VueEntitee : public QLabel
{
    Q_OBJECT
public:
    explicit VueEntitee(QLabel *parent = 0);
    bool etat;
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *e);
    static VueEntitee* getLabelEnSelection();
    static void setLabelEnSelection(VueEntitee* label);

private:
    static VueEntitee* LabelEnSelection;

signals:
    void rightClick();
    void doubleClick();
};

#endif // VUEENTITEE_H
