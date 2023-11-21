#include "JsonMensagens.h"
#include "ConexaoArduino.h"
#include "GraficaConexaoArduino.h"

JsonMensagens::JsonMensagens(QObject *parent)
    : QObject{parent}
{
}

void JsonMensagens::JsoninfoLed(int valorLed,bool estado){

    QJsonObject obj;
    obj["LED"] = valorLed;
    obj["estado"] = estado;

    QJsonDocument mensagem;
    mensagem.setObject(obj);

    // Converte a mensagem JSON para uma string `QByteArray`
    QString mensagemJSONUtf8 = mensagem.toJson();

    // Remove quebras de linha e espaços em branco
    mensagemJSONUtf8.remove('\n');
    mensagemJSONUtf8.remove(' ');


    // Converte de volta para `QByteArray`
    QByteArray mensagemFinal = mensagemJSONUtf8.toUtf8();

    // Imprime a mensagem final para verificar
    qDebug() << "Mensagem:" << mensagemFinal;

    // Envie a mensagem para a conexão com o Arduino
    ConexaoArduino::get()->escreverDados(mensagemFinal);
    /*  QJsonObject obj;
    obj["LED"]= valorLed;
    obj["estado"] = estado;

    QJsonDocument mensagem;
    mensagem.setObject(obj);

    // Converte a mensagem JSON para uma string `QByteArray`
    QByteArray mensagemJSONUtf8 = mensagem.toJson();

    // Adiciona barras invertidas à mensagem JSON
    for (int i = 0; i < mensagemJSONUtf8.size(); i++) {
        if (mensagemJSONUtf8[i] == '"') {
            mensagemJSONUtf8[i] = '\\';
        }
    }

    ConexaoArduino::get()->escreverDados(mensagemJSONUtf8);

    //conexao->escreverDados("L");

    qDebug() << "Mensagem:" << mensagem;
*/
}
