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
#include <QTextEdit>
#include "LogTxt.h"
#include "Leds.h"

class GraficaConexaoArduino : public QWidget
{
    Q_OBJECT

public:
    GraficaConexaoArduino(QWidget *parent = nullptr);
    ~GraficaConexaoArduino();

    //void setConexao(ConexaoArduino* conexao);
    void addWidgetToLayout(QWidget* widget);

    void adicionarMensagemTextEdit(const QString& msgTextoEdit);

private:
    //ConexaoArduino* conexao;
    JsonMensagens* mensagemLed;

    QComboBox* portaComboBox;
    QComboBox* baudrateComboBox;
    QPushButton* abrirPortaButton;
    QPushButton* fecharPortaButton;
    QVBoxLayout* layout;

    QComboBox* ledComboBox;
    QPushButton* ledButton;


    //LEDS
    Leds *leds;

    //LOG MENSAGENS
    QTextEdit *logTextEdit;
    QPushButton *ButtonclearTextEdit;

private slots:
    void onAbrirPortaButtonClicked();
    void onFecharPortaButtonClicked();
    void onSelecionarLedsClicked();
    void clearTextEdit();
};
#endif // GRAFICACONEXAOARDUINO_H
