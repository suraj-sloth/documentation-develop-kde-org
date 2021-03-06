/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp Chat.xml -i Message.hpp -a ChatAdaptor
 *
 * qdbusxml2cpp is Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#include "ChatAdaptor.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

/*
 * Implementation of adaptor class ChatAdaptor
 */

ChatAdaptor::ChatAdaptor(QObject *parent)
    : QDBusAbstractAdaptor(parent)
{
    // constructor
    setAutoRelaySignals(true);
}

ChatAdaptor::~ChatAdaptor()
{
    // destructor
}

QStringList ChatAdaptor::users() const
{
    // get the value of property users
    return qvariant_cast< QStringList >(parent()->property("users"));
}

void ChatAdaptor::addUser(const QString &user)
{
    // handle method call demo.Chat.addUser
    QMetaObject::invokeMethod(parent(), "addUser", Q_ARG(QString, user));
}

void ChatAdaptor::removeUser(const QString &user)
{
    // handle method call demo.Chat.removeUser
    QMetaObject::invokeMethod(parent(), "removeUser", Q_ARG(QString, user));
}

void ChatAdaptor::sendMessage(Message message)
{
    // handle method call demo.Chat.sendMessage
    QMetaObject::invokeMethod(parent(), "sendMessage", Q_ARG(Message, message));
}
