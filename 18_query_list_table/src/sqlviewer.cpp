#include "sqlviewer.h"
#include "ui_sqlviewer.h"

SqlViewer::SqlViewer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SqlViewer)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setDatabaseName("atividadedml");

    if(! db.open()) {
        QMessageBox::critical(this, "Erro Fatal", db.lastError().text());
        QTimer::singleShot(1000, qApp, SLOT(quit()));
    } else
        statusBar()->showMessage("Sucesso ao conectar!", 3000);
}

SqlViewer::~SqlViewer()
{
    db.close();
    delete ui;
}

void SqlViewer::setupSatates()
{
    QSqlQuery query("SELECT nome, uf FROM tb_estados");

    states_UFs["Todos"] = "SELECT * FROM tb_cidades";

    if(query.exec()) {
        while(query.next())
            states_UFs[query.value("nome").toString()] = "SELECT * FROM tb_cidades WHERE uf = '"
                    + query.value("uf").toString() + "'";
    } else
        QMessageBox::critical(this, "Erro Fatal", query.lastError().text());

    ui->listWidget->addItems(states_UFs.keys());
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "ID" << "No. Estado" << "UF" << "Nome");
    ui->tableWidget->setEditTriggers(QTableWidget::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QTableWidget::SelectRows);

}

void SqlViewer::updateTable(QString state)
{
    QSqlQuery query(states_UFs[state]);

    if(query.exec()) {
        ui->tableWidget->setRowCount(query.size());
        statusBar()->showMessage(QString("Query Executado com sucesso! Linhas Afetadas: %1").arg(query.size()), 2500);

        int row = 0;

        while(query.next()) {
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("id").toString()));
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("estado").toString()));
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("uf").toString()));
            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("nome").toString()));

            ++row;
        }
    } else
        QMessageBox::critical(this, "Erro Fatal", query.lastError().text());
}

void SqlViewer::on_actionQuit_triggered()
{
    qApp->quit();
}

void SqlViewer::on_actionAbout_Qt_triggered()
{
    qApp->aboutQt();
}

void SqlViewer::on_listWidget_clicked(const QModelIndex &index)
{
    updateTable(index.data().toString());
}
