#ifndef PROCESSARJSON_H
#define PROCESSARJSON_H

#include "Led.hpp"





class ProcessarJSON
{
public:
    ProcessarJSON();

    void processarMsg(const char *jsonString);


private:
    void msgLed(const char *jsonString);


};

#endif // CONEXAOARDUINO_H
