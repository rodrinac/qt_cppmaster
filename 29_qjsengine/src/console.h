#ifndef CONSOLE_H
#define CONSOLE_H

#include <QWidget>
#include <QJSEngine>

class QLineEdit;
class QTextEdit;

class Console : public QWidget
{
    Q_OBJECT
public:
    Console(QWidget *parent = nullptr);

private:
    QLineEdit *input;
    QTextEdit *output;
    QJSEngine engine;
};

#endif // CONSOLE_H
