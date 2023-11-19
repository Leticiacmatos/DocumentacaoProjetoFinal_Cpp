#include "TFTPMensagens.h"
#include <QHostInfo>
#include <QTcpSocket>
#include <QRegularExpression>
#include <QDebug>

TFTPMensagens::TFTPMensagens(QObject *parent)
    : QObject{parent}
{

}

bool TFTPMensagens::isValidIpAddress(const QString &ipAddress) {
    // Define a expressão regular para um endereço IP válido
    QRegularExpression regex("^(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])$");

    // Verifica se a string corresponde à expressão regular
    QRegularExpressionMatch match = regex.match(ipAddress);

    // Retorna true se a string corresponder à expressão regular
    return match.hasMatch();

}

void TFTPMensagens::resolveIpAddress(const QString &ipAddress) {
     qDebug() << "resolveIpAddress ";
    // Verifica se o endereço IP é válido
    if (isValidIpAddress(ipAddress)) {
         qDebug() << "valido ";
        // Resolve o endereço IP
        QHostInfo hostInfo = QHostInfo::fromName(ipAddress);

        // Armazena o endereço IP resolvido
        if (!hostInfo.addresses().isEmpty()) {
              qDebug() << "armazena ip resolido ";
            m_ipAddress = hostInfo.addresses().first().toString();
        }
    }
}

//Configura a porta do servidor TFTP
void TFTPMensagens::setPort(int port) {

    // Verifica se a porta é válida
    if (port < 1 || port > 65535) {
         qDebug() << "Porta inválida: " << port;
            return;
    }

    // Armazena a porta
    m_port = port;
}
//Configura a mensagem que sera enviado para o TFTP
void TFTPMensagens::setMessage(const QString &mensagem) {
    // Armazena a mensagem
    m_message = mensagem;
}


//Envia a mensagem para o servidor TFTP
bool TFTPMensagens::sendMessage() {
    // Verifica se os dados estão configurados
    if (m_ipAddress.isEmpty() || m_port == 0 || m_message.isEmpty()) {
            qDebug() << "Os dados não estão configurados.";
            return false;
    }

    // Cria um socket TFTP
    QTcpSocket socket;

    // Conecta o socket ao servidor TFTP
    socket.connectToHost(m_ipAddress, m_port);

    // Aguarda a conexão ser estabelecida
    if (!socket.waitForConnected()) {
            qDebug() << "Falha ao conectar ao servidor TFTP.";
            return false;
    }


    // Envia a mensagem para o servidor TFTP
    socket.write(m_message.toUtf8());

    // Fecha o socket
    socket.close();

    // Retorna true se a mensagem foi enviada com sucesso
    return true;
}
