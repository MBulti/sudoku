//  Created by Fabian Gutendorf on 10.04.18.
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "../include/constants.h"
#include "../include/converter.h"
#include "../include/gameplay.h"
#include "../include/consolePrinter.h"
#include "../include/input.h"
#include "../include/exporter.h"

struct s_sudoku gameRoutine(struct s_sudoku sudoku)
{
    int gameLoop = 1;
    sudoku.moves = 0;
    int input = 0;
    const int offset = 9;

    int x = 16;
    int y = 6+offset;

    int row = 0;
    int line = 0;

    int cursorBoundary[2][2] = {{4,offset},{28,12+offset}};

    char path[getPathSize()];
    getAbsoluteFilePath(path, "files", "saveFile.sudoku");

    sudoku.timeStart = time(NULL);
    while (gameLoop)
    {
        CLS;
        printf("Moves: %i\n", sudoku.moves);

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
                //TODO: zusätzlich Originales Sudoku abspeichern (für Lösung)
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
