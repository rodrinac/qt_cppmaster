#ifndef JANELAPRINCIPAL_H
#define JANELAPRINCIPAL_H

#include <QWidget>
#include <QtDebug>
#include <QMessageBox>
#include "databaseacess.h"

namespace Ui {
class JanelaPrincipal;
}

class JanelaPrincipal : public QWidget
{
    Q_OBJECT

    enum {Menu = 0, Consulta = 3, DadosCliente = 4, Vendas = 2, Cadastro = 1};

public:
    explicit JanelaPrincipal(QWidget *parent = nullptr);
    ~JanelaPrincipal();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_listView_doubleClicked(const QModelIndex &index);

private:
    Ui::JanelaPrincipal *ui;
    DatabaseAcess *dba;

    void carregarDadosCliente(const QString &nome);
};

#endif // JANELAPRINCIPAL_H
