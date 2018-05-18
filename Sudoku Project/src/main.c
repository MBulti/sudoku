//  Created by Team-FMR on 10.04.18.

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
#include "../include/importer.h"
#include "../include/gameplay.h"

/*
the magic begins here
params: -
returns: int prozess code
*/
int main()
{
    int navigation = -1;
    char path[getPathSize()];
    struct s_sudoku sudoku = {0};
    struct s_sudoku originalSudoku = {0};

    int i, j, k;

    //used to do os based configurations
    init();

    navigation = mainMenu(navigation);

    while(navigation != 1){
        switch (navigation) {
            //exit game
            case 1:
                CLS;
                printf("Spiel beendet!\n");
                return 0;
                break;
            //new game
            case 2:
                CLS;
                sudoku = newGame(sudoku);
                navigation = sudoku.navigation;
                CLS;
                break;
            //win game
            case 3:
                CLS;
                if(sudoku.moves == 1)
                {
                    printf("Spiel in %i Zug gewonnen!\n", sudoku.moves);
                }else{
                    printf("Spiel in %i Zügen gewonnen!\n", sudoku.moves);
                }

                printf("Lösungsdauer: %i sec.!\n", (int)(difftime(sudoku.timeEnd, sudoku.timeStart)+sudoku.timeElapsed));
                printf("Zurück zum Hauptmenü!\n");
                sudoku.moves = 0;
                sudoku.timeElapsed = 0.0;
                navigation = -1;
                EOL;
                break;
            //load game
            case 4:
                CLS;
                navigation = -1; //reset to default value to check for an error if one occured
                getAbsoluteFilePath(path, "files", "saveFile.sudoku");
                sudoku = getSudokuFromFile(path, sudoku);
                getAbsoluteFilePath(path, "files", "saveOriginalState.sudoku");
                originalSudoku = getSudokuFromFile(path, originalSudoku);
                if(originalSudoku.error == 0) {
                    sudoku.error = originalSudoku.error; //set the error on original sudoku
                }
                for (i = 0; i < 9; i++)//blocks
                {
                    for (j = 0; j < 3; j++)//block lines
                    {
                        for (k = 0; k < 3; k++)//block row
                        {
                            sudoku.a_originalSudoku[i][j][k] = originalSudoku.a_sudoku[i][j][k];
                        }
                    }
                }
                if(sudoku.error == 0){
                    sudoku = gameRoutine(sudoku);
                    navigation = sudoku.navigation;
                }
                CLS;
                break;
            //default navigation (with error handling)
            default:
                if(sudoku.error != 0)
                {
                    CLS;
                    printf("Unbekannter Fehler aufgetreten\nCode: %i",sudoku.error);
                    return 1;
                }
                navigation = mainMenu(navigation);
                break;
        }
    }

    CLS;
    printf("Spiel beendet!\n");
    return 0;
}
