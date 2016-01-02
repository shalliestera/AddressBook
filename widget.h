#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMultiMap>
#include <QDataStream>
#include "contacts.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    Contacts& contacts();
    QString fileName();
    // 保存到文件
    void saveToFile();
    void loadFromFile();

signals:
    void search(QString);
    void fileNameChanged(QString);	// 文件名改变
    void sendInfo(Info);

private slots:
    void setRightHandSide(const Info &info);

    void on_commitInfo(const QString &oldKey, const Info &info);

    //void on_removeKey(QString key);

    void setFileName(const QString &);

    void on_searchEdit_textChanged(const QString &arg1);

    void on_resetButton_clicked();

    void on_saveButton_clicked();

    void on_loadButton_clicked();

    void on_editButton_clicked();

    void on_addButton_clicked();

private:
    Ui::Widget *ui;
    Contacts m_contacts;
    QString m_fileName;
};

#endif // WIDGET_H
