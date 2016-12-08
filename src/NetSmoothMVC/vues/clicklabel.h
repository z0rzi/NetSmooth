#ifndef CLICKLABEL_H
#define CLICKLABEL_H

#include <QObject>
#include <QLabel>
#include <QMouseEvent>
#include <iostream>

using namespace std;

class ClickLabel : public QLabel
{
    Q_OBJECT
public:
    ClickLabel(QLabel *parent = 0);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    static ClickLabel* getLabelEnSelection();
    static void setLabelEnSelection(ClickLabel* label);

private:
    static ClickLabel* LabelEnSelection;

signals:

};

#endif // CLICKLABEL_H
