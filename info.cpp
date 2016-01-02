#include "info.h"

Info::Info()
{
    init();
}

void Info::init()
{
    // 初始化为空值;
    m_fullName = m_qq = m_phone = m_note = "";	// QString
    m_web = m_avatar = "http://localhost/";	// QUrl
}

// public，获取成员的各个函数
QString Info::fullName() const
{
    return m_fullName;
}

QUrl Info::avatar() const
{
    return m_avatar;
}

QString Info::phone() const
{
    return m_phone;
}

QString Info::wechat() const
{
    return m_wechat;
}

QString Info::QQ() const
{
    return m_qq;
}

QUrl Info::web() const
{
    return m_web;
}

QString Info::address() const
{
    return m_address;
}

QString Info::note() const
{
    return m_note;
}

// public slots， 槽函数

void Info::setFullName(const QString &name)
{
    m_fullName = name;
}

void Info::setAvatar(const QUrl &av)
{
    m_avatar = av;
}

void Info::setPhone(const QString &ph)
{
    m_phone = ph;
}

void Info::setWechat(const QString &we)
{
    m_wechat = we;
}

void Info::setQQ(const QString &qq)
{
    m_qq = qq;
}

void Info::setWeb(const QUrl &web)
{
    m_web = web;
}

void Info::setAddress(const QString &addr)
{
    m_address = addr;
}

void Info::setNote(const QString &note)
{
    m_note = note;
}

// friend

QDataStream& operator <<(QDataStream &dsout, const Info &info)
{
    dsout << info.fullName() << info.avatar() << info.phone() << info.QQ() << info.wechat() << info.web() << info.address() << info.note();
    return dsout;
}

QDataStream& operator >>(QDataStream &dsin, Info &info)
{
    QString fullName, phone, qq, wechat, address, note;
    QUrl avatar, web;
    dsin >> fullName >> avatar >> phone >> qq >> wechat >> web >> address >> note;

    info.setFullName(fullName);
    info.setAvatar(avatar);
    info.setPhone(phone);
    info.setQQ(qq);
    info.setWechat(wechat);
    info.setWeb(web);
    info.setAddress(address);
    info.setNote(note);

    return dsin;
}
