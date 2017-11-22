#include "pessoa.h"

Pessoa::Pessoa(QObject *parent) : QObject(parent)
{

}

QString Pessoa::getNome() const
{
    return nome;
}

void Pessoa::setNome(const QString &value)
{
    nome = value;

    emit nomeChanged(nome);
}
