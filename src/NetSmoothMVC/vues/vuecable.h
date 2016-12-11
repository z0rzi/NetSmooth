#ifndef VUECABLE_H
#define VUECABLE_H

#include <iostream>
#include <QWidget>
#include "modeles/Cable.h"
#include "vues/vueentitee.h"

using namespace std;

class VueCable : public QWidget
{
    Q_OBJECT
public:
    explicit VueCable(VueEntitee* v1, VueEntitee* v2,QWidget *parent = 0);
    Cable* getModele(void);

    static void creerVueCable(VueEntitee *v);
    static VueEntitee* getPremiereSelection();
    static VueEntitee* getSecondeSelection();
    static void setPremiereSelection(VueEntitee* v);
    static void setSecondeSelection(VueEntitee* v);

protected:
    void paintEvent(QPaintEvent *event);

private:
    VueEntitee *m_v1 = NULL;
    VueEntitee *m_v2 = NULL;
    Cable* cable = NULL;
    static VueEntitee* PremiereSelection;//Pour créer cables
    static VueEntitee* SecondeSelection;//Pour créer cables

};

#endif // VUECABLE_H
