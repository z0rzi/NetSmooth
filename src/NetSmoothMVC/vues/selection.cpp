#include "selection.h"

Selection::Selection(QWidget *parent) : QWidget(parent)
{
    setFixedSize(150,500);

    setEnSelection(SOURIS);

    souris = new QPushButton(tr("Souris"),this);
    machine = new QPushButton(tr("Machine"), this);
    passerelle = new QPushButton(tr("Passerelle"), this);
    hub = new QPushButton(tr("Hub"), this);
    cable = new QPushButton(tr("Cable"), this);
    sc = new SelectionControleur(this);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(souris,0,0);
    layout->addWidget(machine,1,0);
    layout->addWidget(passerelle,2,0);
    layout->addWidget(hub,3,0);
    layout->addWidget(cable,4,0);
    setLayout(layout);

}

int Selection::getEnSelection()
{
    return enSelection;
}

void Selection::setEnSelection(int es)
{
    enSelection = es;
}
