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
#include "../include/menus.h"
#include "../include/consolePrinter.h"
#include "../include/validator.h"

int main()
{
    int navigation = -1;

    init();

    navigation = mainMenu(navigation);

    while(navigation != 1){
        switch (navigation) {
            //exit
            case 1:
                CLS;
                printf("Spiel beendet!\n");
                return 0;
                break;
            //new Game
            case 2:
                CLS;
                navigation = newGame();
                CLS;
                break;

            default:
                navigation = mainMenu(navigation);
                break;
        }
    }

    CLS;
    printf("Spiel beendet!\n");
    return 0;
}
