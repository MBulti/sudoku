//  Created by Robin Winkler on 10.04.18.
#include <stdio.h>
#include <unistd.h>
#include "../include/constants.h"
#include "../include/gameplay.h"
#include "../include/menu.h"
#include "../include/consolePrinter.h"
#include "../include/validator.h"
#include "../include/importer.h"
#include "../include/input.h"

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
    //https://cboard.cprogramming.com/c-programming/88690-path-file-relative-program.html
    char path[MAX_PATH];
    GetCurrentDirectory(sizeof(path), path);

    printf("Levelauswahl:\n");
    printf("Bitte wählen:\n");
    printf("1 - leichtes Level spielen\n");
    printf("2 - mittleres Level spielen\n");
    printf("3 - schweres Level spielen\n");
    printf("z - Zurück zum Hauptmenü\n");
    printf("Eingabe: ");
    selection = getInput();

    CLS;

    sudoku = getSudokuFromFile(strcat(path, "\\files\\testFile.sudoku"));

    switch (selection) {
        case '1':
            printf("leichtes Level ausgewählt.\n");
            return gameRoutine(sudoku);
            break;
        case '2':
            printf("mittleres Level ausgewählt.\n");
            return gameRoutine(sudoku);
            break;
        case '3':
            printf("schweres Level ausgewählt.\n");
            return gameRoutine(sudoku);
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
