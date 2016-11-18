#ifndef HUB_DEF
#define HUB_DEF

#include <iostream>
#include <vector>

#include "Entitee.h"
#include "Cable.h"

class Hub : public Entitee
{
	public:
		Hub();

	private:
		/* numero de Hub, s'incremente a chaque hub créé
		 * il sert nottament a nommer les bridge:
		 *     brH0   brM3
		 *        ^      ^  
		 */
		static int numHub;
};

#endif

