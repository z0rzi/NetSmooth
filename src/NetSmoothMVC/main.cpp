#include <QApplication>
#include <QWidget>
#include <QGridLayout>

#include "vues/selection.h"
#include "vues/vueprincipale.h"
#include "vues/vueinformation.h"
#include "controleurs/vueinformationcontroleur.h"
#include "vues/fenetre.h"

int Selection::m_enSelection = 0;

int main(int argc, char** argv)
{
    cout << "click droit pour demarer une machine, double click pour xterm" << endl;
    QApplication app(argc, argv);

    Fenetre* fen=new Fenetre();

    fen->showMaximized();

    return app.exec();
}
