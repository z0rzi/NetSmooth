#ifndef CLICKLABEL_H
#define CLICKLABEL_H

#include <QObject>
#include <QLabel>
#include <QMouseEvent>

class ClickLabel : public QLabel
{
    Q_OBJECT
public:
    ClickLabel(QLabel *parent = 0);
    void mouseDoubleClickEvent(QMouseEvent *e);

signals:
    void doubleClick();

};

#endif // CLICKLABEL_H
