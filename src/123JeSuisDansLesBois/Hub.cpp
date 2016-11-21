#include "Hub.h"

using namespace std;

int Hub::numHub=0;

Hub::Hub()
	:Entitee(numHub, TYPE_HUB)
{
	numHub++;
}
