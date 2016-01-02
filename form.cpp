#include "form.h"
#include "ui_form.h"
#include "info.h"
#include <QDebug>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    //m_mode = AddMode;
}

Form::Form(const Info &info, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    setInfo(info);
    //m_mode = AddMode;
}

Form::~Form()
{
    delete ui;
}

// 获取 info
const Info& Form::info() const
{
    return m_info;
}

Info& Form::info()
{
    return m_info;
}

// 设置所有输入框，方便编辑
void Form::setWidgets()
{
    ui->fullNameEdit->setText(info().fullName());
    ui->phoneEdit->setText(info().phone());
    ui->qqEdit->setText(info().QQ());
    ui->wechatEdit->setText(info().wechat());
    ui->webEdit->setText(info().web().toString());
    ui->addrEdit->setPlainText(info().address());
    ui->noteEdit->setPlainText(info().note());
    ui->tipsLabel->setText(tr(""));	// 备用
    qDebug() << tr("setWidgets()");
}

// 设置私有成员的值
void Form::setInfo(const QString& name, const QUrl &avatar, const QString &phone, const QString &qq, const QString &wechat, const QUrl web, const QString &address, const QString &note)
{
    info().setFullName(name);
    info().setAvatar(avatar);
    info().setPhone(phone);
    info().setQQ(qq);
    info().setWechat(wechat);
    info().setWeb(web);
    info().setAddress(address);
    info().setNote(note);
    qDebug() << tr("setInfo(a lot)");
}

void Form::setInfo(const Info &in)
{
    info().setFullName(in.fullName());
    info().setAvatar(in.avatar());
    info().setPhone(in.phone());
    info().setQQ(in.QQ());
    info().setWechat(in.wechat());
    info().setWeb(in.web());
    info().setAddress(in.address());
    info().setNote(in.note());
    qDebug() << tr("setInfo(const Info&)");
}

// commit 按钮	// 设置info()，发信号，关闭窗体
void Form::on_commitButton_clicked()
{    
    QString fullName, phone, qq, wechat, address, note;
    QUrl avatar, web;
    QString oldFullName = info().fullName(); // 这里逻辑错误了，old 应该是之前的
    fullName = ui->fullNameEdit->text();
    if(!fullName.isEmpty())	// name 不是空字符串
    {
        qDebug() << tr("in con_commitButton_clicked()") << oldFullName << "->" << fullName;
        // 从对应位置取得值
        // avatar = ui->nameEdit->text();	// 未实现
        phone = ui->phoneEdit->text();
        qq = ui->qqEdit->text();
        wechat = ui->qqEdit->text();
        web = ui->webEdit->text();
        address = ui->addrEdit->toPlainText();
        note = ui->noteEdit->toPlainText();
        // 设置私有成员info
        setInfo(fullName, avatar, phone, qq, wechat, web, address, note);
        // 将私有成员作为信号参数发送
        emit commitInfo(oldFullName, info());
        qDebug() << tr("commitInfo -- phone:") << info().phone();
        // 关闭窗体
        close();
    }
    else
    {
        // name 是空字符，不处理
        qDebug() << oldFullName;
        qDebug() << tr("on_commitButton_clicked() 没有处理");
    }
}

// reset 按钮
void Form::on_resetButton_clicked()
{
    // 清空输入框
    ui->fullNameEdit->clear();
    // avatarEdit nai
    ui->phoneEdit->clear();
    ui->qqEdit->clear();
    ui->webEdit->clear();
    ui->webEdit->clear();
    ui->addrEdit->clear();
    ui->noteEdit->clear();
}

// cancel 按钮
void Form::on_cancelButton_clicked()
{
    // 按 cancel ，关闭窗体
    close();
}
