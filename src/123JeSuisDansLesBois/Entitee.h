#ifndef ENTITEE_DEF
#define ENTITEE_DEF

class Cable;

#include <iostream>
#include <stdio.h>
#include "Cable.h"

class Entitee
{
	public:
		Entitee(int numType, char type);
		std::string getBridge_vir(void) const;
		std::string getBridge_reel(void) const;
		void setBridge_reel(std::string bridge);
		void machineLancee();
		void machineAretee();
		int getEtatMachine();
		char getType();

		std::vector<Cable*> getCables(void);
		void addCable(Cable *cable);

	protected:
		/*
		 *	le bridge virtuel est unique a chaque entitée,
		 *	c'est le nom de bridge que l'on va créer et auquel
		 *	la machine va se connecter si on la demare et que elle
		 *	n'est connectée a personne d'allumé
		 *	
		 *	il commence toujours par "br", puis un charactere
		 *	suivant son type: 'H' 'M' ou 'P', et enfin le numero
		 *	de création de l'entitée; par exemple, si un hub
		 *	est le 3eme a etre créé, son numero de créqtion sera
		 *	2 (car 0, 1, 2)
		 *	
		 *	exemple : brH0  brM6  brP3
		 */
		std::string m_bridge_virtuel;

		/*
		 *	le bridge reel est le bridge auquel la machine
		 *	est connecté, on l'initialise juste avant de
		 *	démarer la machine, en observant ses connexions:
		 *	ca sera soit le bridge reel de son entourage, 
		 *	soit son bridge virtuel
		 */
		std::string m_bridge_reel;

		int m_running;

		/*
		 *	liste de Cables auquel l'entitee est reilée
		 *	ATTENTION, rien au niveau du code n'empeche
		 *	de mettre 2 cables sur une machine,
		 *	IL NE FAUT PAS LE FAIRE, sinon ca va tout casser
		 *	au demarage de la machine... TOUT CASSER!!!
		 */
		std::vector<Cable*> m_cableList;

		char m_type;	/*'M' machine 'H' hub 'P' passerelle*/
};

#endif
