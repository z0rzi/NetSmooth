#include "selection.h"

Selection::Selection(QWidget *parent) : QWidget(parent)
{
    setFixedSize(150,500);

    setEnSelection(SOURIS);

    this->souris = new QPushButton(tr("Souris"),this);
    this->machine = new QPushButton(tr("Machine"), this);
    this->passerelle = new QPushButton(tr("Passerelle"), this);
    this->hub = new QPushButton(tr("Hub"), this);
    this->cable = new QPushButton(tr("Cable"), this);
    this->sc = new SelectionControleur(this);

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

QPushButton* Selection::getSouris()
{
    return this->souris;
}

QPushButton* Selection::getMachine()
{
    return this->machine;
}

QPushButton* Selection::getPasserelle()
{
    return this->passerelle;
}

QPushButton* Selection::getHub()
{
    return this->hub;
}

QPushButton* Selection::getCable()
{
    return this->cable;
}
