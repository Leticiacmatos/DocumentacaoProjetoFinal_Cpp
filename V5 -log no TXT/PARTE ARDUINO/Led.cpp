#include "Led.hpp"
#include "funsape/globalDefines.hpp"

Led::Led(int idLed, bool estado)
{

    if(estado == true) {

        LigarLed(idLed);
    }

}

void Led::LigarLed(int idLed)
{

    if(idLed == 1) {

        setBit(DDRB, PB1);
        setBit(PORTB, PB1);
    }

    if(idLed == 2) {
        setBit(DDRB, PB2);
        setBit(PORTB, PB2);
    }

    if(idLed == 3) {
        setBit(DDRB, PB3);
        setBit(PORTB, PB3);
    }

}
