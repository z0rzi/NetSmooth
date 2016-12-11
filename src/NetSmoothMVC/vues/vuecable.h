#ifndef VUECABLE_H
#define VUECABLE_H

#include <iostream>
#include <QWidget>

using namespace std;

class VueCable : public QWidget
{
    Q_OBJECT
public:
    explicit VueCable(QWidget *parent = 0);
    //Cable* getCable(void);
protected:
    void paintEvent(QPaintEvent *event);

private:
    //Cable* cable=NULL;

};

#endif // VUECABLE_H
