#ifndef VUEPASSERELLE_H
#define VUEPASSERELLE_H

#include "vueentitee.h"

class VuePasserelle : public VueEntitee
{
	Q_OBJECT
	public:
		explicit VuePasserelle(VueEntitee *parent = 0);
	private:
		Passerelle* passerelle;
};

#endif // VUEPASSERELLE_H
