#include "widget.h"
#include <QApplication>
#include <QtDebug>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;

// Forma A
    if (translator.load(QLocale(), "i18n", ".", "translations"))
        a.installTranslator(&translator);
// Forma B
    if (translator.load("i18n." + QLocale().name(), "translations"))
        a.installTranslator(&translator);

    Widget w;
    w.show();

    qDebug() << qApp->translate("Main", "Application Started");

    return a.exec();
}
