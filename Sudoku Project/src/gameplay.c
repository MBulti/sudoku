//  Created by Team-FMR on 10.04.18.

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "../include/constants.h"
#include "../include/converter.h"
#include "../include/gameplay.h"
#include "../include/consolePrinter.h"
#include "../include/input.h"
#include "../include/exporter.h"

/*
game rountine
params: struct s_sudoku sudoku
returns: struct s_sudoku sudoku
*/
struct s_sudoku gameRoutine(struct s_sudoku sudoku)
{
    int gameLoop = 1;
    int input = 0;
    const int offset = 9;

    int i, j, k;

    int x = 16;
    int y = 6+offset;

    int row = 0;
    int line = 0;

    int cursorBoundary[2][2] = {{4,offset},{28,12+offset}};

    char path[getPathSize()];

    sudoku.timeStart = time(NULL);
    while (gameLoop)
    {
        CLS;
        //menu strings
        printf("Moves: %i\n", sudoku.moves);
        printf("0-9 -> Wert an Stelle eintragen\n");
        printf("s -> Spielstand speichern und Spiel beenden\n");
        printf("l -> Spielstand laden\n");
        printf("m -> Hauptmenü\n");
        printf("e -> Spiel beenden\n\n");

        if(printSudoku(sudoku))
        {
            gameLoop = 0;
            sudoku.navigation = 3;
            sudoku.timeEnd = time(NULL);
            return sudoku;
        }

        cursorGoTo(x,y);

        input = getMove();
        switch(input)
        {
        case -1: //left
            if(x > cursorBoundary[0][0])
            {
                x-=2;
            }
            break;
        case 1: //right
            if(x < cursorBoundary[1][0])
            {
                x+=2;
            }
            break;
        case 2: //up
            if(y > cursorBoundary[0][1])
            {
                y--;
            }
            break;
        case -2: //down
            if(y < cursorBoundary[1][1])
            {
                y++;
            }
            break;
        case '0' ... '9':
            input -= '0';
            row = (x/2)-cursorBoundary[0][0]+2;
            line = y-cursorBoundary[0][1];
            if(getBlockFromCursor(row,line) != -1 && getRowFromCursor(row,line) != -1 && getLineFromCursor(row,line) != -1 && sudoku.a_originalSudoku[getBlockFromCursor(row,line)][getRowFromCursor(row,line)][getLineFromCursor(row,line)] == 0)
            {
                sudoku.a_sudoku[getBlockFromCursor(row,line)][getRowFromCursor(row,line)][getLineFromCursor(row,line)] = input;
                sudoku.moves++;
            }
            break;
        case 'h':
            solveSudoku(sudoku.a_sudoku);
            //TODO: Hilfe einfügen
            break;
        case 'e':
            sudoku.navigation = 1;
            return sudoku;
            break;
        case 'm':
            sudoku.navigation = -1;
            return sudoku;
            break;
        case 's':
            sudoku.timeEnd = time(NULL);
            getAbsoluteFilePath(path, "files", "saveFile.sudoku");
            writeSudokuToFile(path, sudoku);
            getAbsoluteFilePath(path, "files", "saveOriginalState.sudoku");
            for (i = 0; i < 9; i++)//blocks
            {
                for (j = 0; j < 3; j++)//block lines
                {
                    for (k = 0; k < 3; k++)//block row
                    {
                        sudoku.a_sudoku[i][j][k] = sudoku.a_originalSudoku[i][j][k];
                    }
                }
            }
            writeSudokuToFile(path, sudoku);
            sudoku.navigation = 1;
            return sudoku;
            break;
        default:
            break;
        }
    }

    sudoku.error = 2;
    return sudoku;
}
