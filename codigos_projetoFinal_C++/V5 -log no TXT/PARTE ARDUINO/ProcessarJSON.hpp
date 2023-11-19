#ifndef PROCESSARJSON_H
#define PROCESSARJSON_H

#include "Led.hpp"

class ProcessarJSON{
  public:
    ProcessarJSON(const char *jsonString);




  private:
    void msgLed(const char *jsonString);

    int _idLed;
    bool _estado;

    Led *_led;

};

#endif // CONEXAOARDUINO_H
