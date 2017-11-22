#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include <QtDebug>

void writeJSON(QFile &f1, QFile &f2)
{
    QJsonArray jsarray {
        QJsonObject {{"id", 1}, {"nome", "Maria"}, {"senha", "256@986"}},
        QJsonObject {{"id", 2}, {"nome", "Lucas"}, {"senha", "298@457"}}
    };

    QJsonDocument jsdoc(jsarray);

    f1.write(jsdoc.toJson());
    f2.write(jsdoc.toBinaryData());
}

void readJSON(QFile &f1, QFile &f2)
{
    setlocale(LC_ALL, "");
    QJsonDocument jsdoc1 = QJsonDocument::fromJson(f1.readAll());
    QJsonDocument jsdoc2 = QJsonDocument::fromBinaryData(f2.readAll());

    qDebug() << "Arquivo de text: " << jsdoc1.array() << endl;
    qDebug() << "Arquivo binário: " << jsdoc2.array() << endl;
}

int main()
{  
    QFile f1("C:/Users/Jose/Desktop/array.json");
    QFile f2("C:/Users/Jose/Desktop/array.dat");

//  Escreve:
    Q_ASSERT(f1.open(QFile::WriteOnly));
    Q_ASSERT(f2.open(QFile::WriteOnly));
    writeJSON(f1, f2);
    f1.close();
    f2.close();

//  Lê:
    Q_ASSERT(f1.open(QFile::ReadOnly));
    Q_ASSERT(f2.open(QFile::ReadOnly));
    readJSON(f1, f2);
    f1.close();
    f2.close();

//  Fim.
}
