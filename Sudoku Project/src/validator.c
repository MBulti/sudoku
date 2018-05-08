//  Created by Robin Winkler on 10.04.18.
#include <string.h>
#include <stdio.h>
#include "../include/constants.h"
#include "../include/converter.h"
#include "../include/validator.h"
#include "../include/consolePrinter.h"
#include "../include/gameplay.h"

int validateMenuInput(char var)
{
    switch (var)
    {
    case 'n':
        return 2;
        break;

    case 'e':
        return 1;
        break;
    //Debug
    case 'a':
        //sudokuSolving();
        return 1;
        break;

    default:
        return 0;
        break;
    }
    return 0;
}

//correct solution by Moritz Bulthaup
int checkForValidSolution(int a_Sudoku[9][3][3]) //check for a correct solution
{
    int block = 0;
    for(block = 0; block < 9; block++) //foreach block in the sudoku
    {
        if(isBlockValid(a_Sudoku, block) == 0)
            return 0; //block is invalid
    }
    int line = 0;
    for(line = 0; line < 9; line++) //foreach line in the sudoku
    {
        if(isLineValid(a_Sudoku, line) == 0)
            return 0; //line is invalid
    }
    int row = 0;
    for(row = 0; row < 9; row++)    //foreach row in the sudoku
    {
        if(isRowValid(a_Sudoku, row) == 0)
            return 0; //row is invalid
    }

    //printf("Your Sudoku is correct.");
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
                    continue;

                if(a_Sudoku[blockNumber][line][row] == a_assistArray[arrayNumber])
                {
                    a_assistArray[arrayNumber] = 0; //remove found number
                    continue;
                }
            }

        }
    }
    int i = 0;
    for(i = 0; i < 9; i++)
    {
        if(a_assistArray[i] != 0)
            return 0; //one number is missing
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
                    continue;

                if(a_Sudoku[block][line][row] == a_assistArray[arrayNumber])
                {
                    a_assistArray[arrayNumber] = 0;
                    continue;
                }
            }
        }
    }
    int i = 0;
    for(i = 0; i < 9; i++)
    {
        if(a_assistArray[i] != 0)
            return 0; //one number is missing
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

                if(a_Sudoku[block][line][row] == a_assistArray[arrayNumber])
                {
                    a_assistArray[arrayNumber] = 0;
                    continue;
                }
            }
        }
    }
    int i = 0;
    for(i = 0; i < 9; i++)
    {
        if(a_assistArray[i] != 0)
            return 0; //one number is missing
    }

    return 1;
}

//current test for backtracking by Moritz Bulthaup

int isNumberInBlock(int a_Sudoku[9][3][3], int blockNumber, int numberToCheck)
{
    int line = 0;
    int row = 0;
    for(line = 0; line < 3; line++)
    {
        for(row = 0; row < 3; row++)
        {
            if(a_Sudoku[blockNumber][line][row] == numberToCheck)
                return 1; //number is already in block
        }
    }
    return 0; //number is still missing -> feel free to put it here;
}

int isNumberInLine(int a_Sudoku[9][3][3], int lineNumber, int numberToCheck)
{
    int blockNumber = getBlockFromLine(lineNumber); //0-8
    int line = getBlockLineFromLine(lineNumber); //0-2

    int block;
    int row;
    for(block = blockNumber; block < blockNumber+3; block++)
    {
        for(row = 0; row < 3; row++)
        {
            if(a_Sudoku[block][line][row] == numberToCheck)
                return 1; //number is already in line
        }
    }
    return 0; //number is still missing -> feel free to put it here
}

int isNumberInRow(int a_Sudoku[9][3][3], int rowNumber, int numberToCheck)
{
    int blockNumber = getBlockFromRow(rowNumber); //0-8
    int row = getBlockRowFromRow(rowNumber); //0-2

    int block;
    int line;
    for(block = blockNumber; block < blockNumber+7; block = block+3)
    {
        for(line = 0; line < 3; line++)
        {
            if(a_Sudoku[block][line][row] == numberToCheck)
                return 1; //number is already in row
        }
    }
    return 0; //number is still missing -> feel free to put it here
}
