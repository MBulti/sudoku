//  Created by Robin Winkler on 10.04.18.
#include <stdio.h>
#include <unistd.h>
#include "../include/constants.h"
#include "../include/gameplay.h"
#include "../include/menus.h"
#include "../include/consolePrinter.h"
#include "../include/validator.h"
#include "../include/importer.h"

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
    selection = getInput();

    return validateMenuInput(selection);
}

int newGame()
{
    char selection = '\0';
    struct s_sudoku sudoku;

    printf("Levelauswahl:\n");
    printf("Bitte wählen:\n");
    printf("1 - leichtes Level spielen\n");
    printf("2 - mittleres Level spielen\n");
    printf("3 - schweres Level spielen\n");
    printf("z - Zurück zum Hauptmenü\n");
    printf("Eingabe: ");
    selection = getInput();

    CLS;

    sudoku = getSudokuFromFile("E:\\Sudoku Project\\files\\testFile.sudoku");

    switch (selection) {
        case '1':
            printf("leichtes Level ausgewählt.\n");
            gameRoutine(sudoku);
            break;
        case '2':
            printf("mittleres Level ausgewählt.\n");
            gameRoutine(sudoku);
            break;
        case '3':
            printf("schweres Level ausgewählt.\n");
            gameRoutine(sudoku);
            break;
        case 'z':
            return -1;
            break;
        default:
            return 0;
            break;
    }

    return 1;
}

char getInput(){
    char selection = '\0';

    #if defined(PLATFORM) && PLATFORM == 2
        fflush(stdout);
        read(0, &selection, 4);
    #else
        selection = getchar();
        EOL;
    #endif
    return selection;
}
