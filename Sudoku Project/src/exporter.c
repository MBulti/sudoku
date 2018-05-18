
//  Created by Robin Winkler on 21.04.18.
#include <stdio.h>
#include <string.h>
#include "../include/constants.h"
#include "../include/converter.h"
#include "../include/exporter.h"

#define MAXCHARACTERS 255

//http://www.zentut.com/c-tutorial/c-read-text-file/
void writeSudokuToFile(char filename[], struct s_sudoku sudoku){
    FILE *fp;
    fp = fopen(filename, "w");
    if(fp == NULL)
    {
        freopen(filename, "w", fp);
    }

    fprintf(fp, "%s", "moves:");
    fprintf(fp, "%i\n", sudoku.moves);

    int i, j;

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            fprintf(fp, "%c", ((sudoku.a_sudoku[getBlockFromLineAndRow(i, j)][getBlockRowFromRow(j)][getBlockLineFromLine(i)]) + '0'));
        }
        fprintf(fp, "\n");
    }
}
