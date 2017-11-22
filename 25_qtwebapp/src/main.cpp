#include <QCoreApplication>
#include <QTime>
#include <iostream>
#include <httpserver/httplistener.h>
#include "httphandler.h"

void messageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    QByteArray time     = QTime::currentTime().toString("[hh:mm:ss] ").toLocal8Bit();

    if(type == QtMsgType::QtCriticalMsg || type == QtMsgType::QtFatalMsg)
        std::cerr << time.constData() << localMsg.constData() << std::endl;
    else
        std::cout << time.constData() << localMsg.constData() << std::endl;

    Q_UNUSED(context)
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);    
    qInstallMessageHandler(&messageOutput);

    qDebug("App iniciado. Usando QtWebApi v%s\n", getQtWebAppLibVersion());

                                        // ↓ Lembre-se de alterar este diretório
    QSettings *settings = new QSettings("C:/cpplibs/servidor.ini", QSettings::IniFormat, &a);
    settings->beginGroup("listener");

    new HttpListener(settings, new HttpHandler(&a), &a);

    return a.exec();
}

