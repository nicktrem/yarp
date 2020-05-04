/*
 * Copyright (C) 2006-2020 Istituto Italiano di Tecnologia (IIT)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef LOGMODEL_H
#define LOGMODEL_H

#include <QAbstractTableModel>
#include <yarp/logger/YarpLogger.h>
#include <QFont>


class LogModel : public QAbstractTableModel
{
    Q_OBJECT
    Q_DISABLE_COPY(LogModel);

public:
    enum Roles
    {
        YarprunTimestampRole = Qt::UserRole + 1,
        LocalTimestampRole,
        SystemTimeRole,
        SystemTimeStringRole,
        NetworkTimeRole,
        NetworkTimeStringRole,
        LogLevelRole,
        LogLevelStringRole,
        FilenameRole,
        LineRole,
        LineStringRole,
        FunctionRole,
        HostnameRole,
        PidRole,
        CmdRole,
        ArgsRole,
        PidStringRole,
        ThreadIdRole,
        ThreadIdStringRole,
        ComponentRole,
        TextRole,
        BacktraceRole,
    };

    static constexpr int YARPRUNTIMESTAMP_COLUMN = 0;
    static constexpr int LOCALTIMESTAMP_COLUMN   = 1;
    static constexpr int SYSTEMTIME_COLUMN       = 2;
    static constexpr int NETWORKTIME_COLUMN      = 3;
    static constexpr int LOGLEVEL_COLUMN         = 4;
    static constexpr int FILENAME_COLUMN         = 5;
    static constexpr int LINE_COLUMN             = 6;
    static constexpr int FUNCTION_COLUMN         = 7;
    static constexpr int HOSTNAME_COLUMN         = 8;
    static constexpr int PID_COLUMN              = 9;
    static constexpr int CMD_COLUMN              = 10;
    static constexpr int ARGS_COLUMN             = 11;
    static constexpr int THREADID_COLUMN         = 12;
    static constexpr int COMPONENT_COLUMN        = 13;
    static constexpr int TEXT_COLUMN             = 14;
    static constexpr int COLUMN_COUNT            = 15;

    explicit LogModel(QObject *parent = nullptr);
    ~LogModel() override;

    int rowCount(const QModelIndex & parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

    void addMessages(const std::list<yarp::yarpLogger::MessageEntry> &messages);
    void clear();

    void setColor(bool enabled);
    void setWordWrap(bool wordwrap);

    static QString logLevelToString(yarp::yarpLogger::LogLevel l);

private:
    QFont m_font;
    QList<yarp::yarpLogger::MessageEntry> m_messages;
    QHash<int, QByteArray> m_names;
    bool m_color {true};
    bool m_wordwrap {false};
};


#endif // LOGMODEL_H