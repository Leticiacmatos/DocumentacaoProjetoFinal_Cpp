#include "Leds.h"
#include "GraficaConexaoArduino.h"

Leds::Leds(QObject *parent)
    : QObject{parent}
{

}
void Leds::selecionarLed(int valorLed, bool estado){
    _valorLedInt = valorLed;
    _estado = estado;

    _mensagemLed->JsoninfoLed(_valorLedInt, _estado);

    //LogTxt::get()->write("Selecionar LED: " + QString::number(_valorLedInt) + " - Estado: " + (_estado ? "Ligado" : "Desligado"));
   // GraficaConexaoArduino::get()->adicionarMensagemTextEdit("Selecionar LED: " + QString::number(_valorLedInt) + " - Estado: " + (_estado ? "Ligado" : "Desligado"));


    emit ledSelecionado("LED " + QString::number(_valorLedInt) + " selecionado - Estado: " + (_estado ? "Ligado" : "Desligado"));
}
