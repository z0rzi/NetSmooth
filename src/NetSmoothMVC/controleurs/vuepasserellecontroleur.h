#ifndef VUEPASSERELLECONTROLEUR_H
#define VUEPASSERELLECONTROLEUR_H

#include <QObject>
#include "vueentiteecontroleur.h"
#include "vuepasserelle.h"

class VuePasserelleControleur : public VueEntiteeControleur
{
    Q_OBJECT
public:
    explicit VuePasserelleControleur(VuePasserelle* vue, VueEntiteeControleur *parent = 0);

private:
    VuePasserelle* vue;

public slots:
    void allumer();

};

#endif // VUEPASSERELLECONTROLEUR_H
