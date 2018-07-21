#include "showmain.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ShowMain w;
    w.show();

    return a.exec();
}
