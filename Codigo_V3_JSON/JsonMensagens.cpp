#include "JsonMensagens.h"
#include "ConexaoArduino.h"

JsonMensagens::JsonMensagens(QObject *parent)
    : QObject{parent}
{

   conexao = new ConexaoArduino(this);
}

void JsonMensagens::JsoninfoLed(int valorLed,bool estado){

    QJsonObject obj;
    obj["ID LED"]= valorLed;
    obj["estado"] = estado;

    QJsonDocument mensagem;
    mensagem.setObject(obj);
    conexao->escreverDados(mensagem.toJson());

    qDebug() << "Mensagem:" << mensagem;

}
