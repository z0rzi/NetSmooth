#ifndef FENETRE_H
#define FENETRE_H

#include <QMainWindow>

class Fenetre : public QMainWindow
{
    Q_OBJECT
public:
    explicit Fenetre(QWidget *parent = 0);

signals:

public slots:
    void save();
    void load();
    void quit();
};

#endif // FENETRE_H
