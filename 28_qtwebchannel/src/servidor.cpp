#include "servidor.h"

Servidor::Servidor(QObject *parent) : QObject(parent)
{
    setItens({"Óculos", "Luvas", "Sapatos"});
}

QStringList Servidor::itens() const
{
    return m_itens;
}

void Servidor::setItens(const QStringList &itens)
{
    m_itens = itens;

    emit itensChanged();
}

bool Servidor::adicionarItem(const QString &item)
{
    if (! m_itens.contains(item, Qt::CaseInsensitive)) {
        m_itens.append(item);

        emit itensChanged();

       return true;
    }

    return false;
}

void Servidor::removerItem(const QString &item)
{
    m_itens.removeOne(item);

    emit itensChanged();
}
