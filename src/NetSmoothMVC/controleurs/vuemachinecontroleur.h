#ifndef VUEMACHINECONTROLEUR_H
#define VUEMACHINECONTROLEUR_H

#include <QObject>
#include "controleurs/vueentiteecontroleur.h"
#include "vues/vuemachine.h"
#include "modeles/Ordinateur.h"
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

<<<<<<< HEAD
	public slots:
		void allumer();
=======
public slots:
        void allumer();
>>>>>>> 3b66ffdd4b9fbc559aec8a45e3829e53313da281
        void terminal();
};

#endif // VUEMACHINECONTROLEUR_H
