// Leds.cpp

#include "Leds.h"
#include "GraficaLeds.h"
#include "ConexaoArduino.h"
#include "JsonMensagens.h"


Leds::Leds(int led,QObject* parent)
{

    _led=led;

    JsonMensagens* mensagem =new JsonMensagens(this);
    mensagem->JsoninfoLed(_led);
     qDebug() <<"entrou no LEDS::LEDS" ;


}

/*void Leds::setLed(int led){

     JsonMensagens* mensagem =new JsonMensagens();
     mensagem->JsoninfoLed(led);

}*/

