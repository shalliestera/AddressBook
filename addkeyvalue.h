#ifndef ADDKEYVALUE_H
#define ADDKEYVALUE_H

#include <QWidget>

namespace Ui {
class AddKeyValue;
}

class AddKeyValue : public QWidget
{
    Q_OBJECT

public:
    explicit AddKeyValue(QWidget *parent = 0);
    ~AddKeyValue();

private:
    Ui::AddKeyValue *ui;
};

#endif // ADDKEYVALUE_H
