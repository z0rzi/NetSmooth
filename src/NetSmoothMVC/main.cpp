#include <QApplication>
#include <QWidget>
#include <QGridLayout>

#include "vues/selection.h"
#include "vues/vueprincipale.h"

int Selection::enSelection = 0;

int main(int argc, char** argv)
{
    cout << "click droit pour demarer une machine, double click pour xterm" << endl;
    QApplication app(argc, argv);
    QWidget *w = new QWidget();
    Selection *s = new Selection();
    VuePrincipale *vp = new VuePrincipale();
    QGridLayout *g = new QGridLayout();
    g->addWidget(s,0,0,0);
    g->addWidget(vp,0,1,0);
    w->setLayout(g);
    w->show();

    return app.exec();
}
