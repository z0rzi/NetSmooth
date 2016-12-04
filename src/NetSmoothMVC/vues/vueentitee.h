#ifndef VUEENTITEE_H
#define VUEENTITEE_H

#include <QObject>
#include <QWidget>
#include <QMouseEvent>
#include "clicklabel.h"
#include "../123JeSuisDansLesBois/Machine.h"
#include "../123JeSuisDansLesBois/Bridge.h"
#include "../123JeSuisDansLesBois/Cable.h"
#include "../123JeSuisDansLesBois/Constantes.h"
#include "../123JeSuisDansLesBois/DataBase.h"
#include "../123JeSuisDansLesBois/Hub.h"
#include "../123JeSuisDansLesBois/Ordinateur.h"
#include "../123JeSuisDansLesBois/Passerelle.h"
#include "../123JeSuisDansLesBois/Entitee.h"
#include <lxc/lxccontainer.h>

class VueEntitee : public QObject
{
    Q_OBJECT
public:
    explicit VueEntitee(QObject *parent = 0);
    ClickLabel* zoneImg;
    bool etat;

protected:

signals:

};

#endif // VUEENTITEE_H
