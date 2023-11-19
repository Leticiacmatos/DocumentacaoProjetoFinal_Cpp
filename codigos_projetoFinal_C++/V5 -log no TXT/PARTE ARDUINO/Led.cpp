#include "Led.hpp"


#include "funsape/globalDefines.hpp"

Led::Led(int idLed, bool estado)
{

    _idLed = idLed;
    _estado = estado;


    if(_estado == true) {
        Led led(_idLed, _estado);
        led.LigarLed(_idLed);
    }

}

void Led::LigarLed(int idLed)
{
    if(idLed == 1) {
        setBit(DDRB, PB1);
        setBit(DDRB, PB1);
    }

    if(idLed == 2) {
        setBit(DDRB, PB2);
        setBit(DDRB, PB2);
    }


    if(idLed == 3) {
        setBit(DDRB, PB3);
        setBit(DDRB, PB3);
    }

}
