#ifndef CABLE_DEF
#define CABLE_DEF

#include <iostream>
#include <vector>

class Entitee;

#include "Entitee.h"

class Cable
{

	public:
		Cable(Entitee *ext1, Entitee *ext2);

		/*		getExtremitees
		 *	
		 *	ARGS:
		 *	arr: tableau vide de 2 cases:
		 *	     Entitee bobo[2];
		 *	     le code rempli ce tableau avec les
		 *	     extremitées du cable
		 */
		void getExtremites(Entitee** arr) const;

	private:
		/* les deux extrémitées du cable (ext comme extrémitée) */
		Entitee *m_ext1;
		Entitee *m_ext2;
};

#endif
