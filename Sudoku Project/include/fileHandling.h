//  Created by Team-FMR on 16.05.18.

/*
gets absolute path from project dir + subdir + filename
params: char* buffer, char[32] subdirectory, char[32] filename
return: void - stored in buffer
*/
void getAbsoluteFilePath(char *buffer, char a_subDir[32], char a_fileName[32]);
/*
get path size
params: -
returns: int path file size
*/
int getPathSize();
