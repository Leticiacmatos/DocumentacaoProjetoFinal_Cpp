#define F_CPU 16000000UL

#include "funsape/globalDefines.hpp"
#include "funsape/util/circularBuffer.hpp"
#include "funsape/peripheral/usart0.hpp"
#include "ProcessarPackage.hpp"

CircularBuffer<uint8_t> circBuffer;

int main()
{
    uint8_t packageData[25];
    uint8_t packageDataIndex = 0;
    bool_t packageAwaiting = false;

    usart0.init();
    usart0.enableTransmitter();
    usart0.enableReceiver();
    usart0.activateReceptionCompleteInterrupt();
    usart0.stdio();

    sei();


    circBuffer.init(50);

    while(1) {

        while((!circBuffer.isEmpty()) && (!packageAwaiting)) {
            uint8_t auxData = 0;
            circBuffer.pop(&auxData);
            if(auxData != '\r') {
                packageData[packageDataIndex++] = auxData;
            } else {
                packageData[packageDataIndex++] = '\0';
                packageAwaiting = true;
                break;
            }
        }
        if(packageAwaiting) {
            char packageCommand[10];
            char packageOptions[10];
            uint8_t i = 0;
            uint8_t j = 0;

            while(packageData[i] != '=') {
                packageCommand[j++] = packageData[i++];
            }
            packageCommand[j++] = '\0';
            i++;
            j = 0;
            while(packageData[i] != '\0') {
                packageOptions[j++] = packageData[i++];
            }
            packageOptions[j++] = '\0';

            ProcessarPackage obj1(packageCommand, packageOptions);


            packageDataIndex = 0;
            packageAwaiting = false;
        }
    }

    return 0;
}

void usartReceptionCompleteCallback(void)
{
    circBuffer.push(UDR0);
}
