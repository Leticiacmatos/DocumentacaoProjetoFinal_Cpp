#define F_CPU 16000000UL

#include "funsape/globalDefines.hpp"
#include "funsape/device/hd44780.hpp"
#include "funsape/peripheral/int0.hpp"
#include "funsape/peripheral/int1.hpp"
#include "funsape/peripheral/timer1.hpp"
#include "funsape/peripheral/timer0.hpp"
#include "funsape/peripheral/pcint2.hpp"
#include "funsape/device/keypad.hpp"
#include <avr/interrupt.h>

#include <avr/io.h> //definições do componente

#define BAUD 9600 //taxa de 9600 bps


//Prototipos de funções
void uartBegin(uint32_t baud, uint32_t freq_cpu);       //inicializa uart
uint8_t uartTxOk(void);                                 //verifica se dado pode ser enviado
void uartTx(uint8_t dado);                              //Envia um byte pela porta uart
uint8_t uartRxOk(void);                                 //verifica se uart possui novo dado
uint8_t uartRx();                                       //Ler byte recebido na porta uart
void uartString(const char *c);                         //Envia string. Ultimo valor 0

//INTERRUPCAO USART
void uartIntRx(uint8_t x);
void uartIntTx(uint8_t x);
ISR(USART_RX_vect);

//VARIAVEIS GLOBAIS
volatile int flagOFF = 0;
volatile int flagONN = 0;

int main(void)
{

    setBit(DDRB, PB5);
    setBit(PORTB, PB5);
    uartBegin(BAUD, F_CPU);             //inicializar uart
    uartString("Envie caracter\r\n");
    uartIntRx(1);    //habilita interrupcao recepcao de dados
    sei();

    while(1) {
    }

}


//TRATAMENTO INTERRUPCOES USART
ISR(USART_RX_vect)
{
    unsigned char dado_rx;
    dado_rx = uartRx();
    if(dado_rx == 'L') {
        uartIntTx(1);
        flagONN = 1;
        setBit(PORTB, PB5);
    }
    if(dado_rx == 'D') {
        uartIntTx(1);
        flagOFF = 1;
        clrBit(PORTB, PB5);
    }
}
ISR(USART_TX_vect)
{

    if(flagONN) {
        uartString("on\r\n");
        flagONN = 0;
        uartIntTx(0);
    }
    if(flagOFF) {
        uartString("of\r\n");
        flagOFF = 0;
        uartIntTx(0);
    }


}

//FUNCOES USART
//inicializa a porta de comunicação uart do ATmega328
void uartBegin(uint32_t baud, uint32_t freq_cpu)
{
    uint16_t myubrr = freq_cpu / 16 / baud - 1; //calcula valor do registrador UBRR
    UBRR0H = (uint8_t)(myubrr >> 8);            //ajusta a taxa de transmissão
    UBRR0L = (uint8_t)myubrr;
    UCSR0A = 0;                                 //desabilitar velocidade dupla (no Arduino é habilitado por padrão)
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);       //habilita a transmissão e recepção. Sem interrupcao
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);     //assíncrono, 8 bits, 1 bit de parada, sem paridade
}

//verifica se novo dado pode ser enviado pela UART
//retorna valor 32 se novo dado pode ser enviado. Zero se não.
uint8_t uartTxOk(void)
{
    return (UCSR0A & (1 << UDRE0));
}

//Envia um byte pela porta uart
void uartTx(uint8_t dado)
{
    UDR0 = dado;    //envia dado
}

void uartString(const char *c)
{
    while(*c) {
        uartTx(*c);
        c++;
    }
}


//verifica se UART possui novo dado
//retorna valor 128 se existir novo dado recebido. Zero se não.
uint8_t uartRxOk(void)
{
    return (UCSR0A & (1 << RXC0));
}

//Ler byte recebido na porta uart
uint8_t uartRx()
{
    return UDR0; //retorna o dado recebido
}


void uartIntRx(uint8_t x)
{
    if(x) {
        UCSR0B |= (1 << RXCIE0);    //Habilita interrupção de recepção de dados
    } else {
        UCSR0B &= ~(1 << RXCIE0);    //Desabilita interrupção de recepção de dados
    }
}
//Habilita ou desabilita interrupção de Transmissão da usart
//x = 0, desabilita interrupção. Outro valor, habilita interrupção
void uartIntTx(uint8_t x)
{
    if(x) {
        UCSR0B |= (1 << TXCIE0);    //Habilita interrupção de recepção de dados
    } else {
        UCSR0B &= ~(1 << TXCIE0);    //Desabilita interrupção de recepção de dados
    }
}
