#ifndef CONEXAOARDUINO_H
#define CONEXAOARDUINO_H

#include <QObject>
#include <QSerialPort>
#include <iostream>

class ConexaoArduino : public QObject
{
    Q_OBJECT

     explicit ConexaoArduino(QObject *parent = nullptr);
     ~ConexaoArduino();

 public:
    bool abrirPorta(const QString& porta, int baudrate);
    void fecharPorta();

    bool lerDados(QByteArray& dados);
    void escreverDados(const QByteArray& dados);

    static ConexaoArduino* get();

private:
    QSerialPort* porta; //cria um ponteiro para um objeto do


    static ConexaoArduino* _instance;
};

#endif // CONEXAOARDUINO_H
