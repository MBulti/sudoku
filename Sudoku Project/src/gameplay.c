//  Created by Fabian Gutendorf on 10.04.18.
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "../include/constants.h"
#include "../include/converter.h"
#include "../include/gameplay.h"
#include "../include/consolePrinter.h"
#include "../include/input.h"
#include "../include/exporter.h"

#if defined(PLATFORM) && PLATFORM == 1
    #include <windows.h>
#endif

int gameRoutine(struct s_sudoku sudoku)
{
    int gameLoop = 1;
    int moves = 0;
    int input = 0;

    int x = 16;
    int y = 11;

    int row = 0;
    int line = 0;

    int cursorBoundary[2][2] = {{4,5},{28,17}};

    while (gameLoop)
    {
        CLS;
        printf("Moves: %i\n", moves);

        if(printSudoku(sudoku))
        {
            gameLoop = 0;
        }

        printf("x: %i, y: %i", (x/2)-cursorBoundary[0][0]+2, y-cursorBoundary[0][1]);
        //getchar();

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
                sudoku.a_sudoku[getBlockFromCursor(row,line)][getRowFromCursor(row,line)][getLineFromCursor(row,line)] = input;
                //printf("\n\n\n\n\n\n\n\n\n Block: %i\n Row: %i\n Line: %i", getBlockFromCursor(row,line), getRowFromCursor(row,line), getLineFromCursor(row,line));
                //getchar();
                moves++;
                break;
            case 'e':
                return 1;
                break;
            case 'm':
                return -1;
                break;
            case 's':
                writeSudokuToFile(sudoku);
                return 1;
                break;
            default:
                break;
        }
    }

    return 3;
}
