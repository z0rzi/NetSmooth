#include "Ordinateur.h"

using namespace std;

int Ordinateur::numOrdi=0;

Ordinateur::Ordinateur(struct lxc_container *container)
		:Machine(numOrdi, TYPE_ORDINATEUR, container)
{
	numOrdi++;
}

