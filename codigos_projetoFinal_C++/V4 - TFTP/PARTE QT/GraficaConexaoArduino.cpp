#include "GraficaConexaoArduino.h"
#include "ConexaoArduino.h"
#include "JsonMensagens.h"


GraficaConexaoArduino::GraficaConexaoArduino(QWidget *parent)
    : QWidget(parent)
{

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

    for (const QSerialPortInfo& info : QSerialPortInfo::availablePorts()) {
        portaComboBox->addItem(info.portName());
    }

    //Configuracao Baudrate
    baudrateComboBox->addItems(QStringList() << "9600" << "19200" << "38400" << "57600" << "115200");
    baudrateComboBox->setCurrentIndex(0); // padrão baud em 9600

    ledComboBox->addItems(QStringList() << "1" << "2" << "3");
    ledComboBox->setCurrentIndex(0); // padrão baud em 1

    //Cria um obejto na classe ConexaoArduino e ja passa para setConexao
    //Utilizado para conectar a classe GraficaConexaoArduino e ConexaoArduino
    //conexao = new ConexaoArduino(this);


    // Conecta os slots aos botões
    connect(abrirPortaButton, &QPushButton::clicked, this, &GraficaConexaoArduino::onAbrirPortaButtonClicked);
    connect(fecharPortaButton, &QPushButton::clicked, this, &GraficaConexaoArduino::onFecharPortaButtonClicked);
    connect(ledButton, &QPushButton::clicked,         this, &GraficaConexaoArduino::onSelecionarLedsClicked);

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

void GraficaConexaoArduino::onSelecionarLedsClicked(){
    qDebug() <<"Entrou no botao" ;
    QString valorLed = ledComboBox->currentText();
    valorLedInt = valorLed.toInt();
    estado=1;

    mensagemLed = new JsonMensagens(this);
    mensagemLed->JsoninfoLed(valorLedInt,estado);
}

GraficaConexaoArduino::~GraficaConexaoArduino()
{
}

