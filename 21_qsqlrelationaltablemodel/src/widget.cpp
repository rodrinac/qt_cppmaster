#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    // Auto dedução de tipo. C++11/14
    auto quitButton  = new QPushButton("Sair", this);
    auto layout      = new QVBoxLayout(this);

    layout->addWidget(&view);
    layout->addWidget(quitButton, 0, Qt::AlignHCenter);
    view.setAlternatingRowColors(true);

    // Lambda. C++11/14
    connect(quitButton, &QPushButton::clicked, [this]() { qApp->quit(); });

    if(! initDB()) {
        QMessageBox::critical(this, "Erro no BD", db.lastError().text(), QMessageBox::Cancel);
        qApp->exit(-1);
    } else
        setupView();
}

/**
	fecha a conexão com Banco de dados MySql
**/
Widget::~Widget()
{
    db.close();
}

/**
	Cria conexão com Banco de dados MySql
**/
bool Widget::initDB()
{
    db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("empresa");

    return db.open();
}

/**
	Configura o QTableView  e o modelo
**/
void Widget::setupView()
{
    auto model = new QSqlRelationalTableModel(this, db);

    model->setTable("funcionario");
    model->setRelation(2, QSqlRelation("departamento", "id", "nome"));

    model->setHeaderData(0, Qt::Horizontal,           "ID");
    model->setHeaderData(1, Qt::Horizontal,         "Nome");
    model->setHeaderData(2, Qt::Horizontal, "Departamento");    

    model->select();

    view.setSizeAdjustPolicy(QTableView::AdjustToContents);
    view.setModel(model);
    view.setItemDelegate(new QSqlRelationalDelegate(&view));
}
