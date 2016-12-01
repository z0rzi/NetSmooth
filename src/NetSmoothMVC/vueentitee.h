#ifndef VUEENTITEE_H
#define VUEENTITEE_H

#include <QObject>
#include <QWidget>
#include <QMouseEvent>
#include "clicklabel.h"

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
