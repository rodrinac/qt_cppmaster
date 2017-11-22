#include <QtSql>
#include <QDebug>

int main()
{    
    setlocale(LC_ALL, "");
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("alunos");
    db.setUserName("root");

    // para SQLite basta as linhas  7, 11 (Passando o nome [+ diretório]). Ex:
    // db = QSqlDatabase::addDatabase("QSQLITE");
    // db.setDatabaseName("C:/Users/Jose/Desktop/Alunos.db");


    if(db.open())
        qDebug() << "Sucesso ao Abrir a conexão!\n";
    else {
        qDebug() << db.lastError().text();
        return -1;
    }

    // Se ouver apenas um objeto QSqlDatabase, você não precisa
    // setá-lo no construtor da classe QSqlQuery

    QSqlQuery qry("SELECT * FROM dados");

    if(qry.exec()) {
        while(qry.next()) {
                                              // poderia ser também:
            qDebug() << qry.value(0).toInt() // qry.value("id").toInt()
                     << " -- " <<qry.value(1).toString() // qry.value("nome").toString()
                     << " -- " <<qry.value(2).toDouble(); // qry.value("nota").toDouble()
        }
    } else
        qDebug() << "Erro Fatal: " << qry.lastError().text();


    /*
     *	Como fazer pra visualizar diversos resultado
     *  quando não sei se todos tem o mesmo número de colunas
     *  com apenas um bloco de código como o da linha 33-35?
     *  Basta fazer isso:
     *
     *  while(qry.next()) {
     *	int colunmIndex = 0;
     *		QString rowData = qry.value(colunmIndex++).toString();
     *		while(qry.value(colunmIndex).isValid())
     *			rowData += " -- " + qry.value(colunmIndex++).toString();
     *  }
     *
     *	qDebug() << rowData;
     */
}
