//  Created by Robin Winkler on 10.04.18.
#include <string.h>
#include <stdio.h>
#include "../include/constants.h"
#include "../include/converter.h"
#include "../include/validator.h"
#include "../include/consolePrinter.h"
#include "../include/gameplay.h"

/*
 * Validates the menu inputs
 * Param: char var - input
 * Return: int - get passed to main.c where the function lives
 */
int validateMenuInput(char var)
{
    switch (var)
    {
        case 'l':
            return 4;
            break;
        case 'n':
            return 2;
            break;
        case 'e':
            return 1;
            break;
        //Debug
        //case 'a':
        //    sudokuSolving();
        //    return 1;
        //    break;
        default:
            return 0;
            break;
    }
    return 0;
}

/*
Check for a valid solution by Moritz Bulthaup
Param: int a_Sudoku - Sudoku
returns: 1 = Sudoku is solved correcetly, 0 = either a block/a row/ a line is invalid
*/
int checkForValidSolution(int a_Sudoku[9][3][3]) //check for a correct solution
{
    int block = 0;
    for(block = 0; block < 9; block++) //foreach block in the sudoku
    {
        if(isBlockValid(a_Sudoku, block) == 0)
        {
            return 0; //block is invalid
        }

    }
    int line = 0;
    for(line = 0; line < 9; line++) //foreach line in the sudoku
    {
        if(isLineValid(a_Sudoku, line) == 0)
        {
            return 0; //line is invalid
        }

    }
    int row = 0;
    for(row = 0; row < 9; row++)    //foreach row in the sudoku
    {
        if(isRowValid(a_Sudoku, row) == 0)
        {
            return 0; //row is invalid
        }

    }

    return 1;
}

