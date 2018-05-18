//  Created by Team-FMR on 03.05.18.

/*
get block number from line
params: int line
returns: int block number
*/
int getBlockFromLine(int i);
/*
get block number from row
params: int row
returns: int block number
*/
int getBlockFromRow(int i);
/*
get line number in scope of a block
params: int line
returns: int block line number
*/
int getBlockLineFromLine(int i);
/*
get row number in scope of a block
params: int row
returns: int block row number
*/
int getBlockRowFromRow(int i);
/*
get line number in scope of a block
params: int block
returns: int block line number
*/
int getBlockLineFromBlock(int i);
/*
get row number in scope of a block
params: int block
returns: int block row number
*/
int getBlockRowFromBlock(int i);
/*
get block number from sudoku line and row
params: int sudoku.row, int sudoku.line
returns: int block number
*/
int getBlockFromLineAndRow(int row, int line);
/*
get block number from cursor position
params: int cursor.row, int cursor.line
returns: int block number
*/
int getBlockFromCursor(int row, int line);
/*
get block row number from cursor line and row
params: int cursor.row, int cursor.line
returns: int block row number
*/
int getRowFromCursor(int row, int line);
/*
get block line number from cursor line and row
params: int cursor.row, int cursor.line
returns: int block line number
*/
int getLineFromCursor(int row, int line);
