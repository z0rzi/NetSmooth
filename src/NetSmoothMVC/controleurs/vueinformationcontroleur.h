#ifndef VUEINFORMATIONCONTROLEUR_H
#define VUEINFORMATIONCONTROLEUR_H

#include <QObject>
#include <iostream>

using namespace std;

class VueInformation;

#include "vues/vueinformation.h"

class VueInformationControleur : public QObject
{
    Q_OBJECT
public:
    explicit VueInformationControleur(VueInformation* vue, QObject *parent = 0);

private:
    VueInformation* vue;

signals:

public slots:
    void ajoutLigne4();
    void ajoutLigne6();
    void refreshVue();
};

#endif // VUEINFORMATIONCONTROLEUR_H
