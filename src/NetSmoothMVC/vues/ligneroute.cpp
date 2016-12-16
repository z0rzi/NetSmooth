#include "ligneroute.h"

LigneRoute::LigneRoute(QLabel *parent) : QLabel(parent)
{
    valider = new QPushButton();
    layout = new QGridLayout();
    edest = new QTextEdit();
    epass = new QTextEdit();
    einter = new QTextEdit();

    valider->setText("OK");
    valider->setFixedWidth(25);
    edest->setFixedHeight(25);
    epass->setFixedHeight(25);
    einter->setFixedHeight(25);

    layout->addWidget(edest,0,0);
    layout->addWidget(epass,0,1);
    layout->addWidget(einter,0,2);
    layout->addWidget(valider,0,3);

    setLayout(layout);

}

QPushButton* LigneRoute::getValider()
{
    return this->valider;
}

QTextEdit* LigneRoute::getEdest()
{
    return this->edest;
}

QTextEdit* LigneRoute::getEpass()
{
    return this->epass;
}

QTextEdit* LigneRoute::getEinter()
{
    return this->einter;
}

void LigneRoute::bloquer()
{
    this->edest->setReadOnly(true);
    this->epass->setReadOnly(true);
    this->einter->setReadOnly(true);
    this->valider->setText("X");
}

void LigneRoute::debloquer()
{
    this->edest->setReadOnly(false);
    this->epass->setReadOnly(false);
    this->einter->setReadOnly(false);
    this->valider->setText("OK");
}

void LigneRoute::setId(int id)
{
    this->m_id=id;
}

int LigneRoute::getId() const
{
    return this->m_id;
}
