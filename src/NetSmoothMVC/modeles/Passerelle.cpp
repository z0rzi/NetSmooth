#include "Passerelle.h"

using namespace std;

Passerelle::Passerelle(int id)
		:Machine(id, TYPE_PASSERELLE, lxc_container_new("passerelle"+id,NULL))
{
}
