#ifndef VUEFORMULAIREIPCONTROLEUR_H
#define VUEFORMULAIREIPCONTROLEUR_H

#include <QObject>
#include <iostream>
#include "vues/vueentitee.h"
#include "vues/constantes.h"
#include "modeles/Entitee.h"
#include "vues/VueFormulaireIP.h"
class VueFormulaireIP;

class VueFormulaireIPControleur : public QObject
{
    Q_OBJECT
public:
    explicit VueFormulaireIPControleur(VueFormulaireIP* vue, QPushButton* valider, QObject *parent = 0);

private:
    VueFormulaireIP* vue;

signals:

public slots:
    void appliquerModif();

};

#endif
