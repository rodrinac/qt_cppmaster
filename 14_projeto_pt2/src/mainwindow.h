#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTextStream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_Sobre_Qt_triggered();

    void on_action_Abrir_triggered();

    void on_action_salvar_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
