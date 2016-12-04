#ifndef VUEPRINVCPALECONTROLEUR_H
#define VUEPRINVCPALECONTROLEUR_H

#include <QObject>
#include <iostream>

using namespace std;

class VuePrincipale;

#include "vues/vueprincipale.h"
#include "vues/vuemachine.h"
#include "vues/vuepasserelle.h"
#include "vues/vuehub.h"
#include "vues/vueentitee.h"
#include "vues/selection.h"
#include "controleurs/vueentiteecontroleur.h"
#include "controleurs/vuemachinecontroleur.h"
#include "controleurs/vuehubcontroleur.h"
#include "controleurs/vuepasserellecontroleur.h"

class VuePrincipaleControleur : public QObject
{
    Q_OBJECT
public:
    explicit VuePrincipaleControleur(VuePrincipale *vue, QObject *parent = 0);

private:
    VuePrincipale *vue;

signals:

public slots:
    void paintMachine(QPoint pos);
};

#endif // VUEPRINCIPALECONTROLEUR_H
