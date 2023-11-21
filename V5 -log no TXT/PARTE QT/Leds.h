#ifndef LEDS_H
#define LEDS_H

#include <QObject>

#include "JsonMensagens.h"
#include "LogTxt.h"

class Leds : public QObject
{
    Q_OBJECT
public:
    explicit Leds(QObject *parent = nullptr);

    void selecionarLed(int valorLed, bool estado);

private:
    JsonMensagens *_mensagemLed;
    int _valorLedInt;
    bool _estado;

signals:
    void ledSelecionado(const QString &message);
};

#endif // LEDS_H



