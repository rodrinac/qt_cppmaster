#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(updateClients(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    bool ok;
    QString name = QInputDialog::getText(this, "Inserir Nome", "Digite o nome do cliente",
                                         QLineEdit::Normal, "José Maria", &ok, Qt::WindowTitleHint);
    if(ok && !name.isEmpty())
        ui->lineEdit->setText(name);
}


void MainWindow::on_pushButton_3_clicked()
{
    bool ok;
    double peso = QInputDialog::getDouble(this, "Inserir peso", "Insira o peso do clinte", 50,
                                          20, 200, 2, &ok);
    if(ok)
        ui->lineEdit_2->setText(QString("%1").arg(peso));
}

void MainWindow::on_pushButton_4_clicked()
{
    bool ok;
    int idade = QInputDialog::getInt(this, "Inserir idade", "Insira a idade do cliente", 20, 15,
                                     130, 1, &ok);
    if(ok)
        ui->lineEdit_3->setText(QString("%1").arg(idade));
}

void MainWindow::on_pushButton_5_clicked()
{
    bool ok;
    QStringList lista;
    lista <<"Homem" <<"Mulher";

    QString sexo = QInputDialog::getItem(this, "Inserir sexo", "Selecione o sexo do cliente",
                                         lista, 0, false, &ok);
    if(ok && !sexo.isEmpty())
        ui->lineEdit_4->setText(sexo);
}

void MainWindow::updateClients(bool)
{
    using namespace std;
    ifstream fin("C:\\Users\\Jose\\Desktop\\clientes.txt");    
    char temp;
    QByteArray buffer;

    while(fin.get(temp))
        buffer.push_back(temp);

    ui->textEdit->setText(QString::fromUtf8(buffer));
}

void MainWindow::on_pushButton_7_clicked()
{
    if(ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty() ||
            ui->lineEdit_3->text().isEmpty() || ui->lineEdit_4->text().isEmpty())
        return;

    using namespace std;
    ofstream fout("C:\\Users\\Jose\\Desktop\\clientes.txt", ios::app);

    fout << ui->lineEdit->text().toStdString()   << endl;
    fout << ui->lineEdit_2->text().toStdString() << endl;
    fout << ui->lineEdit_3->text().toStdString() << endl;
    fout << ui->lineEdit_4->text().toStdString() << endl;

    fout <<" ---- " <<endl;

    updateClients(true);
}

void MainWindow::on_pushButton_6_clicked()
{
    qApp->quit();
}
