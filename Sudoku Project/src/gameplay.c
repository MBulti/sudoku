//  Created by Fabian Gutendorf on 10.04.18.
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "../include/constants.h"
#include "../include/gameplay.h"
#include "../include/consolePrinter.h"
#include "../include/input.h"

#if defined(PLATFORM) && PLATFORM == 1
    #include <windows.h>
#endif

int waitForInput()
{
    return 0;
}

int gameRoutine(struct s_sudoku sudoku)
{
    int gameLoop = 1;
    int moves = 0;

    int x = 16;
    int y = 10;

    int cursorBoundary[2][2] = {{4,4},{28,16}};

    while (gameLoop)
    {
        CLS;
        printf("Moves: %i\n", moves);

        if(printSudoku(sudoku)){
            gameLoop = 0;
        }

        //printf("x: %i, y: %i", x, y);
        //getchar();

        cursorGoTo(x,y);

        //TODO: cursor restriction to play area, exit functionality, input send to array
        switch(getMove())
        {
            case -1: //left
                if(x > cursorBoundary[0][0]){
                     x-=2;
                }
                break;
            case 1: //right
                if(x < cursorBoundary[1][0]){
                     x+=2;
                }
                break;
            case 2: //up
                if(y > cursorBoundary[0][1]){
                     y--;
                }
                break;
            case -2: //down
                if(y < cursorBoundary[1][1]){
                     y++;
                }
                break;
            default:

                break;
        }

        moves++;
    }

    return 3;
}
