#ifndef VUEENTITEECONTROLEUR_H
#define VUEENTITEECONTROLEUR_H

#include <QObject>

class VueEntitee;

#include "vueentitee.h"

class VueEntiteeControleur : public QObject
{
    Q_OBJECT
public:
    explicit VueEntiteeControleur(QObject *parent = 0);

private:
    VueEntitee *vue;

signals:

public slots:
    virtual void allumer() = 0;
};

#endif // VUEENTITEECONTROLEUR_H
