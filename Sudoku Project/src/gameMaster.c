//  Created by Robin Winkler on 10.04.18.
#include <stdio.h>
#include <unistd.h>
#include "../include/constants.h"
#include "../include/gameMaster.h"
#include "../include/consolePrinter.h"
#include "../include/validator.h"

int mainMenu(int status)
{
    char selection = '\0';

    CLS;

    if (status == 0) {
        printf("Falsche Eingabe entdeckt!\n");
    }

    printf("Hauptmenü:\n");
    printf("Bitte wählen:\n");
    printf("n - neues Spiel\n");
    printf("e - Spiel beenden\n");
    printf("Eingabe: ");
    fflush(stdout);
    read(0, &selection, 4);

    return validateMenuInput(selection);
}

int newGame()
{
    char selection = '\0';

    printf("Levelauswahl:\n");
    printf("Bitte wählen:\n");
    printf("1 - leichtes Level spielen\n");
    printf("2 - mittleres Level spielen\n");
    printf("3 - schweres Level spielen\n");
    printf("z - Zurück zum Hauptmenü\n");
    printf("Eingabe: ");
    fflush(stdout);
    read(0, &selection, 4);
    CLS;

    switch (selection) {
        case '1':
            printf("leichtes Level ausgewählt.\n");
            //printSudoku();
            break;
        case '2':
            printf("mittleres Level ausgewählt.\n");
            break;
        case '3':
            printf("schweres Level ausgewählt.\n");
            break;
        case 'z':
            return -1;
            break;
        default:
            return 0;
            break;
    }

    return 0;
}


