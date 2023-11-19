#include "LogTxt.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QtCore/QTextStream>
#include <QtCore/QtGlobal>
#include <QtCore/QDateTime>
#include <QDir>

LogTxt* LogTxt::_instance = 0;
bool LogTxt::m_firstWrite = true;

LogTxt* LogTxt::get(){
    if(_instance == 0){
        _instance = new LogTxt();
    }
    return _instance;

}


LogTxt::LogTxt(QObject *parent)
{
    m_filename = "LOG";
}


void LogTxt::write(const QString& message)
{
    QString fullPath = QDir::currentPath() + QDir::separator() + m_filename;

    QFile file(fullPath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        qDebug() << "Não foi possível abrir o arquivo de log";
        return;
    }

    QTextStream stream(&file);
    if(m_firstWrite){
        stream << "COMUNICACAO ARDUINO" << Qt::endl;
        m_firstWrite =false;
    }
        stream << QDateTime::currentDateTime().toString() << " - " << message << Qt::endl;

     emit logUpdated(message);   //emite sinal sempre que uma mensagem for gerada
}


void LogTxt::clearLog() {
        QString fullPath = QDir::currentPath() + QDir::separator() + m_filename;

        QFile file(fullPath);
        if (file.exists()) {
        if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
            file.close();
            qDebug() << "Log limpo com sucesso.";
        } else {
            qDebug() << "Falha ao limpar o log.";
        }
        } else {
        qDebug() << "O arquivo de log não existe.";
        }
}

