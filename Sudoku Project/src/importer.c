//  Created by Robin Winkler on 21.04.18.
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "../include/constants.h"
#include "../include/converter.h"
#include "../include/importer.h"

#define MAXCHARACTERS 255

//http://www.zentut.com/c-tutorial/c-read-text-file/
struct s_sudoku getSudokuFromFile(char filename[], struct s_sudoku sudoku){
    FILE *fp;
    char str[MAXCHARACTERS];
    int i, j = 0;

    fp = fopen(filename, "r");
    if (fp == NULL){
        sudoku.error = 1;
        return sudoku;
    }

    i=0;
    while (fgets(str, MAXCHARACTERS, fp) != NULL){
        for(j=0; j<(strlen(str)); j++){
            if(str[j] != '\n' && (int)str[j] != 13){
                sudoku.a_sudoku[getBlockFromLineAndRow(i,j)][getBlockLineFromLine(j)][getBlockRowFromRow(i)] = (int)str[j] - '0'; //minus 48 due to the fact that the char 0 begins in the ascii table with the value 48
                sudoku.a_originalSudoku[getBlockFromLineAndRow(i,j)][getBlockLineFromLine(j)][getBlockRowFromRow(i)] = (int)str[j] - '0'; //clone of original state to know wich values come from the user and wich not
            }
        }
        i++;
    }
    fclose(fp);

    return sudoku;
}
