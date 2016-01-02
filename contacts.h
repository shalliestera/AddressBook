#ifndef CONTACTS_H
#define CONTACTS_H

// 保存一个人的数据 的类
// 基于 QMap<QString, Info>
// Info 是另一个自定义类
#include <QMap>
#include <info.h>	// class Info;

typedef QMap<QString, Info> Contacts;

#endif // CONTACTS_H
