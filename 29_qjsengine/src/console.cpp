#include "console.h"

#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>

Console::Console(QWidget *parent)
    : QWidget(parent)
    , input(new QLineEdit(this))
    , output(new QTextEdit("<h3>Console Pronto</h3>", this))
{
    QLayout *layout = new QVBoxLayout(this);
    layout->addWidget(output);
    layout->addWidget(input);

    input->setAlignment(Qt::AlignRight);
    input->setPlaceholderText("<Digite Aquí>");
    output->setReadOnly(true);

    connect(input, &QLineEdit::returnPressed, [this] {
        output->append(QString("<font color='red'>></font> %1").arg(input->text()));

        auto result = engine.evaluate(input->text());

        output->append(QString("<i>%1</i><br>").arg(result.toString()));

        input->clear();
    });
}
