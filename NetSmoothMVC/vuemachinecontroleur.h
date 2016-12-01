#ifndef VUEMACHINECONTROLEUR_H
#define VUEMACHINECONTROLEUR_H

#include <QObject>
#include "vueentiteecontroleur.h"
#include "vuemachine.h"
#include <iostream>

using namespace std;

class VueMachineControleur : public VueEntiteeControleur
{
    Q_OBJECT
public:
    explicit VueMachineControleur(VueMachine* vue, VueEntiteeControleur *parent = 0);

private:
    VueMachine* vue;

signals:

public slots:
    void allumer();
};

#endif // VUEMACHINECONTROLEUR_H
