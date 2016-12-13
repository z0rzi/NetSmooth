#ifndef LIGNEROUTE_H
#define LIGNEROUTE_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QTextEdit>
#include <QGridLayout>
#include <QPushButton>

class LigneRoute : public QLabel
{
    Q_OBJECT
public:
    explicit LigneRoute(QLabel *parent = 0);
    QPushButton* getValider();
    QTextEdit* getEdest();
    QTextEdit* getEpass();
    QTextEdit* getEinter();
    void bloquer();
    void debloquer();

private:
    QPushButton* valider;
    QGridLayout* layout;
    QTextEdit* edest;
    QTextEdit* epass;
    QTextEdit* einter;

signals:

public slots:
};

#endif // LIGNEROUTE_H
