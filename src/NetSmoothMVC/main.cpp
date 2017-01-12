#include <QApplication>
#include "vues/fenetre.h"
#include "vues/selection.h"

int Selection::m_enSelection = 0;

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    cout << "click droit pour demarer une machine, double click pour xterm" << endl;

    Fenetre* fen = new Fenetre();
    fen->showMaximized();

    return app.exec();
}
