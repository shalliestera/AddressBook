#include "addkeyvalue.h"
#include "ui_addkeyvalue.h"

AddKeyValue::AddKeyValue(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddKeyValue)
{
    ui->setupUi(this);
}

AddKeyValue::~AddKeyValue()
{
    delete ui;
}
