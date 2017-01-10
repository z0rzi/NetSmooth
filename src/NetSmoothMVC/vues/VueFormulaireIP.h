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

    void setIpv4(QString t);
    void setIpv6(QString t);
    void setMask(QString t);

private:
    QTextEdit* ipv4;
    QTextEdit* ipv6;
    QTextEdit* mask;

signals:

public slots:
};

#endif
