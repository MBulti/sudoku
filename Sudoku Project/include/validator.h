// Created by Team-FMR on 10.04.18.

/*
validates the menu inputs
params: char var - input
return: int - get passed to main.c where the function lives
 */
int validateMenuInput(char var);
/*
check for a valid solution
params: int a_Sudoku - Sudoku
returns: 1 = Sudoku is solved correcetly, 0 = either a block/a row/ a line is invalid
*/
int checkForValidSolution(int a_Sudoku[9][3][3]);
/*
check if block is valid
params: int[9][3][3] sudoku as array, int block number
returns: int is valid
*/
int isBlockValid(int a_Sudoku[9][3][3], int blockNumber);
/*
check if line is valid
params: int[9][3][3] sudoku as array, int line number
returns: int is valid
*/
int isLineValid(int a_Sudoku[9][3][3], int lineNumber);
/*
check if row is valid
params: int[9][3][3] sudoku as array, int row number
returns: int is valid
*/
int isRowValid(int a_Sudoku[9][3][3], int rowNumber);
/*
backtracking function
params: int a_Sudoku Sudoku
returns: 1 = everything is set and sudoku is solved, 0 = sudoku cannot be solved
*/
int solveSudoku(int a_Sudoku[9][3][3]);
/*
checks if sudoku is filled
params: int[9][3][3] sudoku as array, int* block, int* row, int* line
returns: int is everything is set
*/
int findUnassignedField(int a_Sudoku[9][3][3], int *block, int *row, int *line);
/*
checks if number can be set
params: int[9][3][3] sudoku as array, int block number, int row number, int line number, int number to check
returns: int is settable
*/
int isNumberSafe(int a_Sudoku[9][3][3],int blockNumber, int rowNumber, int lineNumber, int numberToCheck);
/*
checks if number is set in block
params: int[9][3][3] sudoku as array, int block number, int number to check
returns: int is set
*/
int isNumberInBlock(int a_Sudoku[9][3][3], int blockNumber, int numberToCheck);
/*
checks if a number is set in block line
params: int[9][3][3] sudoku as array, int block number, int line number, int number to check
returns: int is set
*/
int isNumberInLine(int a_Sudoku[9][3][3],int blockNumber, int lineNumber, int numberToCheck);
/*
checks if a number is set in block row
params: int[9][3][3] sudoku as array, int block number, int row number, int number to check
returns: int is set
*/
int isNumberInRow(int a_Sudoku[9][3][3],int blockNumber, int rowNumber, int numberToCheck);

