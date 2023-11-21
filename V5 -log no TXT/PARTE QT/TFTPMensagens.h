#ifndef TFTPMENSAGENS_H
#define TFTPMENSAGENS_H

#include <QObject>
#include <QHostInfo> // Resolver nomes de host para endereços IP
#include <QTcpSocket> // Sockets para conexão com servidores TFTP.
#include <QRegularExpression> //verifica se e valido
#include <QApplication>


class TFTPMensagens : public QObject
{
    Q_OBJECT
public:
    explicit TFTPMensagens(QObject *parent = nullptr);

    //Verifica se o IP do servidor e valido
    bool isValidIpAddress(const QString &ipAddress);

    //Configura o end IP do servidor TFTP
    void resolveIpAddress(const QString &ipAddress);

    //Configura a porta do servidor TFTP
    void setPort(int port);

    //Configura a mensagem que sera enviado para o TFTP
    void setMessage(const QString &message);

    //Envia a mensagem para o servidor TFTP
    bool sendMessage();

private:
    QString m_ipAddress;
    int m_port;
    QString m_message;


};

#endif // TFTPMENSAGENS_H
