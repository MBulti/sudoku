//  Created by Robin Winkler on 10.04.18.

#include <stdio.h>
#include <stdlib.h>
//#include <termios.h>
#include "../include/constants.h"
#include "../include/gameMaster.h"
#include "../include/consolePrinter.h"
#include "../include/validator.h"

int main()
{
    int navigation = -1;
/*
    //http://blog.eduardofleury.com/archives/2007/11/16
    struct termios tios, orig_tios;    // terminal settings

    //Get current terminal settings
    if (tcgetattr(0, &orig_tios)){
        printf("Error getting current terminal settingsn");
        return 3;
    }

    // Copy that to "tios" and play with it
    tios = orig_tios;

    // We want to disable the canonical mode
    tios.c_lflag &= ~ICANON;

    // And make sure ECHO is enabled
    tios.c_lflag |= ECHO;

    // Apply our settings
    if (tcsetattr(0, TCSANOW, &tios)){
        printf("Error applying terminal settings\n");
        return 3;
    }

    // Check whether our settings were correctly applied
    if (tcgetattr(0, &tios)){
        tcsetattr(0, TCSANOW, &orig_tios);
        printf("Error while asserting terminal settings\n");
        return 3;
    }

    if ((tios.c_lflag & ICANON) || !(tios.c_lflag & ECHO)) {
        tcsetattr(0, TCSANOW, &orig_tios);
        printf("Could not apply all terminal settings\n");
        return 3;
    }
*/
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

    return 0;
}
