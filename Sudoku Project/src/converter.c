//  Created by Team-FMR on 03.05.18.

#include "../include/converter.h"

/*
get block number from line
params: int line
returns: int block number
*/
int getBlockFromLine(int i)
{
    int a_ConvertLineNumberToBlock[9] = { 0, 0, 0, 3, 3, 3, 6, 6, 6};
    return a_ConvertLineNumberToBlock[i];
}

/*
get block number from row
params: int row
returns: int block number
*/
int getBlockFromRow(int i)
{
    int a_ConvertRowNumberToBlock[9] = { 0, 0, 0, 1, 1, 1, 2, 2, 2};
    return a_ConvertRowNumberToBlock[i];
}

/*
get line number in scope of a block
params: int line
returns: int block line number
*/
int getBlockLineFromLine(int i)
{
    int a_ConvertLineNumberToLine[9] = { 0, 1, 2, 0, 1, 2, 0, 1, 2};
    return a_ConvertLineNumberToLine[i];
}

/*
get row number in scope of a block
params: int row
returns: int block row number
*/
int getBlockRowFromRow(int i)
{
    int a_ConvertRowNumberToRow[9] = { 0, 1, 2, 0, 1, 2, 0, 1, 2};
    return a_ConvertRowNumberToRow[i];
}

/*
get line number in scope of a block
params: int block
returns: int block line number
*/
int getBlockLineFromBlock(int i)
{
    int a_ConvertBlockToBlockLine[9] = {0, 0, 0, 3, 3, 3, 6, 6, 6};
    return a_ConvertBlockToBlockLine[i];
}

/*
get row number in scope of a block
params: int block
returns: int block row number
*/
int getBlockRowFromBlock(int i)
{
    int a_ConvertBlockToBlockRow[9] = {0, 1, 2, 0, 1, 2, 0, 1, 2};
    return a_ConvertBlockToBlockRow[i];
}

/*
get block number from sudoku line and row
params: int sudoku.row, int sudoku.line
returns: int block number
*/
//Arraymapping (row & line -> block)
int getBlockFromLineAndRow(int row, int line)
{
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

/*
get block number from cursor position
params: int cursor.row, int cursor.line
returns: int block number
*/
int getBlockFromCursor(int row, int line)
{
    int a_getBlock[13][13] = {
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,0,0,0,-1,1,1,1,-1,2,2,2,-1},
        {-1,0,0,0,-1,1,1,1,-1,2,2,2,-1},
        {-1,0,0,0,-1,1,1,1,-1,2,2,2,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,3,3,3,-1,4,4,4,-1,5,5,5,-1},
        {-1,3,3,3,-1,4,4,4,-1,5,5,5,-1},
        {-1,3,3,3,-1,4,4,4,-1,5,5,5,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,6,6,6,-1,7,7,7,-1,8,8,8,-1},
        {-1,6,6,6,-1,7,7,7,-1,8,8,8,-1},
        {-1,6,6,6,-1,7,7,7,-1,8,8,8,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
    };

    return a_getBlock[line][row];
}

/*
get block row number from cursor line and row
params: int cursor.row, int cursor.line
returns: int block row number
*/
int getRowFromCursor(int row, int line)
{
    int a_getBlock[13][13] = {
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,0,0,0,-1,0,0,0,-1,0,0,0,-1},
        {-1,1,1,1,-1,1,1,1,-1,1,1,1,-1},
        {-1,2,2,2,-1,2,2,2,-1,2,2,2,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,0,0,0,-1,0,0,0,-1,0,0,0,-1},
        {-1,1,1,1,-1,1,1,1,-1,1,1,1,-1},
        {-1,2,2,2,-1,2,2,2,-1,2,2,2,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,0,0,0,-1,0,0,0,-1,0,0,0,-1},
        {-1,1,1,1,-1,1,1,1,-1,1,1,1,-1},
        {-1,2,2,2,-1,2,2,2,-1,2,2,2,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
    };

    return a_getBlock[row][line];
}

/*
get block line number from cursor line and row
params: int cursor.row, int cursor.line
returns: int block line number
*/
int getLineFromCursor(int row, int line)
{
    int a_getBlock[13][13] = {
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,0,1,2,-1,0,1,2,-1,0,1,2,-1},
        {-1,0,1,2,-1,0,1,2,-1,0,1,2,-1},
        {-1,0,1,2,-1,0,1,2,-1,0,1,2,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,0,1,2,-1,0,1,2,-1,0,1,2,-1},
        {-1,0,1,2,-1,0,1,2,-1,0,1,2,-1},
        {-1,0,1,2,-1,0,1,2,-1,0,1,2,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,0,1,2,-1,0,1,2,-1,0,1,2,-1},
        {-1,0,1,2,-1,0,1,2,-1,0,1,2,-1},
        {-1,0,1,2,-1,0,1,2,-1,0,1,2,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
    };

    return a_getBlock[row][line];
}
