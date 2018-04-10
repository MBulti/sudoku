//  Created by Robin Winkler on 10.04.18.

//--- Windows ---//
//#define PLATFORM 1 //Windows
//#define CLS system("cls")

//--- Mac/Linux --//
#define PLATFORM 2 //Linux/Mac
#define CLS system("clear")

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/gameMaster.h"
#include "include/consolePrinter.h"
#include "include/validator.h"

int main()
{
    int navigation = -1;
    
    navigation = mainMenu(navigation);
    
    while(1){
        switch (navigation) {
            //exit
            case 1:
                CLS;
                printf("Spiel beendet!\n");
                return 0;
                break;
            case 2:
                newGame();
                CLS;
                return 0;
                break;
                
            default:
                navigation = mainMenu(navigation);
                break;
        }
    }
    
    return 0;
}
