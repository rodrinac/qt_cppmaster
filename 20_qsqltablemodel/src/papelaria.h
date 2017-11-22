#ifndef PAPELARIA_H
#define PAPELARIA_H

#include <QtWidgets>
#include <QtSql>
#include <random>
#include <chrono>

// cria aliases para alguns nome
// o mesmo efeito de typedef, só que melhor,
// funciona em objetos epossibilita usar templates
using RandomEngine = std::default_random_engine;
using Random = std::uniform_int_distribution<int>;

namespace Ui {
class Papelaria;
}

class Papelaria : public QWidget
{
    Q_OBJECT

public:
    explicit Papelaria(QWidget *parent = nullptr);
    ~Papelaria();

    unsigned int getRandomID() const;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Papelaria *ui;
    QSqlDatabase db;
};

#endif // PAPELARIA_H
