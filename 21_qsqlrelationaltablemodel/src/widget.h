#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>
#include <QtSql>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QSqlDatabase db;
    QTableView view;

    bool initDB();
    void setupView();
};

#endif // WIDGET_H
