#include "ConexaoArduino.h"
#include <QDebug>

ConexaoArduino* ConexaoArduino::_instance = 0;

ConexaoArduino* ConexaoArduino::get(){
    if(_instance == 0){
        _instance = new ConexaoArduino();
    }
    return _instance;
}

ConexaoArduino::ConexaoArduino(QObject *parent)
    : QObject{parent}
{
    porta = new QSerialPort();
}

ConexaoArduino::~ConexaoArduino()
{
    delete porta;
}
bool ConexaoArduino::abrirPorta(const QString& NomePorta, int baudrate)
{
    // Configura a porta serial.
    porta->setPortName(NomePorta);
    porta->setBaudRate(baudrate);
    porta->setDataBits(QSerialPort::Data8);
    porta->setParity(QSerialPort::NoParity);
    porta->setStopBits(QSerialPort::OneStop);
    porta->setFlowControl(QSerialPort::NoFlowControl);

    // Tenta abrir a porta serial.
    if (!porta->open(QIODevice::ReadWrite)) {
        qDebug() << " Porta Nao Aberta";
        return false;
    }


    return true;
}

void ConexaoArduino::fecharPorta()
{
    // Fecha a porta serial.
    porta->close();
}

bool ConexaoArduino::lerDados(QByteArray& dados)
{
    // Lê os dados da porta serial.
    dados = porta->readAll();

    // Verifica se há dados disponíveis.
    if (dados.isEmpty()) {
        return false;
    }

    return true;
}

void ConexaoArduino::escreverDados(const QByteArray& dados)
{

      qDebug() <<"hugo" ;
    if (this->porta->isOpen() && this->porta->isWritable()) {
        int tmp = this->porta->write(dados);
        qDebug() << "Write=" << tmp ;
    } else {
        qDebug() << "isOpen" << this->porta->isOpen();
        qDebug() << "isWritable" << this->porta->isWritable();

    }
}
