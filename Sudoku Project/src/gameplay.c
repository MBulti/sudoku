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
    int time_elapsed = 0.0;

    //Debug
    //printf("%i", sudoku.a_sudoku[1][2][2]);
    //getchar();

    while (gameLoop) {
        CLS;
        time_elapsed++;
        printf("Time elapsed: %i\n", time_elapsed);
        printSudoku(sudoku.a_sudoku);
        #if defined(PLATFORM) && PLATFORM == 2
            sleep(1);
        #else
            Sleep(1000);
        #endif
    }

    return 0;
}

void sudokuSolving()
{
    srand(time(NULL));
    int a_sudoku[9][3][3];
    //          Unused Variable Warning
    int i, j, k, /*inputValue = 0,*/ inputLength;
    char input[3];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 9; k++)
            {
                a_sudoku[k][i][j] = rand() % 10;
            }
        }
    }
    input[0] = 'q';
    printSudoku(a_sudoku);

    do
    {
        inputLength = read(0, &input, 9);

        if (input[0] == 'q')
        {
            printf("Spiel wird beendet!");
        }
        else if (inputLength != 4)
        {
            printf("Ungueltige Laenge der Eingabe!\n");
        }
        else
        {
            printf("Hello!");
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
                    printf("Bla");
                    break;
            }
            printf("k: %i", k);

            i = k;
            k = input[1] - '0';
            k--;
            k = (int)(k / 3);
            k = 3 * k;
            k = i + k;
            k--;

            //k = k + (3 * (int)((input[1] - '0') - 1) / 3);

            //printf("k: %i", k);

            i = (int)input[0];
            i--;
            i = i % 3;

            j = input[1] - '0';
            j--;
            j = j % 3;

            //printf("k: %i, i: %i, j: %i", k, i, j);
            a_sudoku[k][i][j] = input[2] - '0';
        }

        printSudoku(a_sudoku);

    }while(input[0] != 'q');

    printf("%c %c %c", input[0], input[1], input[2]);
}

int checkForValidSolution(int a_Sudoku[9][3][3]) //check for a correct solution
{
    //sudoku print [x][y][z]
    //int a_assistArray[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int assistNumber = 1;
    int block = 0;
    int line = 0;
    int row = 0;
    int found = 0;
    for(block = 0; block < 9; block++) //foreach block in the sudoku
    {
        assistNumber = 1; //number should be reseted after each block
        for(line = 0; line < 3; line++)
        {
            for(row = 0; row < 3; row++)
            {
                if(a_Sudoku[block][line][row] == assistNumber)
                {
                    found = 1;
                    assistNumber++; //increase number if it was found in one of the lines
                    break;
                }
            }
        }
    }

    return 1;
}

int checkForValidLine(int array[9])
{
    return 1;
}

