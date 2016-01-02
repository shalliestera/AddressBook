#ifndef INFO_H
#define INFO_H

// 保存个人信息的 类
// 名字 和 其他属性
#include <QUrl>
#include <QDataStream>

class Info
{
public:
    Info();
    void init();
    QString fullName() const;
    QUrl avatar() const;	// Url
    QString phone() const;
    QString wechat() const;
    QString QQ() const;
    QUrl web() const;	// Url
    QString address() const;
    QString note() const;
    //friend QDataStream& operator<<(QDataStream &dsout, const Info& info);
    //friend QDataStream& operator>>(QDataStream &dsin, Info& info);

public slots:
    void setFullName(const QString &name);
    void setAvatar(const QUrl &av);
    void setPhone(const QString &ph);
    void setWechat(const QString &we);
    void setQQ(const QString &qq);
    void setWeb(const QUrl &web);
    void setAddress(const QString &addr);
    void setNote(const QString &note);

private:
    // full name;
    QString m_fullName;
    // avatar
    QUrl m_avatar;
    // phone
    QString m_phone;
    // QQ
    QString m_qq;
    // wechat
    QString m_wechat;
    // web
    QUrl m_web;
    // address
    QString m_address;
    // note
    QString m_note;
};

QDataStream& operator <<(QDataStream &dsout, const Info &info);

QDataStream& operator >>(QDataStream &dsin, Info &info);

#endif // INFO_H
