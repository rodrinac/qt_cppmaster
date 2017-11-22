#ifndef DATABASEACESS_H
#define DATABASEACESS_H

#include <QObject>
#include <QtSql>

class DatabaseAcess : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseAcess(QObject *parent = nullptr);

    void setupModel(QSqlQueryModel *model);

    void setupTableVendas(QSqlQueryModel *model);

    bool clienteExiste(QString nome);

    bool cadastrarCliente(const QString &nome, const QString &endereco, const QString &telefone);

    bool ok() const {return db.isOpen();}

    void carregarDadosCliente(const QString &nome, QSqlQueryModel *modelCliente, QSqlQueryModel *modelVenda);

private:
   QSqlDatabase db;
};

#endif // DATABASEACESS_H
