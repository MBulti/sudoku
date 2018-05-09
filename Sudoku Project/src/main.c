//  Created by Robin Winkler on 10.04.18.

#include <stdio.h>
#include <stdlib.h>
#if defined(PLATFORM) && PLATFORM == 2
    #include <termios.h>
    #include "../include/linuxLoader.h"
#else
    #include "../include/windowsLoader.h"
#endif

#include "../include/constants.h"
#include "../include/menu.h"
#include "../include/consolePrinter.h"
#include "../include/validator.h"

int main()
{
    int navigation = -1;

    init();

    navigation = mainMenu(navigation);

    while(navigation != 1){
        switch (navigation) {
            //beenden
            case 1:
                CLS;
                printf("Spiel beendet!\n");
                return 0;
                break;
            //neues Spiel
            case 2:
                CLS;
                navigation = newGame();
                CLS;
                break;
            //gewonnen
            case 3:
                CLS;
                printf("Spiel gewonnen!\n");
                printf("Zurück zum Hauptmenü!\n");
                navigation = -1;
                EOL;
                break;
            //Abfrage
            default:
                navigation = mainMenu(navigation);
                break;
        }
    }

    CLS;
    printf("Spiel beendet!\n");
    return 0;
}
