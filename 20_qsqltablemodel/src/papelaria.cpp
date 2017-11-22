#include "papelaria.h"
#include "ui_papelaria.h"

Papelaria::Papelaria(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Papelaria)
{
    ui->setupUi(this);

    /*
     *   Cria conexão com banco de dados sqlite.
     *----
     *   OBS..: enqunto rodando o app pela IDE,
     *   ele será iniciado um diretório acima.
     *   Ex:
     *                                        Será executado aqui       | mas ele está
     *                                               1                  | aqui   2
     *   [...\Rascunhos\build-Aula20-Desktop_Qt_5_7_0_MinGW_32bit-Release\]release\
     *
     *   Neste caso você deve por o .db neste diretório (1).
     *   Você podo alterar esse comportamento em
     *   Projects -> Build | (Run) -> Working Directory.
     *
     */
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Papelaria.db");

    // tenta abrir conexão
    if(! db.open()) {
        QMessageBox::critical(this, "Erro no Banco de Dados", db.lastError().text(),  QMessageBox::Cancel);
        qApp->exit(-1);
    } else {
        // seta o objeto modelo
        QSqlTableModel *model = new QSqlTableModel(this, db);

        // seta a tabela
        model->setTable("empregado");
        ui->tableView->setModel(model);

        // seleciona os dados da tabela
        model->select();
    }
}

Papelaria::~Papelaria()
{
    delete ui;
}

// Botão "Inserir"
void Papelaria::on_pushButton_2_clicked()
{
    if(ui->spinBox->text().isEmpty() || ui->lineEdit->text().isEmpty()
            || ui->doubleSpinBox->text().isEmpty())
        QMessageBox::warning(this, "Atenção", "Dados Inválidos!");
    else
    {    
#define BIND_WITH_INDEX
#ifdef BIND_WITH_INDEX
        QSqlQuery qry("INSERT INTO empregado VALUES (?, ?, ?)", db);

        qry.bindValue(0, ui->spinBox->value());
        qry.bindValue(1, ui->lineEdit->text());
        qry.bindValue(2, ui->doubleSpinBox->value());
#else
        QSqlQuery qry("INSERT INTO empregado values(:id, :nome, :salario)", db);

        qry.bindValue(":id", ui->spinBox->value());
        qry.bindValue(":nome", ui->lineEdit->text());
        qry.bindValue(":salario", ui->doubleSpinBox->value());
#endif
       if(qry.exec())
           QMessageBox::information(this, "Sucesso", "Query executado com sucesso!");
       else
           QMessageBox::warning(this, "Fracasso", "Query fracassou:<br><b>" + qry.lastError().text());
    }

    // atualiza a tabela
    // OBS..: qobject_cast<R *>(T *) faz casts entre classes herdeiras de QOject
    qobject_cast<QSqlTableModel *>(ui->tableView->model())->select();
}


// seta um ID aleatório
void Papelaria::on_pushButton_clicked()
{
    ui->spinBox->setValue(getRandomID());
}

// obtem um número aleatório de 1000 até 9999
unsigned int Papelaria::getRandomID() const
{
    static RandomEngine eng(std::time(nullptr));
    static Random rnd(1000, 9999);

    return rnd(eng);
}

void Papelaria::on_pushButton_3_clicked()
{
    qApp->quit();
}

void Papelaria::on_pushButton_4_clicked()
{
    qApp->aboutQt();
}
