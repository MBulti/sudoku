//  Created by Team-FMR on 10.04.18.

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../include/constants.h"
#include "../include/consolePrinter.h"
#include "../include/validator.h"

/*
prints sudoku
params: struct s_sudoku sudoku
returns: int is correct filled
*/
int printSudoku(struct s_sudoku sudoku)
{
    char a_visualSudoku[9][3][3]; //The char sudoku that is printed on the console
    int i, j, k, l;
    int fullyFilled = 1; //Is = 0 if there is at least one 0 in the sudoku (empty field)

    //Parse the sudoku array and convert every integer of the parameter sudoku into a char
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
                }
                else
                {
                    a_visualSudoku[k][i][j] = sudoku.a_sudoku[k][i][j] + '0';
                }
            }
        }
    }

    //is the sudoku completely solved?
    if(fullyFilled == 1 && checkForValidSolution(sudoku.a_sudoku) == 1)
    {
        return 1;
    }

    //if not, then print the current sudoku field with red colors for the non-editable digits and white for the editable digits or the field
    else
    {
        printf("     a b c   d e f   g h i  \n");
        printf("   +-------+-------+-------+\n");
        i = 1;
        for (k = 0; k < 9; k += 3)//blocks
        {
            for (j = 0; j < 3; j++)//block lines
            {
                printf("%i  ", i);
                for (l = 0; l < 3; l++)//block row
                {
                    printf("| ");
                    if(sudoku.a_originalSudoku[k+l][0][j]) //If there is an entry in the original sudoku array the printed digit will be red, else white
                    {
                        printf(RED);
                    }
                    else
                    {
                        printf(WHITE);
                    }
                    printf("%c ", a_visualSudoku[k+l][0][j]);
                    if(sudoku.a_originalSudoku[k+l][1][j])
                    {
                        printf(RED);
                    }
                    else
                    {
                        printf(WHITE);
                    }
                    printf("%c ", a_visualSudoku[k+l][1][j]);
                    if(sudoku.a_originalSudoku[k+l][2][j])
                    {
                        printf(RED);
                    }
                    else
                    {
                        printf(WHITE);
                    }
                    printf("%c ", a_visualSudoku[k+l][2][j]);
                    printf(WHITE);
                }
                printf("|\n");
                i++;
            }
            printf("   +-------+-------+-------+\n");
        }
        return 0;
    }
    return 0;
}
