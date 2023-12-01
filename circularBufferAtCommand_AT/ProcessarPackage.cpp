#include "ProcessarPackage.hpp"
#include "funsape/globalDefines.hpp"

ProcessarPackage::ProcessarPackage(char *command_p, char *options_p)
{
    if(strcmp(command_p, "ATAQ") == 0) {
        printf("Commando aquecedor!\r");
        if(strcmp(options_p, "1") == 0) {
            printf("    Ligar!\r");
        } else if(strcmp(options_p, "0") == 0) {
            printf("    Desligar!\r");
        } else if(strcmp(options_p, "?") == 0) {
            printf("    Perguntar!\r");
        } else {
            printf("    Opcao invalida!\r");
        }

    } else if(strcmp(command_p, "ATLED") == 0) {
        printf("Comando LED!\r");
        if(strcmp(options_p, "1") == 0) {
            printf(" Ligar LED 1! \r");
        } else if(strcmp(options_p, "0") == 0) {
            printf("Desligar LED 1! \r");
        } else {
            printf("  Opcao invalida!\n");
        }
    } else {
        printf("Commando invalido!\r");
    }

}
