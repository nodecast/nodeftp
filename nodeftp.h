/****************************************************************************
**   nodeftp is the nodecast ftp server
**   Copyright (C) 2010-2013  Frédéric Logier <frederic@logier.org>
**
**   https://github.com/nodecast/nodeftp
**
**   This program is free software: you can redistribute it and/or modify
**   it under the terms of the GNU Affero General Public License as
**   published by the Free Software Foundation, either version 3 of the
**   License, or (at your option) any later version.
**
**   This program is distributed in the hope that it will be useful,
**   but WITHOUT ANY WARRANTY; without even the implied warranty of
**   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**   GNU Affero General Public License for more details.
**
**   You should have received a copy of the GNU Affero General Public License
**   along with this program.  If not, see <http://www.gnu.org/licenses/>.
****************************************************************************/

#ifndef NODEFTP_H
#define NODEFTP_H

#include "CFtpServer.h"
#include <QObject>
#include <QDir>
#include <QCryptographicHash>
#include <QSocketNotifier>
#include <QxtJSON>
#include <QTextStream>
#include <QDebug>
#include <iostream>

class Nodeftp : public QObject
{
    Q_OBJECT
public:
    Nodeftp(QString a_directory, int port, QString a_passive_ip);
    ~Nodeftp();

private:
    void writeStdout(QString s);
    bool add_user(QString email, QString password, QString path);
    bool delete_user(QString email);

    QString m_directory;
    int m_port;
    QString m_passive_ip;

    CFtpServer *FtpServer;
    QString user_email;
    QString user_password;
    QString user_path;

    QTextStream* output;
    QFile *log;


public slots:
    void init();
    void receive_payload(QString s);

    //void remove_user(QString username);
};

#endif // NODEFTP_H
