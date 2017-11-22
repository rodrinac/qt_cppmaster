#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_Sobre_Qt_triggered()
{
    qApp->aboutQt();
}

void MainWindow::on_action_Abrir_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Abrir Arquivo", QDir::currentPath(),
                                                    "Arquivo de texto (*.txt);; Arquivo HTML (*.html)");
    if(!fileName.isEmpty())
    {
        QFile file(fileName);

        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream stream(&file);
            ui->textEdit->clear();
            ui->textEdit->setText(stream.readAll());
            ui->statusBar->showMessage("Sucesso ao abrir " + file.fileName(), 2000);
        }
        //código extra
        /*
         *  else
         *      ui->statusBar->showMessage("impossível abrir o arquivo " + file.fileName(), 2000);
         */
    }
}

void MainWindow::on_action_salvar_triggered()
{
    QString extensao;

    if(ui->checkBox->isChecked())
        extensao = "/Sem título.html";
    else
        extensao = "/Sem título.txt";

    QString fileName = QFileDialog::getSaveFileName(this, "Salvar Como", QDir::homePath() + extensao,
                                                    "Todos os arquivos (*)");
    if(! fileName.isEmpty()) {
        QFile file(fileName);

        if(file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
        {
            QTextStream stream(&file);

            if(extensao.contains("html"))
             stream <<ui->textEdit->toHtml();
            else
                stream <<ui->textEdit->toPlainText();

            ui->statusBar->showMessage("Sucesso ao salvar " + file.fileName(), 2000);
        }
        //código extra
        /*
         *  else
         *      ui->statusBar->showMessage("impossível salvar o arquivo " + file.fileName(), 2000);
         */
    }
}
