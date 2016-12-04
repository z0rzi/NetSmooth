#ifndef VUEHUBCONTROLEUR_H
#define VUEHUBCONTROLEUR_H

#include <QObject>
#include "controleurs/vueentiteecontroleur.h"
#include "vues/vuehub.h"

class VueHubControleur : public VueEntiteeControleur
{
    Q_OBJECT
public:
    explicit VueHubControleur(VueHub* vue, VueEntiteeControleur *parent = 0);

private:
    VueHub* vue;

public slots:
    void allumer();
};

#endif // VUEHUBCONTROLEUR_H
