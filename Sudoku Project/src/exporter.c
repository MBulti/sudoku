//  Created by Team-FMR on 21.04.18.

#include <stdio.h>
#include <string.h>
#include "../include/constants.h"
#include "../include/converter.h"
#include "../include/exporter.h"

/*
export sudoku to file
params: char[] filename, struct s_sudoku sudoku
returns: void
*/
//http://www.zentut.com/c-tutorial/c-read-text-file/
void writeSudokuToFile(char filename[], struct s_sudoku sudoku)
{
    FILE *fp;
    fp = fopen(filename, "w");
    if(fp == NULL)
    {
        //if the files could not be found and opened, create a new file with the given name and open it
        freopen(filename, "w", fp);
    }

    //writing of the amount of moves and time so far
    fprintf(fp, "%s", "moves:");
    fprintf(fp, "%i\n", sudoku.moves);

    fprintf(fp, "%s", "timeElapsed:");
    fprintf(fp, "%i\n", (int)difftime(sudoku.timeEnd, sudoku.timeStart));

    int i, j;

    //write every digit field of the sudoku board into the file
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            fprintf(fp, "%c", ((sudoku.a_sudoku[getBlockFromLineAndRow(i, j)][getBlockRowFromRow(j)][getBlockLineFromLine(i)]) + '0'));
        }
        fprintf(fp, "\n");
    }
}
