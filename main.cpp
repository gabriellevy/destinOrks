#include "orks.h"
#include <QApplication>
#include "orks.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Orks* av = new Orks(eh_VieDUnMekano, ModeAffichage::ema_Jeu);
    av->show();

    return a.exec();
}
