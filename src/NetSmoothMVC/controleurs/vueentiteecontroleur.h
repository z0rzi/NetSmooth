#ifndef VUEENTITEECONTROLEUR_H
#define VUEENTITEECONTROLEUR_H

#include <QPoint>
#include <QObject>

class VueEntitee;
class VuePrincipale;

#include "vues/vueentitee.h"
class VueEntiteeControleur : public QObject
{
    Q_OBJECT
public:
    explicit VueEntiteeControleur(VueEntitee* vue, QObject *parent = 0);

private:
    VueEntitee *vue;

signals:

public slots:
    void actionMoveLeftButton();
};
#endif // VUEENTITEECONTROLEUR_H
