#include "widget.h"
#include "ui_widget.h"
#include "contacts.h"
#include "form.h"	// 用来添加联系人的窗体
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QDataStream>
#include <QFile>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 文件名改变时 和 底部标签 绑定
    QObject::connect(this, SIGNAL(fileNameChanged(QString)), ui->fileNameLabel, SLOT(setText(QString)));

    ui->fileNameLabel->setText(tr("没有打开任何文件"));

}

Widget::~Widget()
{
    delete ui;
}

Contacts& Widget::contacts()
{
    return m_contacts;
}

QString Widget::fileName()
{
    return m_fileName;
}

// 设置 文件名，存取文件时
void Widget::setFileName(const QString &fileName)
{
    m_fileName = fileName;
    emit fileNameChanged(fileName);
}

// 设置右半边的所有部件
void Widget::setRightHandSide(const Info &info)
{
    ui->displayName->setText(info.fullName());
    ui->fileNameLabel->setText(fileName());
    // 全名，电话，qq，微信，网页，地址，备注
    ui->fullNameLabel->setText(info.fullName());
    ui->phoneEdit->setText(info.phone());
    ui->qqEdit->setText(info.QQ());
    ui->wechatEdit->setText(info.wechat());
    ui->webEdit->setText(info.web().toString());
    ui->addrPlain->setPlainText(info.address());
    ui->notePlain->setPlainText(info.note());
}

// add 按钮
void Widget::on_addButton_clicked()
{
    // 打开 添加新项目的窗口，并置顶。
    Form *fm = new Form(NULL);
    fm->setWindowModality(Qt::ApplicationModal);
    fm->setWindowTitle(tr("添加联系人"));
    fm->show();
    // 关联 fm 的信号 和 主窗体的 槽，传递 info用
    QObject::connect(fm, SIGNAL(commitInfo(QString, Info)), this, SLOT(on_commitInfo(QString,Info)));
}

// 接收 添加联系人 窗体发出的信号，将info插入contacts里。
void Widget::on_commitInfo(const QString &oldKey, const Info &info)
{
    QMessageBox::information(NULL, tr("debug"), tr("姓名：") + info.fullName());
    // 把 info 的信息 插入 contacts，先删，再插入
    contacts().remove(oldKey);
    contacts().insert(info.fullName(), info);
    qDebug() << tr("on_commitInfo(cQString, cInfo") << info.phone();
}

// reset 按钮
void Widget::on_resetButton_clicked()
{
    // 清空搜索框
    ui->searchEdit->clear();
}

// 搜索框，文字变化时
void Widget::on_searchEdit_textChanged(const QString &arg1)
{
    // 获取文本, 搜索名，搜索姓。如果有名字相符的，显示在右边
    QString name = ui->searchEdit->text();

    if(!name.isEmpty())	// 检查是不是空的，如果不是
    {
        Info info = contacts().value(name);	// 在contacts里查找key为name的值
        if(!info.fullName().isEmpty())	// 检查返回的结果中，name是不是空的，如果不是
        {
            // 在右边显示  // 名，姓，其他信息
            setRightHandSide(info);
        } // **if(!info.name().isEmpty())
    }
    else{
        // 空字符串，不处理
    } // **if(!name.isEmpty())
}

// 加载 按钮
void Widget::on_loadButton_clicked()
{
    loadFromFile();
}

// 保存 按钮
void Widget::on_saveButton_clicked()
{
    // 保存到文件
    QString dstFileName = fileName();
    if(dstFileName.isEmpty())
    {
        // 空文件名，不处理
        QMessageBox::information(NULL, tr("空文件名"), tr("文件名是空字符串"));
    }
    else
    {
        // 保存到文件
        QMessageBox::information(NULL, tr("保存"), tr("保存功能"));
        saveToFile();
    }
}

// 编辑 按钮
void Widget::on_editButton_clicked()
{
    // 获取本页的fullName
    QString fullName = ui->fullNameLabel->text();
    // 弹出修改用的窗体，借用add
    Form *fm = new Form(contacts().value(fullName));
    fm->setWidgets();
    fm->setWindowModality(Qt::ApplicationModal);
    fm->setWindowTitle(tr("编辑联系人"));
    // 关联信号
    QObject::connect(fm, SIGNAL(commitInfo(QString, Info)), this, SLOT(on_commitInfo(QString,Info)));
    fm->show();
    qDebug() << tr("on_editButton_clicked()");
}

// 文件读写
void Widget::saveToFile()
{
    qDebug() << tr("进入了 saveToFile()");
    // 首先尝试打开 fileName
    //QString srcFileName = QFileDialog::getSaveFileName(this,tr("保存"), tr("."), tr("Binary files(*.dat);;All files(*)"));
    QFile fileOut(fileName());	// 尝试打开文件
    if(fileName().isEmpty() || !fileOut.open(QIODevice::WriteOnly))
    {
        // 文件名为空
        qDebug() << tr("文件名为空 或者 文件无法写入");
        return;
    }
    // 构造输入流
    QDataStream dsOut(&fileOut);
    // 设置流 版本
    dsOut.setVersion(QDataStream::Qt_5_5);

    dsOut << contacts();
    // 似乎写入了？
}

void Widget::loadFromFile()
{
    // 获取文件名
    QString srcFileName = QFileDialog::getOpenFileName(this, tr("打开文件"), tr("."), tr("Binary files(*.dat);;All files(*)"));

    // 文件对象
    QFile fileIn(srcFileName);
    // 打开
    if(!fileIn.open(QIODevice::ReadOnly))
    {
        // 打开失败
        QMessageBox::warning(this, tr("打开文件失败"), tr("打开文件失败了：") + fileIn.errorString());
        return;
    }
    // 构造输入数据流
    QDataStream dsIn(&fileIn);
    // 设置流的版本
    dsIn.setVersion(QDataStream::Qt_5_5);
    // 读取
    dsIn >> contacts();
    // 保存文件名
    setFileName(srcFileName);
    // 报告
    QMessageBox::information(this, tr("成功"), tr("数据读取成功"));
}
