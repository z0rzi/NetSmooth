#ifndef VUEPASSERELLE_H
#define VUEPASSERELLE_H

#include "vueentitee.h"

class VuePasserelle : public VueEntitee
{
    Q_OBJECT
public:
    explicit VuePasserelle(VueEntitee *parent = 0);
    Passerelle* getModele(void);
    void setPasserelle(Passerelle* passerelle0);
    void terminal();

private:
    Passerelle* passerelle;

};

#endif // VUEPASSERELLE_H
