#ifndef LOGTXT_H
#define LOGTXT_H

#include <QObject>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QtCore/QTextStream>
#include <QtCore/QtGlobal>
#include <QtCore/QDateTime>
#include <QDir>

class LogTxt : public QObject
{
    Q_OBJECT
public:
    explicit LogTxt(QObject *parent = nullptr);

    void write(const QString& message);
    void clearLog();

    static LogTxt* get();

private:
    QString m_filename;
    static LogTxt* _instance;
    static bool m_firstWrite;


signals:
    void logUpdated(const QString& logMessage);
};

#endif // LOGTXT_H
