//  Created by Robin Winkler on 10.04.18.

#include <stdio.h>
#include <stdlib.h>
#include "../include/constants.h"
#include "../include/gameMaster.h"
#include "../include/consolePrinter.h"
#include "../include/validator.h"

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
            //new Game
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
