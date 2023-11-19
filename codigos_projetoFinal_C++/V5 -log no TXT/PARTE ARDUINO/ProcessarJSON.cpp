#include "ProcessarJSON.hpp"

#include <stdlib.h>
#include <string.h>

#include "Led.hpp"

ProcessarJSON::ProcessarJSON(const char *jsonString){

    // Verifica se a mensagem contém a chave ID_LED
    char *idLED = strstr(jsonString, "ID_LED");


    //Contem ID LED
    if (idLED != NULL) {

        ProcessarJSON processarJSON(jsonString);
        processarJSON.msgLed(jsonString);
    }
}


void ProcessarJSON::msgLed(const char *jsonString){

    //Verifica se a mansagem contém estado do Led
    char *estadoLED = strstr(jsonString, "estado");

    // Verifica se a mensagem contém a chave ID_LED
    char *idLED = strstr(jsonString, "ID_LED");

    _idLed = atoi(idLED + 6); // _idLed contem o valor inteiro do led
    _estado = atoi(estadoLED + 7) == 1; // _estado contem o estado do led

    _led = new Led(_idLed,_estado);


}
