#include "widget.h"
#include "ui_widget.h"

#include <QtSql>
#include <QtCore>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("pedidos");
    db.setUserName("root");

    if(! db.open())  {
        qDebug() << "Erro Fatal: " << db.lastError().text();

        // expressão lambda, dísponivel compilando como C++11/14.
        // Apartir de Qt5.7.0, O SDK está construído em C++11.
        QTimer::singleShot(2500, [this]() { qApp->quit(); });
    } else
        setupTable();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setupTable()
{
    auto model = new QSqlQueryModel(this);

    model->setQuery("SELECT * FROM produtos");
    ui->tableView->setModel(model);
}

void Widget::on_quitButton_clicked()
{
    qApp->quit();
}
