#ifndef CABLE_DEF
#define CABLE_DEF

#include <iostream>
#include <vector>

#include "Machine.h"
#include "Passerelle.h"
#include "Hub.h"
#include "Entitee.h"
#include "ElementListeChainee.h"

class DataBase
{

	public:

    static void addMachine(Machine* m);
    static void retirerMachine(Machine* m);

	private:
    static int m_nbreMachine;
    static ElementListeChainee* m_premierElement;
};

#endif
