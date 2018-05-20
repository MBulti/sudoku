//  Created by Team-FMR on 10.04.18.

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "../include/constants.h"
#include "../include/gameplay.h"
#include "../include/menu.h"
#include "../include/consolePrinter.h"
#include "../include/validator.h"
#include "../include/importer.h"
#include "../include/input.h"

/*
show main menu
params: int previous status
returns: int validated input
*/
int mainMenu(int status)
{
    char selection = '\0';

    CLS;

    if (status == 0)
    {
        printf("Falsche Eingabe entdeckt!\n");
    }

    printf("Hauptmenü:\n");
    printf("Bitte wählen:\n");
    printf("n - neues Spiel\n");
    printf("l - letztes Spiel laden\n");
    printf("e - Spiel beenden\n");
    printf("Eingabe: ");
    selection = getInput();

    return validateMenuInput(selection);
}

/*
starts new game
params: struct s_sudoku sudoku
returns: struct s_sudoku sudoku
*/
struct s_sudoku newGame(struct s_sudoku sudoku)
{
    char selection = '\0';
    char path[getPathSize()];

    printf("Levelauswahl:\n");
    printf("Bitte wählen:\n");
    printf("1 - leichtes Level spielen\n");
    printf("2 - mittleres Level spielen\n");
    printf("3 - schweres Level spielen\n");
    printf("z - Zurück zum Hauptmenü\n");
    printf("Eingabe: ");
    selection = getInput();

    CLS;

    switch (selection)
    {
    case '1':
        printf("leichtes Level ausgewählt.\n");
        getAbsoluteFilePath(path, "files", "relax.sudoku");
        break;
    case '2':
        printf("mittleres Level ausgewählt.\n");
        getAbsoluteFilePath(path, "files", "genius.sudoku");
        break;
    case '3':
        printf("schweres Level ausgewählt.\n");
        getAbsoluteFilePath(path, "files", "mastermind.sudoku");
        break;
    case '0':
        //EASTER EGG
        CLS;
        printf("Geheimes Easter Egg gefunden!\n\n");
        getAbsoluteFilePath(path, "files", "easterEgg.sudoku");
        sudoku = getSudokuFromFile(path, sudoku);
        printSudoku(sudoku);
        getInput();
        sudoku.navigation = -1;
        return sudoku;
        break;
    case 'z':
        sudoku.navigation = -1;
        return sudoku;
        break;
    default:
        sudoku.navigation = 0;
        return sudoku;
        break;
    }
    sudoku = getSudokuFromFile(path, sudoku);
    if(sudoku.error != 0)
    {
        return sudoku;
    }
    return gameRoutine(sudoku);
}
