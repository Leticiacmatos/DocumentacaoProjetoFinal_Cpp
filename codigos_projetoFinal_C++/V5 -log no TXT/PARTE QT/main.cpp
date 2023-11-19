#include "GraficaConexaoArduino.h"
#include "GraficaLeds.h"
#include <QApplication>
#include "LogTxt.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GraficaConexaoArduino conexaoArduino;


    conexaoArduino.show();


    return a.exec();
}






