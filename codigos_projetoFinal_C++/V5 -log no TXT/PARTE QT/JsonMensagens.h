#ifndef JSONMENSAGENS_H
#define JSONMENSAGENS_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

#include "ConexaoArduino.h"

class JsonMensagens : public QObject
{
    Q_OBJECT
public:
    explicit JsonMensagens(QObject *parent = nullptr);

    void JsoninfoLed(int valorLed, bool estado);

private:
};

#endif // JSONMENSAGENS_H
