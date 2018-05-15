//  Created by Robin Winkler on 10.04.18.
int validateMenuInput(char var);
int checkForValidSolution(int a_Sudoku[9][3][3]);
int isBlockValid(int a_Sudoku[9][3][3], int blockNumber);
int isLineValid(int a_Sudoku[9][3][3], int lineNumber);
int isRowValid(int a_Sudoku[9][3][3], int rowNumber);

int solveSudoku(int a_Sudoku[9][3][3]);
int findUnassignedField(int a_Sudoku[9][3][3], int *block, int *row, int *line);
int isNumberSafe(int a_Sudoku[9][3][3],int blockNumber, int rowNumber, int lineNumber, int numberToCheck);
int isNumberInBlock(int a_Sudoku[9][3][3], int blockNumber, int numberToCheck);
int isNumberInLine(int a_Sudoku[9][3][3],int blockNumber, int lineNumber, int numberToCheck);
int isNumberInRow(int a_Sudoku[9][3][3],int blockNumber, int rowNumber, int numberToCheck);

