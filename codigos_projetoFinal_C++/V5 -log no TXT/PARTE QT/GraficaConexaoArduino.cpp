#include "GraficaConexaoArduino.h"
#include "ConexaoArduino.h"
#include "JsonMensagens.h"
#include "LogTxt.h"
#include "Leds.h"
#include <QTextEdit>



GraficaConexaoArduino::GraficaConexaoArduino(QWidget *parent)
    : QWidget(parent)
{
    leds= new Leds();

    //Botao Limpa Log
    ButtonclearTextEdit = new QPushButton("LIMPAR LOG");

    logTextEdit = new QTextEdit(this);
    logTextEdit->setReadOnly(true);  //Widget somente leitura

     //Cria ComboBox
    portaComboBox = new QComboBox;
    baudrateComboBox = new QComboBox;
    ledComboBox=  new QComboBox;

    //Cria os botoes
    abrirPortaButton = new QPushButton("Abrir Porta", this);
    fecharPortaButton = new QPushButton("Fechar Porta", this);
    ledButton = new QPushButton("Ligar LED", this);

    //Cria QVBoxLayout* layout
    layout = new QVBoxLayout(this);
    layout->addWidget(portaComboBox);
    layout->addWidget(baudrateComboBox);
    layout->addWidget(abrirPortaButton);
    layout->addWidget(fecharPortaButton);
    layout->addWidget(ledComboBox);
    layout->addWidget(ledButton);
    layout->addWidget(logTextEdit);
    layout->addWidget(ButtonclearTextEdit);

    for (const QSerialPortInfo& info : QSerialPortInfo::availablePorts()) {
        portaComboBox->addItem(info.portName());
    }

    //Configuracao Baudrate
    baudrateComboBox->addItems(QStringList() << "9600" << "19200" << "38400" << "57600" << "115200");
    baudrateComboBox->setCurrentIndex(0); // padrão baud em 9600

    ledComboBox->addItems(QStringList() << "1" << "2" << "3");
    ledComboBox->setCurrentIndex(0); // padrão baud em 1



    // Conecta os slots aos botões
    connect(abrirPortaButton, &QPushButton::clicked, this, &GraficaConexaoArduino::onAbrirPortaButtonClicked);
    connect(fecharPortaButton, &QPushButton::clicked, this, &GraficaConexaoArduino::onFecharPortaButtonClicked);
    connect(ledButton, &QPushButton::clicked,         this, &GraficaConexaoArduino::onSelecionarLedsClicked);

    //LOGS
    connect(leds, &Leds::ledSelecionado, LogTxt::get(), &LogTxt::write);
    connect(LogTxt::get(), &LogTxt::logUpdated, this, &GraficaConexaoArduino::adicionarMensagemTextEdit);
    connect(ButtonclearTextEdit, &QPushButton::clicked, this, &GraficaConexaoArduino::clearTextEdit);
}

void GraficaConexaoArduino::onAbrirPortaButtonClicked()
{
    // Obtém o nome da porta selecionada.
    QString porta = portaComboBox->currentText();

    // Obtém o baudrate selecionado.
    int baudrate = baudrateComboBox->currentText().toInt();

    // Abre a porta serial.
    if (ConexaoArduino::get()->abrirPorta(porta, baudrate)) {
        qDebug() <<"Porta Aberta" ;

    } else {
        qDebug() <<"Erro ao abrir a porta" ;
    }
}

void GraficaConexaoArduino::onFecharPortaButtonClicked(){
    ConexaoArduino::get()->fecharPorta();
}


// IMPLEMENTACAO LEDS
void GraficaConexaoArduino::onSelecionarLedsClicked(){

    QString valorLedStr = ledComboBox->currentText();
    bool estado = true;

    // Verifique se o valor do LED é um número inteiro
    bool ok;
    int valorLedInt = valorLedStr.toInt(&ok);

    if (ok) {
        leds->selecionarLed(valorLedInt, estado);
    } else {
        qDebug() << "Erro ao converter valor do LED para inteiro";
    }


}

//envia mensagens para o textEdit
void GraficaConexaoArduino::adicionarMensagemTextEdit(const QString& msgTextoEdit){
    logTextEdit->append(msgTextoEdit);
    qDebug() <<"entrou no text edit";
}

void GraficaConexaoArduino::clearTextEdit(){
       logTextEdit->clear();
}


GraficaConexaoArduino::~GraficaConexaoArduino()
{
}

