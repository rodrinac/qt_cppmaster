#ifndef SERVIDOR_HPP
#define SERVIDOR_HPP

#include <QObject>

class Servidor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList itens READ itens WRITE setItens NOTIFY itensChanged)
public:
    explicit Servidor(QObject *parent = nullptr);

    QStringList itens() const;
    void setItens(const QStringList &itens);

    Q_INVOKABLE bool adicionarItem(const QString &item);
    Q_INVOKABLE void removerItem(const QString &item);

signals:
    void itensChanged();

private:
    QStringList m_itens;
};

#endif // SERVIDOR_HPP
