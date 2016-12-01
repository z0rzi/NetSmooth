#ifndef BRIDGE_DEF
#define BRIDGE_DEF

#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

class Bridge
{
	public:
		/*	creerBridge
		 *
		 *	permet de créer un bridge sur la machine hote
		 *
		 *	ARGS
		 *	-nomPont:	nom du bridge a créer
		 */
		static void creerBridge(const char* nomPont);

		/*	detruireBridge
		 *
		 *	permet de détruire un bridge sur la machine hote
		 *
		 *	ARGS
		 *	-nomPont:	nom du bridge a détruire
		 */
		static void detruireBridge(const char* nomPont);

	private:
};

#endif
