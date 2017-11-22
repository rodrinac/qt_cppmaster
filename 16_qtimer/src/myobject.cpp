#include "myobject.h"

#include <QTime>
#include <QDebug>

MyObject::MyObject(QObject *parent)
    : QObject(parent)
    , timer(new QTimer(this))
{
    connect(timer, SIGNAL(timeout()), this, SLOT(showMessage()));
    timer->start(1000);
	
	//	Exemplo de QTimer::singleShot(); Comente as duas linhas de cima para ver o efeito
	QTimer::singleShot(1000, this, SLOT(showMessage()));	
}

void MyObject::showMessage()
{
#ifdef Q_OS_WIN
    system("cls");
#endif

    qDebug() << "Horário Atual: " << QTime::currentTime().toString();
}
