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
        return 0;
    }
    
    switch (var[0]) {
        case 'n':
            return 2;
            break;
            
        case 'e':
            return 1;
            break;
            
        default:
            return 0;
            break;
    }
    return 0;
}

void mainMenu()
{
    printf("Hauptmenü:\n");
    printf("Bitte wählen:\n");
    printf("n - neues Spiel\n");
    printf("e - Spiel beenden\n");
    printf("Eingabe: ");
}

int main()
{
    char selection[] = "\0";
    int navigation = -1;
    
    CLS;
    mainMenu();
    scanf("%s", selection);
    navigation = validateMenuInput(selection);
    
    while(1){
        switch (navigation) {
            //exit
            case 1:
                CLS;
                printf("Spiel beendet!\n");
                return 0;
                break;
            case 2:
                //newGame();
                CLS;
                printf("Neues Spiel wird erstellt!\n");
                return 0;
                break;
                
            default:
                CLS;
                printf("Falsche Eingabe entdeckt!\n");
                mainMenu();
                scanf("%s", selection);
                navigation = validateMenuInput(selection);
                break;
        }
    }
    
    return 0;
}
