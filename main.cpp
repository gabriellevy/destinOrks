#include "orks.h"
#include <QApplication>
#include "orks.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Orks* av = new Orks(eh_VieDUnMekano);
    av->show();

    return a.exec();
}
