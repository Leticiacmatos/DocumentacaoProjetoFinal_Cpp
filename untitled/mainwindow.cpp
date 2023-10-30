#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //instância da QSerialPort
    this->serialPort = new QSerialPort;

    //Montagem da lista de portas e alimentação do combobox com a lista de portas disponíveis
    QStringList ports;
    const auto serialPortInfos = QSerialPortInfo::availablePorts();
    int i = 0;
    for (const QSerialPortInfo &serialPortInfo : serialPortInfos){
        ports.insert(i,serialPortInfo.portName());
        i++;
    }
    ui->comboBox_port->insertItems(0,ports);

    //Criação da lista de velocidades da comunicação serial e alimentação do combobox baudrate
    QStringList bauds;
    bauds << "9600" << "19200" << "38400" << "57600" << "115200";
    ui->comboBox_baud->insertItems(0,bauds);

    /*Conexão do clique do botão com o slot que inicia a conexão, visto no tutorial 01 de Qt*/
    connect(ui->pushButton_connect,SIGNAL(clicked(bool)),this,SLOT(connectToSerial()));


    connect(ui->pushButton_onoff,SIGNAL(clicked()),this,SLOT(onOffClicked()));
    connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::dadosRecebidos);


}
/*
void MainWindow::startReading()
{

    QByteArray readData = this->serialPort->readAll();
    //Apenas exibindo a leitura em stdout.
    qDebug() << readData;

    if (this->ON){
        this->ON = false;
        this->serialPort->write("1\n");
    }
    else{
        this->ON = true;
        this->serialPort->write("0\n");
    }
}*/

void MainWindow::dadosRecebidos()
{
    QByteArray dados = this->serialPort->readAll(); // Lê os dados recebidos
    QString dadosString = QString::fromStdString(dados.toStdString()); // Converte para QString
    ui->label_dadosRecebidos->setText(dadosString); // Atualiza o QLabel com os dados recebidos
    qDebug()<<dadosString;
}


void MainWindow::onOffClicked()
{
          if (this->ON_OFF) {
            this->ON_OFF = false;
            this->serialPort->write("L\n"); // Envia 'L' para ligar o LED no lado do AVR
        } else {
            this->ON_OFF = true;
            this->serialPort->write("D\n"); // Envia 'D' para desligar o LED no lado do AVR
        }


}

void MainWindow::connectToSerial()
{
    /*Na conexão é feito a abertura ou fechamento da porta.*/
    if (this->serialPort->isOpen()){
        this->serialPort->close();
        ui->label_status->setText("Desconectado");
        ui->pushButton_connect->setText("Conectar");
        return;
    }
    //se for para abrir, pegamos os parâmetros de velocidade e porta a abrir.
    this->serialPort->setPortName(ui->comboBox_port->currentText());
    this->serialPort->setBaudRate(ui->comboBox_baud->currentText().toUInt());
    this->serialPort->setDataBits(QSerialPort::Data8);
    this->serialPort->setParity(QSerialPort::NoParity);
    this->serialPort->setStopBits(QSerialPort::OneStop);


    if (!this->serialPort->open(QIODevice::ReadWrite)){
        ui->label_status->setText("Falha ao tentar conectar");
        return;
    }
    ui->label_status->setText("Conectado");
    ui->pushButton_connect->setText("Desconectar");

    emit startReading(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
