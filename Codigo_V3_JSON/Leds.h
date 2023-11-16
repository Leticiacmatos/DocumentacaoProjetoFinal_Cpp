// Leds.h

#ifndef LEDS_H
#define LEDS_H

#include "ConexaoArduino.h"
#include "JsonMensagens.h"
#include <QObject>

// Declaração antecipada de GraficaLeds
class GraficaLeds;

class Leds : public QObject
{
    Q_OBJECT
public:
    explicit Leds(int led,QObject* parent = nullptr);
    //void setLed(int led);

private:
    GraficaLeds* graficaLeds;
    JsonMensagens* mensagem;
    ConexaoArduino* conexao;
    int _led;
    bool status;
};

#endif // LEDS_H
