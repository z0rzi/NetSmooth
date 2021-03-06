#ifndef VUEMACHINECONTROLEUR_H
#define VUEMACHINECONTROLEUR_H

#include <QObject>
#include "controleurs/vueentiteecontroleur.h"
#include "vues/vuemachine.h"
#include "modeles/Ordinateur.h"
#include <iostream>

class VueMachineControleur : public VueEntiteeControleur
{
        Q_OBJECT
public:
        explicit VueMachineControleur(VueMachine* vue, VueEntiteeControleur *parent = 0);

private:
        VueMachine* vue;

signals:

public slots:
        void actionDoubleClick();
};

#endif // VUEMACHINECONTROLEUR_H
