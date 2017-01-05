#ifndef VUEFORMULAIREIP_H
#define VUEFORMULAIREIP_H

#include <iostream>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QTextEdit>
#include <QGridLayout>
#include <QString>
#include <QLabel>

class VueFormulaireIP : public QGridLayout
{

    Q_OBJECT
public:
    explicit VueFormulaireIP(QWidget *parent = 0);
    QString getIpv4(void);
    QString getIpv6(void);
    QString getMask(void);

    QString setIpv4(void);
    QString setIpv6(void);
    QString setMask(void);
private:
    QTextEdit* ipv4;
    QTextEdit* ipv6;
    QTextEdit* mask;

signals:

public slots:
};

#endif
