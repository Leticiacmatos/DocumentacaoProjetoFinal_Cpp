#ifndef GRAFICALEDS_H
#define GRAFICALEDS_H


#include "Leds.h"
#include <QWidget>
#include <QApplication>
#include <QSerialPortInfo>
#include <QPushButton>
#include <QComboBox>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>

class GraficaLeds : public QWidget
{
    Q_OBJECT
public:
    explicit GraficaLeds(QWidget *parent = nullptr);
    int retornaValorLed()const ;


private:
    QComboBox* _comboBoxleds;
    QVBoxLayout* _layout;
    QLabel* _labelLeds;
    QPushButton* _conectaLed;
    Leds* leds = nullptr;

    int _valorInteiro;

private slots:
    int setLedButtonClicked();
};

#endif // GRAFICALEDS_H
