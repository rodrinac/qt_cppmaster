#include "myobject.h"

void test()
{
    QObject obj;
    MyObject* ptr = new MyObject(&obj);
}

int main()
{
    setlocale(LC_ALL, "");

    test();

    qDebug("\n====================\n");
}
