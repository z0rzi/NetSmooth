#include "VueFormulaireIP.h"

VueFormulaireIP::VueFormulaireIP(QWidget *parent)
    : QGridLayout(parent)
{

    QLabel* labelIpv4 = new QLabel("ipv4 :");
    QLabel* labelIpv6 = new QLabel("ipv6 :");
    QLabel* labelMask = new QLabel("Masque ipv4 :");

    this->ipv4 = new QTextEdit();
    this->mask = new QTextEdit();
    this->ipv6 = new QTextEdit();

    this->ipv4->setFixedHeight(25);
    this->mask->setFixedHeight(25);
    this->ipv6->setFixedHeight(25);

    this->addWidget(labelIpv4,0,0);
    this->addWidget(ipv4,0,1);
    this->addWidget(labelMask,1,0);
    this->addWidget(mask,1,1);
    this->addWidget(labelIpv6,2,0);
    this->addWidget(ipv6,2,1);
}

QString VueFormulaireIP::getIpv4()
{
    return this->ipv4->toPlainText();
}

QString VueFormulaireIP::getIpv6()
{
    return this->ipv6->toPlainText();
}

QString VueFormulaireIP::getMask()
{
    return this->mask->toPlainText();
}

void VueFormulaireIP::setIpv4(QString t)
{
    this->ipv4->setText(t);
}

void VueFormulaireIP::setIpv6(QString t)
{
    this->ipv6->setText(t);
}

void VueFormulaireIP::setMask(QString t)
{
    this->mask->setText(t);
}
