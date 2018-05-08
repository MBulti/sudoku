//  Created by Fabian Gutendorf on 10.04.18.
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../include/constants.h"
#include "../include/consolePrinter.h"
#include "../include/validator.h"

/*
prints sudoku
params: int array[9][3][3] - sudoku
returns: nothing
*/
int printSudoku(struct s_sudoku sudoku)
{
    char a_visualSudoku[9][3][3];
    int i, j, k;
    int fullyFilled = 1;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 9; k++)
            {
                if (sudoku.a_sudoku[k][i][j] == 0)
                {
                    a_visualSudoku[k][i][j] = '.';
                    fullyFilled = 0;
                }else{
                    a_visualSudoku[k][i][j] = sudoku.a_sudoku[k][i][j] + '0';
                }
            }
        }
    }

    if(fullyFilled == 1 && checkForValidSolution(sudoku.a_sudoku) == 1)
    {
        return 1;
    }else{
        //Debug
        //printf("%i\n", sudoku.a_sudoku[1][0][0]);
        //printf("%c\n", a_visualSudoku[1][0][0]);
        //getchar();

        //String für die Ausgabe auf der Konsole
        printf("Zum Füllen eines Feldes erst die Spalte wählen, dann die Zeile und zum Schluss den einzutragenden Wert!\n\n");
        printf("     a b c   d e f   g h i  \n");
        printf("   +-------+-------+-------+\n");

        i = 1;
        for (k = 0; k < 9; k += 3)
        {
            for (j = 0; j < 3; j++)
            {
                //printf("a_visualSudoku[%i][%i][%i] = %c", k+1, 2, j, a_visualSudoku[k+1][2][j]);
                //getchar();
                printf("%i  | %c %c %c | %c %c %c | %c %c %c |\n", i,
                       a_visualSudoku[k][0][j], a_visualSudoku[k][1][j], a_visualSudoku[k][2][j],
                       a_visualSudoku[k+1][0][j], a_visualSudoku[k+1][1][j], a_visualSudoku[k+1][2][j],
                       a_visualSudoku[k+2][0][j], a_visualSudoku[k+2][1][j], a_visualSudoku[k+2][2][j]);
                i++;
            }
            printf("   +-------+-------+-------+\n");
        }
        return 0;
    }
    return 0;
}
