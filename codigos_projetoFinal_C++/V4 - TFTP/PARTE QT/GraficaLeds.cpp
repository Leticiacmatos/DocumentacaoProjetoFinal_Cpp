#include "GraficaLeds.h"
#include "Leds.h"


GraficaLeds::GraficaLeds(QWidget *parent)
    : QWidget{parent}
{
    _labelLeds = new QLabel("Ligar Leds:", this);
    _comboBoxleds = new QComboBox;
    _conectaLed =new QPushButton("LIGA LED",this);

    _comboBoxleds->addItems(QStringList() << "1" << "2" << "3");
    _comboBoxleds->setCurrentIndex(0); // padrão baud em 1


    _layout = new QVBoxLayout(this);

    _layout->addWidget(_labelLeds);
    _layout->addWidget(_comboBoxleds);
    _layout->addWidget(_conectaLed);
    qDebug() <<"Entrou no GraficaLeds" ;

    connect(_conectaLed, &QPushButton::clicked, this, &GraficaLeds::setLedButtonClicked);
}

int GraficaLeds::setLedButtonClicked(){
    qDebug() <<"Entrou no botao" ;
      QString porta = _comboBoxleds->currentText();
       _valorInteiro = porta.toInt();


      if (!leds) {
          leds = new Leds(_valorInteiro);
      }


}
int GraficaLeds::retornaValorLed() const {
      return _valorInteiro;
        qDebug() <<"VALOOOR:", _valorInteiro ;
}

