#include "GraficaConexaoArduino.h"
#include "GraficaLeds.h"
#include <QApplication>
#include <TFTPMensagens.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GraficaConexaoArduino conexaoArduino;

    TFTPMensagens enviaTFTP;
    enviaTFTP.isValidIpAddress("192.168.0.103");
    enviaTFTP.resolveIpAddress("192.168.0.103");
    enviaTFTP.setPort(69);
    enviaTFTP.setMessage("oiiiiii");
    enviaTFTP.sendMessage();

    conexaoArduino.show();


    return a.exec();
}






