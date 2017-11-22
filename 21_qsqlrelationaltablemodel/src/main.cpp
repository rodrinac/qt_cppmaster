#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle(QStyleFactory::create("Fusion"));

    Widget w;

    w.setWindowFlags(Qt::WindowTitleHint | Qt::WindowMinimizeButtonHint);
    w.setWindowTitle("C++ em Qt - Aula 21");
    w.show();

    return a.exec();
}
