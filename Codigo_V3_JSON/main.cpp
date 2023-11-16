#include "GraficaConexaoArduino.h"
#include "GraficaLeds.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GraficaConexaoArduino conexaoArduino;

    conexaoArduino.show();


    return a.exec();
}






