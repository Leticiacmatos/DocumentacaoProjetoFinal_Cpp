#include "ProcessarJSON.hpp"


#include <stdlib.h>
#include <string.h>

#include "Led.hpp"

ProcessarJSON::ProcessarJSON()
{

}

void ProcessarJSON::processarMsg(const char *jsonString)
{


    // Verifica se a mensagem contém a chave ID_LED
    char *idLED = strstr(jsonString, "L1");


    //Contem ID LED
    if(idLED != NULL) {
        setBit(PORTB, PB0);
        msgLed(jsonString);
    }

}

void ProcessarJSON::msgLed(const char *jsonString)
{
    /*     int idLed;
        bool estado;

        // Busca a chave ID_LED
        char *ptrIdLed = strstr(jsonString, "\"ID_LED\":");
        if(ptrIdLed != NULL) {
            ptrIdLed += strlen("\"ID_LED\":");
            idLed = 1;//atoi(ptrIdLed);

        }

        const char *ptrEstado = strstr(jsonString, "\"estado\":");
        if(ptrEstado != nullptr) {
            ptrEstado += strlen("\"estado\":");
            estado = (*ptrEstado == 't');  // Se a primeira letra após "estado:" for 't', consideramos true
        }

        if(idLed == 1) {
            setBit(PORTB, PB0);
        }

        // Cria um objeto Led
        Led led(idLed, estado);
     */

}
