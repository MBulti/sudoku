//  Created by Fabian Gutendorf on 10.04.18.
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "../include/constants.h"
#include "../include/gameplay.h"
#include "../include/consolePrinter.h"

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

    int i, j, k, inputLength;
    char input[3];
    //Debug
    //printf("%i", sudoku.a_sudoku[1][2][2]);
    //getchar();

    printSudoku(sudoku);
    while (gameLoop)
    {
        CLS;
        printf("Moves: %i\n", moves);
        printSudoku(sudoku);
        //wait(1);
        //TODO: in input.c als Funktion packen
        inputLength = read(0, &input, 9);

        if (input[0] == 'q')
        {
            printf("Spiel wird beendet!");
            gameLoop = 0;
        }
        else if (inputLength != 4)
        {
            printf("Ungueltige Laenge der Eingabe!\n");
        }
        else
        {
            //printf("Hello!");
            switch(input[0])
            {
            case 'a'...'c':
                k = 1;
                break;
            case 'd'...'f':
                k = 2;
                break;
            case 'g'...'i':
                k = 3;
                break;
            default:
                //printf("Bla");
                break;
            }
            //printf("k: %i\n", k);

            i = k;
            k = input[1] - '0';
            //printf("k: %i\n", k);
            k--;
            //printf("k: %i\n", k);
            k = (int)(k / 3);
            //printf("k: %i\n", k);
            k = 3 * k;
            //printf("k: %i\n", k);
            k = i + k;
            //printf("k: %i\n", k);
            k--;
            //printf("k: %i\n", k);

            //k = k + (3 * (int)((input[1] - '0') - 1) / 3);

            //printf("k: %i", k);

            i = (int)input[0];
            //printf("i: %i\n", i);
            i--;
            //printf("i: %i\n", i);
            i = i % 3;
            //printf("i: %i\n", i);

            j = input[1] - '0';
            //printf("j: %i\n", j);
            j--;
            //printf("j: %i\n", j);
            j = j % 3;
            //printf("j: %i\n", j);

            printf("k: %i, i: %i, j: %i\n", k, i, j);
            //printf("j: %i\n", j);
            sudoku.a_sudoku[k][i][j] = input[2] - '0';
        }

        if(printSudoku(sudoku)){
            return 3;
        }
        moves++;
    }

    return 0;
}
