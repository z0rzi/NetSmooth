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

int Selection::m_enSelection = 0;

void chld_handler(int s)
{
    int ho;
    while(waitpid(0,&ho,WNOHANG)>0);
}

int main(int argc, char** argv)
{
    struct sigaction sa;
    sa.sa_handler=chld_handler;
    sa.sa_flags=SA_RESTART;
    sigemptyset(&sa.sa_mask);


    sigaction(SIGCHLD, &sa, NULL);


    QApplication app(argc, argv);

    Fenetre* fen=new Fenetre();

    fen->showMaximized();

    return app.exec();
}
