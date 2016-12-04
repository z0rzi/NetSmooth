#ifndef SELECTIONCONTROLEUR_H
#define SELECTIONCONTROLEUR_H

#include <QObject>
#include <iostream>

using namespace std;

class Selection;

#include "vues/selection.h"

class SelectionControleur : public QObject
{
    Q_OBJECT
public:
    explicit SelectionControleur(Selection *vue, QObject *parent = 0);

private:
    Selection *vue;

signals:

public slots:
    void changeEnSelection();
};

#endif // SELECTIONCONTROLEUR_H
