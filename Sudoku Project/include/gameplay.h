//evtl. Soduku Array rein und Soduku Array raus?
int gameRoutine(struct s_sudoku sudoku);
void sudokuSolving();

int checkForValidSolution(int a_Sudoku[9][3][3]);
int isBlockValid(int a_Sudoku[9][3][3], int blockNumber);
int isLineValid(int a_Sudoku[9][3][3], int lineNumber);
int isRowValid(int a_Sudoku[9][3][3], int rowNumber);
void waitForUserInput();
