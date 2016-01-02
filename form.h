#ifndef FORM_H
#define FORM_H

// 构造一个Info数据，通过信号交给主窗体

#include <QWidget>
#include <QUrl>
#include "info.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    //enum Mode{AddMode, EditMode};
    explicit Form(QWidget *parent = 0);
    explicit Form(const Info &info, QWidget *parent = 0);	// 用 info 构造，方便编辑
    ~Form();
    // 返回私有成员 info
    const Info& info() const;
    Info& info();
signals:
    void commitInfo(const QString &oldFullName, const Info &info);	// 信号，提交构造好的Info

public slots:
    void setWidgets();	// 设置所有输入框的内容，以方便编辑
    // setInfo 的 2种方法
    void setInfo(const Info &info);
    void setInfo(const QString& fullName, const QUrl &avatar, const QString &phone, const QString &qq, const QString &wechat, const QUrl web, const QString &address, const QString &note);

private slots:	// 槽函数
    void on_commitButton_clicked();

    void on_resetButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::Form *ui;
    Info m_info;	// 这个成员用来保存编辑好的数据
    //Mode m_mode;
};

#endif // FORM_H
