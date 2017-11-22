#include <QCoreApplication>
#include "myobject.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    setlocale(LC_ALL, "");

    MyObject obj;

    return a.exec();
}
