#ifndef VUECABLECONTROLEUR_H
#define VUECABLECONTROLEUR_H

#include <QObject>


#include "vues/vueentitee.h"
class VueCableControleur : public QObject
{
    Q_OBJECT
public:
    explicit VueCableControleur(VueCable* vue, QObject *parent = 0);

private:
    VueCable *vue;

signals:

public slots:
    void actionDeleteCable();
};
#endif
