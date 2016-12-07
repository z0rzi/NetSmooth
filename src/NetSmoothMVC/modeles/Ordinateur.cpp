#include "Ordinateur.h"

using namespace std;

Ordinateur::Ordinateur(id)
		:Machine(id, TYPE_ORDINATEUR, lxc_container_new("ordinateur"+id))
{

}

