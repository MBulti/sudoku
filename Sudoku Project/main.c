//--- Windows ---//
//#define PLATFORM 1 //Windows
//#define CLS system("cls")

//--- Mac/Linux --//
#define PLATFORM 2 //Linux/Mac
#define CLS system("clear")

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/consolePrinter.h"

int validateMenuInput(char *var)
{
    char workaround;
    //workaround depends on os
    switch (PLATFORM) {
        case 1:
            fflush(stdin);
            break;
        case 2:
            scanf("%c", &workaround);
            break;
        default:
            break;
    }
    
    if(strlen(var) > 1){
        return -1;
    }
    
    switch (var[0]) {
        case 'n':
            return 1;
            break;
            
        case 'e':
            return 0;
            break;
            
        default:
            return -1;
            break;
    }
    return -1;
}

int main()
{
    char selection[] = "\0";
    int navigation = -1;
    
    while(1){
        switch (navigation) {
            //exit
            case 0:
                return 0;
                break;
            case 1:
                //newGame();
                break;
                
            default:
                printf("Gültige Eingabe:\n");
                scanf("%s", selection);
                navigation = validateMenuInput(selection);
                break;
        }
    }
    
    return 0;
}
