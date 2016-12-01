#ifndef VUEPRINVCPALECONTROLEUR_H
#define VUEPRINVCPALECONTROLEUR_H

#include <QObject>
#include <iostream>

using namespace std;

class VuePrincipale;

#include "vueprincipale.h"
#include "vuemachine.h"
#include "vuepasserelle.h"
#include "vuehub.h"
#include "vueentitee.h"
#include "selection.h"
#include "vueentiteecontroleur.h"
#include "vuemachinecontroleur.h"
#include "vuehubcontroleur.h"
#include "vuepasserellecontroleur.h"

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
