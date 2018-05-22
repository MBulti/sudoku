//  Created by Team-FMR on 21.04.18.

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include "../include/constants.h"
#include "../include/converter.h"
#include "../include/importer.h"

/*
import sudoku from file
params: char[] filename, struct s_sudoku sudoku
returns: struct s_sudoku sudoku
*/
//http://www.zentut.com/c-tutorial/c-read-text-file/
struct s_sudoku getSudokuFromFile(char filename[], struct s_sudoku sudoku)
{
    FILE *fp;
    char str[MAXCHARACTERS];
    int i, j = 0;

    int buffer[8] = {0};

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        sudoku.error = 1;
        return sudoku;
    }

    i=0;
    while (fgets(str, MAXCHARACTERS, fp) != NULL)
    {
        j = 0;
        buffer[0] = 0;
        if(str[0] == 'm' && str[1] == 'o' && str[2] == 'v' && str[3] == 'e' && str[4] == 's' && str[5] == ':')
        {
            while(str[j+6] != '\n' && (int)str[j+6] != 13)
            {
                //printf("char: %c, int: %i\n", str[j+6], str[j+6]);
                buffer[j+1] = str[j+6] - '0';
                j++;
                //buffer[0] is reserved for the length of the number
                buffer[0] = j+1;
            }
            for(j=buffer[0]-1; j>0; j--)
            {
                //manual string to int conversation
                sudoku.moves += buffer[buffer[0]-j] * pow(10.0, j-1);
                //printf("%i mal 10 hoch %i (%i) = %i\n", buffer[buffer[0]-j], j, (int)pow(10.0, j-1), sudoku.moves);
            }
            //printf("moves: %i", sudoku.moves);
            //getchar();
        }
        else if(str[0] == 't' && str[1] == 'i' && str[2] == 'm' && str[3] == 'e' && str[4] == 'E' && str[5] == 'l' && str[6] == 'a' && str[7] == 'p' && str[8] == 's' && str[9] == 'e' && str[10] == 'd' && str[11] == ':')
        {
            while(str[j+12] != '\n' && (int)str[j+12] != 13)
            {
                //code duplication!
                //printf("char: %c, int: %i\n", str[j+12], str[j+12]);
                buffer[j+1] = str[j+12] - '0';
                j++;
                //buffer[0] is reserved for the length of the number
                buffer[0] = j;
                //printf("buffer[%i] = %i\n", j, buffer[j]);
            }
            for(j=buffer[0]; j>0; j--)
            {
                //printf("buffer[%i] = %i\n", buffer[0]+1-j, buffer[buffer[0]+1-j]);
                //manual string to int conversation
                sudoku.timeElapsed += buffer[buffer[0]+1-j] * pow(10.0, j-1);
                //printf("%i mal 10 hoch %i (%i) = %lf\n", buffer[buffer[0]+1-j], j, (int)pow(10.0, j), sudoku.timeElapsed);
            }
            //printf("timeElapsed: %lf", sudoku.timeElapsed);
            //getchar();
        }
        else
        {
            for(; j<(strlen(str)); j++)
            {
                if(str[j] != '\n' && (int)str[j] != 13)
                {
                    //copy sudoku form file
                    sudoku.a_sudoku[getBlockFromLineAndRow(i,j)][getBlockLineFromLine(j)][getBlockRowFromRow(i)] = (int)str[j] - '0'; //minus 48 due to the fact that the char 0 begins in the ascii table with the value 48
                    sudoku.a_originalSudoku[getBlockFromLineAndRow(i,j)][getBlockLineFromLine(j)][getBlockRowFromRow(i)] = (int)str[j] - '0'; //clone of original state to know wich values come from the user and wich not
                    sudoku.a_validSudoku[getBlockFromLineAndRow(i,j)][getBlockLineFromLine(j)][getBlockRowFromRow(i)] = (int)str[j] - '0'; //clone of original state to get a valid solution
                }
            }
            i++;
        }
    }
    fclose(fp);

    return sudoku;
}
