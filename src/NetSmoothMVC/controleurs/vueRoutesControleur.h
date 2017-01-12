#ifndef VUEROUTESCONTROLEUR_H
#define VUEROUTESCONTROLEUR_H

#include <QObject>
#include <iostream>
#include "vues/vueentitee.h"
#include "vues/constantes.h"
#include "modeles/Entitee.h"
#include "modeles/Machine.h"
#include "vues/selection.h"

using namespace std;

class VueRoutes;

#include "vues/vueRoutes.h"

class VueRoutesControleur : public QObject
{
    Q_OBJECT
public:
    explicit VueRoutesControleur(VueRoutes* vue, QObject *parent = 0);

private:
    VueRoutes* vue;

signals:

public slots:
};

#endif
