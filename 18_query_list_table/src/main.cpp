#include "sqlviewer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SqlViewer viewer;
    viewer.show();
    viewer.setupSatates();

    return a.exec();
}
