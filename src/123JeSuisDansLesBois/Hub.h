#ifndef HUB_DEF
#define HUB_DEF

#include <iostream>
#include <vector>

#include "Entitee.h"

class Hub : public Entitee
{
	public:
		/*	Hub
		 *
		 *	constructeur de la classe, il appelle le constructeur
		 *	de son parent
		 */
		Hub();
		
		/*	Methodes inutiles
		 *
		 *	ces methodes ne sont redéfinies ici que pour respecter
		 *	les methodes virtuelles pures du parent, mais elles 
		 *	ne sont pas utiles ici (elles le sont dans l'autre
		 *	enfant en revanche: Machine)
		 * 
		 */
		void appliquerParamIp();
		void appliquerParamRoutage();
		int lancerContainer();
		void lierABridge();
		int stopperContainer();

	private:
		/* numero de Hub, s'incremente a chaque hub créé
		 * il sert nottament a nommer les bridge:
		 *     brH0   brM3
		 *        ^      ^  
		 */
		static int numHub;
};

#endif

