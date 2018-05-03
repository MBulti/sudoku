//  Created by Robin Winkler on 03.05.18.
#include "../include/converter.h"

int getBlockFromLine(int i)
{
    int a_ConvertLineNumberToBlock[9] = { 0, 0, 0, 3, 3, 3, 6, 6, 6};
    return a_ConvertLineNumberToBlock[i];
}

int getBlockFromRow(int i)
{
    int a_ConvertRowNumberToBlock[9] = { 0, 0, 0, 1, 1, 1, 2, 2, 2};
    return a_ConvertRowNumberToBlock[i];
}

int getBlockLineFromLine(int i)
{
    int a_ConvertLineNumberToLine[9] = { 0, 1, 2, 0, 1, 2, 0, 1, 2};
    return a_ConvertLineNumberToLine[i];
}

int getBlockRowFromRow(int i)
{
    int a_ConvertRowNumberToRow[9] = { 0, 1, 2, 0, 1, 2, 0, 1, 2};
    return a_ConvertRowNumberToRow[i];
}

//Arraymapping (row & line -> block)
int getBlockFromLineAndRow(int row, int line){
    //Arraymapping (row & line -> block)
    int a_getBlock[9][9] = {
        {0,0,0,1,1,1,2,2,2},
        {0,0,0,1,1,1,2,2,2},
        {0,0,0,1,1,1,2,2,2},
        {3,3,3,4,4,4,5,5,5},
        {3,3,3,4,4,4,5,5,5},
        {3,3,3,4,4,4,5,5,5},
        {6,6,6,7,7,7,8,8,8},
        {6,6,6,7,7,7,8,8,8},
        {6,6,6,7,7,7,8,8,8},
    };
    return a_getBlock[row][line];
}
