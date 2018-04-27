//  Created by Fabian Gutendorf on 10.04.18.
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../include/consolePrinter.h"
#include "../include/constants.h"

void printSudoku(int field[9][3][3])
{
    //CLS;
    char a_sudokuPrint[9][3][3];
    int i, j, k;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 9; k++)
            {
                if (field[k][i][j] == 0)
                {
                    a_sudokuPrint[k][i][j] = '.';
                }
                else
                {
                    a_sudokuPrint[k][i][j] = field[k][i][j] + '0';
                }
            }
        }
    }

    //Debug
    //printf("%i", field[1][2][2]);
    //printf("%c", a_sudokuPrint[1][2][2]);
    //getchar();

    //String für die Ausgabe auf der Konsole
    printf("Zum Füllen eines Feldes erst die Spalte wählen, dann die Zeile und zum Schluss den einzutragenden Wert!\n");
    printf("Beispiel: e48\n\n\n\n\n");
    printf("     a b c   d e f   g h i  \n");
    printf("   +-------+-------+-------+\n");

    i = 1;
    for (k = 0; k < 9; k += 3)
    {
        for (j = 0; j < 3; j++)
        {
            //printf("a_sudokuPrint[%i][%i][%i] = %c", k+1, 2, j, a_sudokuPrint[k+1][2][j]);
            //getchar();
            printf("%i  | %c %c %c | %c %c %c | %c %c %c |\n", i,
                   a_sudokuPrint[k][0][j], a_sudokuPrint[k][1][j], a_sudokuPrint[k][2][j],
                   a_sudokuPrint[k+1][0][j], a_sudokuPrint[k+1][1][j], a_sudokuPrint[k+1][2][j],
                   a_sudokuPrint[k+2][0][j], a_sudokuPrint[k+2][1][j], a_sudokuPrint[k+2][2][j]);
            i++;
        }
        printf("   +-------+-------+-------+\n\n");
    }
}
