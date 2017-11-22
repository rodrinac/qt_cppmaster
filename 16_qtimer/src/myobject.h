#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>
#include <QTimer>

class MyObject : public QObject
{
    Q_OBJECT
public:
    explicit MyObject(QObject *parent = 0);

private slots:
    void showMessage();

private:
    QTimer *timer;
};

#endif // MYOBJECT_H
