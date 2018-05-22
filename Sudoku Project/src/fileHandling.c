//  Created by Team-FMR on 16.05.18.

#include "../include/constants.h"
#include <unistd.h>
#include <string.h>

/*
gets absolute path from project dir + subdir + filename
params: char* buffer, char[32] subdirectory, char[32] filename
return: void - stored in buffer
*/
void getAbsoluteFilePath(char *buffer, char a_subDir[32], char a_fileName[32])
{
    //clean the buffer variable
    int i = 0;
    for(; i<=sizeof(buffer); i++)
    {
        buffer[i] = '\0';
    }
#if defined(PLATFORM) && PLATFORM == 1
    //https://cboard.cprogramming.com/c-programming/88690-path-file-relative-program.html
    char path[MAX_PATH];
    GetCurrentDirectory(sizeof(path), path);
#elif defined(PLATFORM) && PLATFORM == 2
    char path[1024];
    getcwd(path, sizeof(path));
#endif

    //build path together
    strcat(buffer, path);
    strcat(buffer, DS);
    strcat(buffer, a_subDir);
    strcat(buffer, DS);
    strcat(buffer, a_fileName);
}

/*
get path size
params: -
returns: int path file size
*/
int getPathSize()
{
#if defined(MAX_PATH)
    int path = MAX_PATH;
#else
    int path = 1024;
#endif
    return path+sizeof(DS)+sizeof(DS)+sizeof(".sudoku")+64;
}
