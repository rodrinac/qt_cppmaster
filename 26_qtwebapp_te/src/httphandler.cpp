#include "httphandler.h"

HttpHandler::HttpHandler(QObject *parent) : HttpRequestHandler(parent)
{
    auto settings = new QSettings("D:/Programming/servidor.ini", QSettings::IniFormat, this);
    settings->beginGroup("templates");
    tcache = new TemplateCache(settings, this);

    qDebug("Servidor Iniciado.");
}

HttpHandler::~HttpHandler()
{
    qDebug("Servidor Finalizado.");
}

void HttpHandler::service(HttpRequest &request, HttpResponse &response)
{
    Template tp = tcache->getTemplate("demo", request.getHeader("Accept-Language"));
    auto params = request.getParameterMap();
    int nparams = params.size();

    response.setHeader("Content-Type", "text/html; charset=utf-8");    

    tp.setVariable("param", QString::number(nparams));
    tp.loop("data", nparams);

    int i = 0;
    for(auto it = params.constBegin(); it != params.constEnd(); ++it, ++i)
    {
        tp.setVariable(QString("data%1.key").arg(i), it.key());
        tp.setVariable(QString("data%1.value").arg(i), it.value());
    }

    response.write(tp.toUtf8(), true);
}
