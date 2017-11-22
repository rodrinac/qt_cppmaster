#include "httphandler.h"

HttpHandler::HttpHandler(QObject *parent) : HttpRequestHandler(parent)
{
    qDebug("Servidor Iniciado.");
}

HttpHandler::~HttpHandler()
{
    qDebug("Servidor Finalizado.");
}

void HttpHandler::service(HttpRequest &request, HttpResponse &response)
{
    response.setHeader("Content-Type", "text/html; charset=utf-8");

    auto params = request.getParameterMap();

    response.write("<!DOCTYPE html><html><body><table border=1>"
                   "<tr><th colspan=2>Dados recebidos pelo servidor.</th></td>");

    for(auto it = params.constBegin(); it != params.constEnd(); ++it)
    {
        response.write("<tr><td>" + it.key() + "</td>");
        response.write("<td>"   + it.value() + "</td></tr>");
    }

    response.write("</table></body></html>", true);
}
