#ifndef PESSOA_H
#define PESSOA_H

#include <QObject>

class Pessoa : public QObject
{
/*
 * Para fazer uso de properties, a classe precisa herdar QObject
 */
    Q_OBJECT

    Q_PROPERTY(QString nome READ getNome WRITE setNome NOTIFY nomeChanged)
public:
    explicit Pessoa(QObject *parent = nullptr);

    QString getNome() const;

    void setNome(const QString &value);

signals:
    void nomeChanged(const QString &);

private:
    QString nome;
};

#endif // PESSOA_H
