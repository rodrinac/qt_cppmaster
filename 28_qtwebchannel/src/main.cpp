#include <QCoreApplication>
#include <QWebSocketServer>
#include <QWebChannel>
#include <QUrl>
#include <QtDebug>

#include "qt/websocketclientwrapper.h"
#include "qt/websockettransport.h"
#include "servidor.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QWebSocketServer server("Servidor de exemplo WebChannel", QWebSocketServer::NonSecureMode);

    if (! server.listen(QHostAddress::LocalHost, 12345)) {
        qWarning() << "Erro ao abrir WebSocket [" << server.errorString() << ']';
        return -1;
    }

    qInfo() << "Servidor WebSocket rodando em " << server.serverUrl().toString() << endl;

    WebSocketClientWrapper wrapper(&server);

    QWebChannel channel;

    QObject::connect(&wrapper, &WebSocketClientWrapper::clientConnected, &channel, &QWebChannel::connectTo);

    channel.registerObject("servidor", new Servidor(&a));

    return a.exec();
}

