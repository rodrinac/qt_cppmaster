#ifndef SQLVIEWER_H
#define SQLVIEWER_H

#include <QtWidgets>
#include <QtSql>
#include <QtCore>

namespace Ui {
class SqlViewer;
}

class SqlViewer : public QMainWindow
{
    Q_OBJECT

public:
    explicit SqlViewer(QWidget *parent = nullptr);
    ~SqlViewer();

    void setupSatates();

    void updateTable(QString state);

private slots:
    void on_actionQuit_triggered();

    void on_actionAbout_Qt_triggered();

    void on_listWidget_clicked(const QModelIndex &index);

private:
    Ui::SqlViewer *ui;
    QMap<QString, QString> states_UFs;
    QSqlDatabase db;
};

#endif // SQLVIEWER_H
