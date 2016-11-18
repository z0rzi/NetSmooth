#include "Cable.h"
#include "Machine.h"
#include "Entitee.h"

using namespace std;

Cable::Cable(Entitee* ext1, Entitee* ext2)
		:m_ext1(ext1), m_ext2(ext2)
{
}

void Cable::getExtremites(Entitee** arr) const
{
	arr[0]=m_ext1;
	arr[1]=m_ext2;
}
