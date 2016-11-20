#ifndef ENTITEE_DEF
#define ENTITEE_DEF

class Cable;

#include <iostream>
#include <stdio.h>
#include "Cable.h"
#include "Constantes.h"

class Entitee
{
	public:
		/*	Entitee
		 *	
		 *	Constructeur de la classe, il initialise le 
		 *	nom de bridge par defaut pour hub et passerelles
		 *	
		 *	ARGS
		 *	-numtype :	numero de la machine créée, il doit
		 *			etre unique pour chaque ma de meme
		 *			type
		 *	
		 *	-type :		numero correspondant au type, se 
		 *			réferer au fichier 
		 *			Constantes.h -> TYPE_****
		 */
		Entitee(int numType, int type);

		std::string getBridge_vir(void) const;
		std::string getBridge_reel(void) const;
		void setBridge_reel(std::string bridge);

		/*	getEtatMachine
		 *
		 *	permet d'obtenir l'etat de la machine
		 *	
		 *	RETURN VALUE
		 *	elle retourne un booleen : true si la 
		 *	machine est allumée et false sinon.
		 *	
		 *	NOTE
		 *	cette methode est applicable sur n'importe
		 *	quel entitee, cad Machine, Passerelle ou Hub
		 */
		bool getEtatMachine(void);

		/*	setEtatMachine
		 *
		 *	permet de modifier l'etat de la machine
		 *	
		 *	ARGS
		 *	-etat:		booleen: true si vous avez
		 *			allumé la machine, false si
		 *			vous l'avez eteinte
		 *
		 *	NOTE
		 *	cette methode est applicable sur n'importe
		 *	quel entitee, cad Machine, Passerelle ou Hub
		 */
		void setEtatMachine(bool etat);

		/*	getType
		 *
		 *	permet de connaitre le type de l'entitee
		 *	
		 *	RETURN VALUE
		 *	retourne un entier representant le type; se réferer 
		 *	au fichier Constantes.h -> TYPE_****
		 */
		int getType(void);

		/*	getCables
		 *
		 *	permet de recuperer les cables auxquels est
		 *	connecté l'entitée
		 *	
		 *	RETURN VALUE
		 *	renvoie un "vector" (=tableau plus ou moins)
		 *	d'adresses de Cables dans lequel tous les
		 *	cables auquels l'entitee est relié sont repertoriés
		 */
		std::vector<Cable*> getCables(void);

		/*	addCable
		 *	
		 *	permet d'ajouter un cable a la liste des cables 
		 *	de l'entitée
		 *	
		 *	ARGS
		 *	-cable:		adresse du cable a ajouter
		 *	
		 *	NOTE
		 *	ne pas créer le cable a ajouter dans un une 
		 *	structure conditionnelle ou une boucle, sinon
		 *	le cable disparaitra *POOF*
		 *
		 */
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
		
		/*	variable representant l'etat de l'entitée
		 *	elle vaut true si la machine est allumée et
		 *	false sinon
		 *
		 */
		bool m_running;

		/*
		 *	liste de Cables auquel l'entitee est reliée
		 *	ATTENTION, rien au niveau du code n'empeche
		 *	de mettre 2 cables sur une machine,
		 *	IL NE FAUT PAS LE FAIRE, sinon ca va tout casser
		 *	au demarage de la machine... TOUT CASSER!!!
		 */
		std::vector<Cable*> m_cableList;

		int m_type;
};

#endif
