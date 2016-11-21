#ifndef CABLE_DEF
#define CABLE_DEF

#include <iostream>
#include <vector>


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
    vector<Machine*> machines;
    vector<Hub*> hubs;
    vector<Passerelle*> passerelles;
    vector<Bridge*> bridges;
};

#endif
