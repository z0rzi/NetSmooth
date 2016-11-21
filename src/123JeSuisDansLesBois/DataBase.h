#ifndef CABLE_DEF
#define CABLE_DEF

#include <iostream>
#include <vector>


#include "Entitee.h"

class DataBase
{

	public:

    static DataBase getDataBase();

		/*	addCable
		 *	
		 *	ARGS:
		 *	-arr: 		doit etre un tableau vide de 2 cases:
		 *	     		Entitee bobo[2]; par exemple
		 *	    		le code rempli ce tableau avec les
		 *	    		adresses des extremitées du cable
		 */

    void addMachine(Machine* m);
    void rmMachine(Machine* m);
    vector<Machine*> getMachines();

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
