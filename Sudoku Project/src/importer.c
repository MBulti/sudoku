//  Created by Robin Winkler on 21.04.18.
#include <stdio.h>
#include <string.h>
#include "../include/constants.h"
#include "../include/importer.h"

#define MAXCHAR 255

//http://www.zentut.com/c-tutorial/c-read-text-file/
struct s_sudoku getSudokuFromFile(char filename[]){
    FILE *fp;
    char str[MAXCHAR];
    struct s_sudoku sudoku;
    int i, j = 0;

    fp = fopen(filename, "r");
    if (fp == NULL){
        //printf("Could not open file %s",filename);
        sudoku.error = 1;
        return sudoku;
    }
    i=0;
    while (fgets(str, MAXCHAR, fp) != NULL){
        for(j=0; j<(strlen(str)); j++){
            if(str[j] != '\n'){
                sudoku.a_sudoku[getBlockFromLineAndRow(j,i)][getBlockLineFromLine(j)][getBlockRowFromRow(i)] = (int)str[j] - '0'; //minus 48 da die numbern im ascii code bei 48 bzw bei dem zeichen 0 anfangen
                //printf("Test: %c, Block: %i, Spalte: %i, Zeile: %i\n", str[j], getBlockFromLineAndRow(j,i), getBlockLineFromLine(j), getBlockRowFromRow(i));
            }
        }
        i++;
        //printf("%s", str);
        //printf("Lenght: %i\n", strlen(str));
    }
    fclose(fp);

    //Debug
    //printf("%i", sudoku.a_sudoku[1][2][2]);
    //getchar();

    return sudoku;
}
