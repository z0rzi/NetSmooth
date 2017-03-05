#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

#include "vues/selection.h"
#include "vues/vueprincipale.h"
#include "vues/vueinformation.h"
#include "controleurs/vueinformationcontroleur.h"
#include "vues/fenetre.h"

int Selection::m_enSelection = SOURIS;

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    Fenetre* fen=new Fenetre();

    fen->showMaximized();

    return app.exec();
}
