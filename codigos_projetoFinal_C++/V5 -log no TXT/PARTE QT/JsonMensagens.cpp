#include "JsonMensagens.h"
#include "ConexaoArduino.h"
#include "GraficaConexaoArduino.h"

JsonMensagens::JsonMensagens(QObject *parent)
    : QObject{parent}
{
}

void JsonMensagens::JsoninfoLed(int valorLed,bool estado){

    QJsonObject obj;
    obj["ID LED"]= valorLed;
    obj["estado"] = estado;

    QJsonDocument mensagem;
    mensagem.setObject(obj);
    ConexaoArduino::get()->escreverDados(mensagem.toJson());

    //conexao->escreverDados("L");

    qDebug() << "Mensagem:" << mensagem;

}
