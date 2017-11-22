#include "databaseacess.h"

DatabaseAcess::DatabaseAcess(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("localhost");
    db.setUserName("root");
    db.setDatabaseName("a3ltp2");

    if(! db.open())
        qWarning(qPrintable(db.lastError().text()));
}

void DatabaseAcess::setupModel(QSqlQueryModel *model)
{
    model->setQuery("SELECT nome FROM cliente", db);
}

void DatabaseAcess::setupTableVendas(QSqlQueryModel *model)
{
    model->setQuery("SELECT venda.ID, cliente.nome, vendedor.nome  "
                    "FROM venda JOIN cliente ON id_cliente = cliente.id "
                    "JOIN vendedor ON id_vendedor = vendedor.id ", db);

    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Nome Cliente");
    model->setHeaderData(2, Qt::Horizontal, "Nome Vendedor");
}

bool DatabaseAcess::clienteExiste(QString nome)
{
    QSqlQuery query("SELECT nome FROM cliente WHERE nome = ?", db);

    query.bindValue(0, nome);

    return query.exec() ? query.next() : false;
}

bool DatabaseAcess::cadastrarCliente(const QString &nome, const QString &endereco, const QString &telefone)
{
    QSqlQuery query("INSERT INTO cliente VALUES(NULL, ?, ?, ?)", db);

    query.bindValue(0, nome);
    query.bindValue(1, endereco);
    query.bindValue(2, telefone);

    return query.exec();
}

void DatabaseAcess::carregarDadosCliente(const QString &nome, QSqlQueryModel *modelCliente, QSqlQueryModel *modelVenda)
{
    modelCliente->setQuery("SELECT * FROM cliente WHERE nome ='" + nome + "'", db);
    modelVenda->setQuery("SELECT venda.ID, cliente.nome, vendedor.nome  "
                         "FROM venda JOIN cliente ON id_cliente = cliente.id "
                         "JOIN vendedor ON id_vendedor = vendedor.id WHERE cliente.nome ='" + nome + "'", db);
}
