#ifndef LED_H
#define LED_H

#include "funsape/globalDefines.hpp"

class Led
{

public:
    Led(int idLed, bool estado);

private:
    void LigarLed(int idLed);
    //void DesligarLed(int idLed);

    //int _idLed;
    //bool _estado;


};




#endif // CONEXAOARDUINO_H