int isBlockValid(int a_Sudoku[9][3][3], int blockNumber)
{
    int line = 0;
    int row = 0;
    int arrayNumber = 0;
    int a_assistArray[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(line = 0; line < 3; line++)
    {
        for(row = 0; row < 3; row++)
        {
            for(arrayNumber = 0; arrayNumber < 9; arrayNumber++)
            {
                if(a_assistArray[arrayNumber] == 0)
                {
                    continue;
                }


                if(a_Sudoku[blockNumber][row][line] == a_assistArray[arrayNumber])
                {
                    a_assistArray[arrayNumber] = 0; //remove found number
                    break;
                }
            }

        }
    }
    int i = 0;
    for(i = 0; i < 9; i++)
    {
        if(a_assistArray[i] != 0)
        {
            return 0; //one number is missing
        }
    }
    return 1;
}

int isLineValid(int a_Sudoku[9][3][3], int lineNumber)
{
    int blockNumber = getBlockFromLine(lineNumber); //0-8
    int line = getBlockLineFromLine(lineNumber); //0-2

    int block;
    int row;
    int arrayNumber = 0;
    int a_assistArray[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(block = blockNumber; block < blockNumber+3; block++)
    {
        for(row = 0; row < 3; row++)
        {
            for(arrayNumber = 0; arrayNumber < 9; arrayNumber++)
            {
                if(a_assistArray[arrayNumber] == 0)
                {
                    continue;
                }

                if(a_Sudoku[block][row][line] == a_assistArray[arrayNumber])
                {
                    a_assistArray[arrayNumber] = 0;
                    break;
                }
            }
        }
    }
    int i = 0;
    for(i = 0; i < 9; i++)
    {
        if(a_assistArray[i] != 0)
        {
            return 0; //one number is missing
        }
    }

    return 1;
}

int isRowValid(int a_Sudoku[9][3][3], int rowNumber)
{
    int blockNumber = getBlockFromRow(rowNumber); //0-8
    int row = getBlockRowFromRow(rowNumber); //0-2

    int block;
    int line;
    int arrayNumber = 0;
    int a_assistArray[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(block = blockNumber; block < blockNumber+7; block = block+3)
    {
        for(line = 0; line < 3; line++)
        {
            for(arrayNumber = 0; arrayNumber < 9; arrayNumber++)
            {
                if(a_assistArray[arrayNumber] == 0)
                    continue;

                if(a_Sudoku[block][row][line] == a_assistArray[arrayNumber])
                {
                    a_assistArray[arrayNumber] = 0;
                    break;
                }
            }
        }
    }
    int i = 0;
    for(i = 0; i < 9; i++)
    {
        if(a_assistArray[i] != 0)
        {
            return 0; //one number is missing
        }
    }

    return 1;
}


//sudoku --> block row line
/*
Backtracking function by Moritz Bulthaup
Param: int a_Sudoku - Sudoku
returns: 1 = everything is set and sudoku is solved, 0 = sudoku cannot be solved
*/
int solveSudoku(int a_Sudoku[9][3][3])
{
    //https://gist.github.com/bopbi/c9f94b1b981b84bcb02b
    //15.05.2018

    int row = 0;
    int line = 0;
    int block = 0;

    if(findUnassignedField(a_Sudoku, &block, &row, &line)) //find unassigned fields
    {
        //Everything is set
        return 1;
    }

    int num;
    for(num = 1; num <= 9; num++) // try out all numbers
    {
        if(isNumberSafe(a_Sudoku,block, row, line, num))
        {
            a_Sudoku[block][row][line] = num;

            if(solveSudoku(a_Sudoku)) //call the function again to fill further fields
            {
                //if every field is filled, we return 1 and return from the functions (tree search)
                return 1;
            }
            a_Sudoku[block][row][line] = 0; //set it to 0 if we cant find a number
        }
    }

    return 0;
}

int findUnassignedField(int a_Sudoku[9][3][3], int *block, int *row, int *line)
{
    for(*block = 0; *block < 9; (*block)++)
    {
        for(*row = 0; *row < 3; (*row)++)
        {
            for(*line = 0; *line < 3; (*line)++)
            {
                if(a_Sudoku[*block][*row][*line] == 0)
                    return 0; //a number have to be set here
            }
        }
    }
    return 1; //everything is set
}

int isNumberSafe(int a_Sudoku[9][3][3],int blockNumber, int rowNumber, int lineNumber, int numberToCheck)
{
    if(isNumberInBlock(a_Sudoku, blockNumber, numberToCheck) == 0) //not in block
    {
        if(isNumberInRow(a_Sudoku,blockNumber, rowNumber, numberToCheck) == 0) //not in row
        {
            if(isNumberInLine(a_Sudoku,blockNumber, lineNumber, numberToCheck) == 0) //not in line
            {
                return 1; //number can be set
            }
        }
    }
    return 0; //number cannot be set
}

int isNumberInBlock(int a_Sudoku[9][3][3], int blockNumber, int numberToCheck)
{
    int line = 0;
    int row = 0;
    for(line = 0; line < 3; line++)
    {
        for(row = 0; row < 3; row++)
        {
            if(a_Sudoku[blockNumber][row][line] == numberToCheck)
                return 1; //number is already in block
        }
    }
    return 0; //number is still missing -> feel free to put it here;
}

int isNumberInLine(int a_Sudoku[9][3][3],int blockNumber, int lineNumber, int numberToCheck)
{
    int blockStart = getBlockLineFromBlock(blockNumber);

    int block;
    int row;
    for(block = blockStart; block <= blockStart + 2; block++)
    {
        for(row = 0; row < 3; row++)
        {
            if(a_Sudoku[block][row][lineNumber] == numberToCheck)
                return 1; //number is already in line
        }
    }
    return 0; //number is still missing -> feel free to put it here
}

int isNumberInRow(int a_Sudoku[9][3][3],int blockNumber, int rowNumber, int numberToCheck)
{
    int blockStart = getBlockRowFromBlock(blockNumber);

    int block;
    int line;
    for(block = blockStart; block <= blockStart + 6; block = block+3)
    {
        for(line = 0; line < 3; line++)
        {
            if(a_Sudoku[block][rowNumber][line] == numberToCheck)
                return 1; //number is already in row
        }
    }
    return 0; //number is still missing -> feel free to put it here
}

