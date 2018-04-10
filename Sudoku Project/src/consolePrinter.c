#include "consolePrinter.h"
#include <stdlib.h>

int printSudoku()
{
    srand(time(NULL));
    int a_sudoku[3][3][9];
    char a_sudokuPrint[3][3][9];
    int i, j, k;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 9; k++)
            {
                a_sudoku[i][j][k] = rand() % 10;
                if (a_sudoku[i][j][k] == 0)
                {
                    a_sudokuPrint[i][j][k] = '.';
                }
                else
                {
                    a_sudokuPrint[i][j][k] = a_sudoku[i][j][k] + '0';
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
            printf("| %c %c %c | %c %c %c | %c %c %c |\n", a_sudokuPrint[0][j][k], a_sudokuPrint[1][j][k],
                                                           a_sudokuPrint[2][j][k], a_sudokuPrint[0][j][k+1],
                                                           a_sudokuPrint[1][j][k+1], a_sudokuPrint[2][j][k+1],
                                                           a_sudokuPrint[0][j][k+2], a_sudokuPrint[1][j][k+2],
                                                           a_sudokuPrint[2][j][k+2]);
        }
        printf("+-------+-------+-------+\n");
    }
}
