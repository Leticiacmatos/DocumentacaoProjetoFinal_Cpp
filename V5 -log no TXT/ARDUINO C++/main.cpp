#define F_CPU 16000000UL

#include "funsape/globalDefines.hpp"
#include "funsape/peripheral/usart0.hpp"

vuint8_t receivedData;
volatile Usart0::ReceptionError receivedStatus;
vbool_t receivedFlag = false;


struct LedInfo {
    int id;
    bool estado;
};
LedInfo ledInfo;

void processarJson(const char *jsonString)
{
    LedInfo ledInfo;

    int numItens = sscanf(jsonString, "{\"ID_LED\": %d, \"estado\": %d}", &ledInfo.id, &ledInfo.estado);

    if(numItens == 2) {
        printf("ID do LED: %d\n", ledInfo.id);
        printf("Estado do LED: %s\n", ledInfo.estado ? "Ligado" : "Desligado");
        int idLido = ledInfo.id;
        if(idLido == 1) {
            setBit(DDRB, PB1);
            setBit(PORTB, PB1);
        }
    } else {
        // Tratar erro na deserialização
        printf("Erro ao processar JSON\n");
    }
}

int main()
{

    // UART configuration
    usart0.setBaudRate(Usart0::BaudRate::BAUD_RATE_9600);
    usart0.enableReceiver();            //Habilita Receptor
    usart0.enableTransmitter();         //Habilita Transmissor
    usart0.activateReceptionCompleteInterrupt();//Habilita interrupcao de recepcao completa
    usart0.init();  //finaliza a configuracao

    sei();
    while(1) {
        if(receivedFlag) {
            if(receivedStatus != Usart0::ReceptionError::NONE) {        // CASO OCORRA UMA ERRO DURANTE A RECEPCAO

            } else {
                //CASO TENHA SIDO RECEBIDO COM SUCESSO
                processarJson((const char *)&receivedData);
            }
            receivedFlag = false;
        }
    }

    return 0;
}

void usartReceptionCompleteCallback()
{
    usart0.getReceptionStatus((Usart0::ReceptionError *)&receivedStatus);
    receivedData = UDR0;
    receivedFlag = true;

    if(receivedData == 'L') {
        setBit(DDRB, PB1);
        setBit(PORTB, PB1);
    }
}
