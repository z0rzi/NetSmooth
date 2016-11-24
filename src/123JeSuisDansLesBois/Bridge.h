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
		static void creerBridge(const char* nomPont);
		static void detruireBridge(const char* nomPont);

	private:
};

#endif
