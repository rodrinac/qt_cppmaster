#include "janelaprincipal.h"
#include "ui_janelaprincipal.h"

JanelaPrincipal::JanelaPrincipal(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::JanelaPrincipal)
    , dba(new DatabaseAcess(this))
{
    ui->setupUi(this);

    if(! dba->ok()) qApp->exit(-1);

    ui->stackedWidget->setCurrentIndex(Menu);

    ui->listView->setModel(new QSqlQueryModel(this));
    ui->tabelaVendas->setModel(new QSqlQueryModel(this));
    ui->tabelaClientes->setModel(new QSqlQueryModel(this));
    ui->tabelaVendasClientes->setModel(new QSqlQueryModel(this));
}

JanelaPrincipal::~JanelaPrincipal()
{
    delete ui;
}

void JanelaPrincipal::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(Menu);
}

void JanelaPrincipal::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(Cadastro);
}

void JanelaPrincipal::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(Vendas);

    dba->setupTableVendas(qobject_cast<QSqlQueryModel *>(ui->tabelaVendas->model()));
}

void JanelaPrincipal::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(Consulta);

    dba->setupModel(qobject_cast<QSqlQueryModel *>(ui->listView->model()));
}

void JanelaPrincipal::on_pushButton_5_clicked()
{
    QString nome = ui->campoNome->text();
    QString endereco = ui->campoEndereco->text();
    QString telefone = ui->campoTelefone->text();

    if(dba->cadastrarCliente(nome, endereco, telefone))
        QMessageBox::information(this, "Cadastro de Cliente", "Sucesso ao cadastrar");
    else
        QMessageBox::warning(this, "Cadastro de Cliente", "falha ao cadastrar");
}

void JanelaPrincipal::on_pushButton_6_clicked()
{
    QString nome = ui->campoBuscarClienteNome->text();

    if(dba->clienteExiste(nome)) {
        ui->stackedWidget->setCurrentIndex(DadosCliente);
        carregarDadosCliente(nome);
    } else
        QMessageBox::warning(this, "Busca de Cliente", "falha ao encontrar este cliente");
}

void JanelaPrincipal::carregarDadosCliente(const QString &nome)
{
    dba->carregarDadosCliente(nome, qobject_cast<QSqlQueryModel *>(ui->tabelaClientes->model()),
                                    qobject_cast<QSqlQueryModel *>(ui->tabelaVendasClientes->model()));
}

void JanelaPrincipal::on_listView_doubleClicked(const QModelIndex &index)
{
    ui->stackedWidget->setCurrentIndex(DadosCliente);
    carregarDadosCliente(index.data().toString());
}
