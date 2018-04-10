#define CLS system("cls")

//  Created by Robin Winkler on 10.04.18.
#include "constants.h"
#include "gameMaster.h"

int mainMenu(int status)
{
    char selection[] = "\0";

    CLS;

    if (status == 0) {
        printf("Falsche Eingabe entdeckt!\n");
    }

    printf("Hauptmenü:\n");
    printf("Bitte wählen:\n");
    printf("n - neues Spiel\n");
    printf("e - Spiel beenden\n");
    printf("Eingabe: ");
    scanf("%s", selection);

    /*
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
    */

    return validateMenuInput(selection);
}

int newGame()
{
    int gameLoop = 1;

    while (gameLoop) {

    }
}
