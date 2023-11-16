#ifndef CONEXAOARDUINO_H
#define CONEXAOARDUINO_H

#include <QObject>
#include <QSerialPort>

class ConexaoArduino : public QObject
{
    Q_OBJECT
public:
    explicit ConexaoArduino(QObject *parent = nullptr);
    ~ConexaoArduino();

    bool abrirPorta(const QString& porta, int baudrate);
    void fecharPorta();

    bool lerDados(QByteArray& dados);
    void escreverDados(const QByteArray& dados);

private:
    QSerialPort* porta; //cria um ponteiro para um objeto do

};

#endif // CONEXAOARDUINO_H
