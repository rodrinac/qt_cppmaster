#ifndef HTTPHANDLER_HXX
#define HTTPHANDLER_HXX

#include <QObject>
#include <httpserver/httprequesthandler.h>
#include <templateengine/templatecache.h>

using namespace stefanfrings;

class HttpHandler : public HttpRequestHandler
{
    Q_OBJECT
public:
    explicit HttpHandler(QObject *parent = nullptr);

    ~HttpHandler();

    void service(HttpRequest &request, HttpResponse &response) override;

private:
    TemplateCache *tcache;
};

#endif // HTTPHANDLER_HXX
