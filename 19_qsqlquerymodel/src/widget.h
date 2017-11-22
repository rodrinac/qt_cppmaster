#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlDatabase>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void setupTable();

private slots:
    void on_quitButton_clicked();

private:
    Ui::Widget *ui;
    QSqlDatabase db;
};

#endif // WIDGET_H
