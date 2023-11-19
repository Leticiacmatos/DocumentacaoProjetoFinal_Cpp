#define F_CPU 16000000UL

#include "funsape/globalDefines.hpp"
#include "funsape/peripheral/usart0.hpp"
#include "ProcessarJSON.hpp"

vuint8_t receivedData;
volatile Usart0::ReceptionError receivedStatus;
vbool_t receivedFlag = false;




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
                ProcessarJSON obj1((const char *)&receivedData);



                //CASO TENHA SIDO RECEBIDO COM SUCESSO
                //processarJson((const char *)&receivedData);
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
}
