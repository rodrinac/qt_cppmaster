#include "widget.h"
#include "ui_form.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form())
{
   ui->setupUi(this);

   setWindowTitle(tr("%1 Application").arg("i18n"));
}

Widget::~Widget() { delete ui; }
