#include "Passerelle.h"

using namespace std;

int Passerelle::numPass=0;

Passerelle::Passerelle(struct lxc_container *container)
		:Ordinateur(numPass, TYPE_PASSERELLE, container)
{
	numPass++;
}
