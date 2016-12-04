#ifndef SELECTION_H
#define SELECTION_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

class SelectionControleur;

#include "controleurs/selectioncontroleur.h"

#define SOURIS 0
#define MACHINE 1
#define PASSERELLE 2
#define CABLE 3
#define HUB 4

class Selection : public QWidget
{
    Q_OBJECT
public:
    explicit Selection(QWidget *parent = 0);
    static int getEnSelection();
    static void setEnSelection(int es);
    QPushButton *souris;
    QPushButton *machine;
    QPushButton *passerelle;
    QPushButton *hub;
    QPushButton *cable;
    SelectionControleur *sc;

private:
    static int enSelection;
};

#endif // SELECTION_H
