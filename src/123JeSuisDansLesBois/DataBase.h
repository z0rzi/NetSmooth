#ifndef CABLE_DEF
#define CABLE_DEF

#include <iostream>
#include <vector>

#include "Machine.h"
#include "Passerelle.h"
#include "Hub.h"
#include "Entitee.h"

class DataBase
{

	public:

		static DataBase getDataBase();

		static void addMachine(Machine* m);
		static void rmMachine(Machine* m);
		static std::vector<Machine*> getMachines();

		/** faire la même chose pour tous les types**/

	private:
		/* 	les adresses des deux extrémitées du
		 *	cable (ext comme extrémitée) 
		 */
		DataBase();
		std::vector<Machine*> machines;
		std::vector<Hub*> hubs;
		std::vector<Passerelle*> passerelles;
		//std::vector<Bridge*> bridges;
		//on a pas de types Bridge
};

#endif
