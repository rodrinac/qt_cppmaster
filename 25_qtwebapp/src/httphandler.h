#ifndef HTTPHANDLER_HXX
#define HTTPHANDLER_HXX

#include <QObject>
#include <httpserver/httprequesthandler.h>

using namespace stefanfrings;

class HttpHandler : public HttpRequestHandler
{
    Q_OBJECT
public:
    explicit HttpHandler(QObject *parent = nullptr);

    ~HttpHandler();

    // HttpRequestHandler interface
public:
    void service(HttpRequest &request, HttpResponse &response) override;
};

#endif // HTTPHANDLER_HXX
