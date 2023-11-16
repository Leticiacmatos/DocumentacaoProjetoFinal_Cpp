#ifndef GRAFICACONEXAOARDUINO_H
#define GRAFICACONEXAOARDUINO_H

#include "ConexaoArduino.h"
#include "JsonMensagens.h"
#include <QWidget>
#include <QApplication>
#include <QSerialPortInfo>
#include <QPushButton>
#include <QComboBox>
#include <QMainWindow>
#include <QVBoxLayout>

class GraficaConexaoArduino : public QWidget
{
    Q_OBJECT

public:
    GraficaConexaoArduino(QWidget *parent = nullptr);
    ~GraficaConexaoArduino();

    void setConexao(ConexaoArduino* conexao);
    void addWidgetToLayout(QWidget* widget);


private:
    ConexaoArduino* conexao;
    JsonMensagens* mensagemLed;

    QComboBox* portaComboBox;
    QComboBox* baudrateComboBox;
    QPushButton* abrirPortaButton;
    QPushButton* fecharPortaButton;
    QVBoxLayout* layout;

    QComboBox* ledComboBox;
    QPushButton* ledButton;



    int valorLedInt;
    bool estado=0;
private slots:
    void onAbrirPortaButtonClicked();
    void onFecharPortaButtonClicked();
    void onSelecionarLedsClicked();
};
#endif // GRAFICACONEXAOARDUINO_H
