#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../include/consolePrinter.h"

void printSudoku()
{
    srand(time(NULL));
    int a_sudoku[9][3][3];
    char a_sudokuPrint[9][3][3];
    int i, j, k;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 9; k++)
            {
                a_sudoku[k][i][j] = rand() % 10;
                if (a_sudoku[k][i][j] == 0)
                {
                    a_sudokuPrint[k][i][j] = '.';
                }
                else
                {
                    a_sudokuPrint[k][i][j] = a_sudoku[k][i][j] + '0';
                }
            }
        }
    }

    //String für die Ausgabe auf der Konsole

    printf("+-------+-------+-------+\n");


    for (k = 0; k < 9; k += 3)
    {
        for (j = 0; j < 3; j++)
        {
            printf("| %c %c %c | %c %c %c | %c %c %c |\n", a_sudokuPrint[k][0][j], a_sudokuPrint[k][1][j],
                                                           a_sudokuPrint[k][2][j], a_sudokuPrint[k+1][0][j],
                                                           a_sudokuPrint[k+1][1][j], a_sudokuPrint[k+2][2][j],
                                                           a_sudokuPrint[k+2][0][j], a_sudokuPrint[k+2][1][j],
                                                           a_sudokuPrint[k+2][2][j]);
        }
        printf("+-------+-------+-------+\n");
    }
}
