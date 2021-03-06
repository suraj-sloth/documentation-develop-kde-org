/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp Chat.xml -i Message.hpp -a ChatAdaptor
 *
 * qdbusxml2cpp is Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#ifndef CHATADAPTOR_H_1270658274
#define CHATADAPTOR_H_1270658274

#include <QtCore/QObject>
#include <QtDBus/QtDBus>
#include "Message.hpp"
class QByteArray;
template<class T> class QList;
template<class Key, class Value> class QMap;
class QString;
class QStringList;
class QVariant;

/*
 * Adaptor class for interface demo.Chat
 */
class ChatAdaptor: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "demo.Chat")
    Q_CLASSINFO("D-Bus Introspection", ""
"  <interface name=\"demo.Chat\">\n"
"    <property access=\"read\" type=\"as\" name=\"users\"/>\n"
"    <signal name=\"userAdded\">\n"
"      <arg direction=\"out\" type=\"s\" name=\"user\"/>\n"
"    </signal>\n"
"    <signal name=\"userRemoved\">\n"
"      <arg direction=\"out\" type=\"s\" name=\"user\"/>\n"
"    </signal>\n"
"    <signal name=\"messageSent\">\n"
"      <arg direction=\"out\" type=\"a(ii)\" name=\"message\"/>\n"
"      <!-- to support also Qt < 5.6.3 & 5.7.0, use instead org.qtproject.QtDBus.QtTypeName.In0 -->\n"
"      <annotation value=\"Message\" name=\"com.trolltech.QtDBus.QtTypeName.Out0\"/>\n"
"    </signal>\n"
"    <method name=\"addUser\">\n"
"      <arg direction=\"in\" type=\"s\" name=\"user\"/>\n"
"    </method>\n"
"    <method name=\"removeUser\">\n"
"      <arg direction=\"in\" type=\"s\" name=\"user\"/>\n"
"    </method>\n"
"    <method name=\"sendMessage\">\n"
"      <arg direction=\"in\" type=\"a(ii)\" name=\"message\"/>\n"
"      <annotation value=\"Message\" name=\"com.trolltech.QtDBus.QtTypeName.In0\"/>\n"
"    </method>\n"
"  </interface>\n"
        "")
public:
    ChatAdaptor(QObject *parent);
    virtual ~ChatAdaptor();

public: // PROPERTIES
    Q_PROPERTY(QStringList users READ users)
    QStringList users() const;

public Q_SLOTS: // METHODS
    void addUser(const QString &user);
    void removeUser(const QString &user);
    void sendMessage(Message message);
Q_SIGNALS: // SIGNALS
    void messageSent(Message message);
    void userAdded(const QString &user);
    void userRemoved(const QString &user);
};

#endif
