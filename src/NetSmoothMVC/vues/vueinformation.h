#ifndef VUEINFORMATION_H
#define VUEINFORMATION_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QTextEdit>
#include <QLabel>
#include "vues/ligneroute.h"

class VueInformation : public QWidget
{
    Q_OBJECT
public:
    static VueInformation* getInstanceOf();
    void setlastV4(LigneRoute* lr);
    void setlastV6(LigneRoute* lr);
    void refresh(QWidget* s);
    void setSource(QWidget* s);
    QWidget* getSource();
    LigneRoute* getLastV4();
    LigneRoute* getLastV6();
    QGridLayout* getLayoutRoute4();
    QGridLayout* getLayoutRoute6();
    int getNbr4();
    int getNbr6();
    void setNbr4(int n);
    void setNbr6(int n);

private:
    static VueInformation* instance;
    explicit VueInformation(QWidget *parent = 0);
    QWidget* source;
    LigneRoute* lastV4;
    LigneRoute* lastV6;
    QGridLayout* layoutRoute4;
    QGridLayout* layoutRoute6;
    int nbrLigne4;
    int nbrLigne6;

signals:
    void refresh();

public slots:
};

#endif // VUEINFORMATION_H
