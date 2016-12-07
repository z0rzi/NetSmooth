#include "Ordinateur.h"

using namespace std;

Ordinateur::Ordinateur(int id)
  :Machine(id, TYPE_ORDINATEUR, lxc_container_new("ordinateur"+id,NULL))
{

}

Ordinateur::~Ordinateur(void)
{
  
}
