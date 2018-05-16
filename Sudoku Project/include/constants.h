//  Created by Robin Winkler on 10.04.18.
#include <stdlib.h>
#include <time.h>

//--- Windows ---//
#define PLATFORM 1 //Windows

//--- Mac --//
//#define PLATFORM 2 //Mac

#if defined(PLATFORM) && PLATFORM == 1
    //Windows specific commands
    #include <windows.h>
    #define CLS system("cls")
    #define wait(X) (Sleep(X*1000))
    #define DS "\\"
#elif defined(PLATFORM) && PLATFORM == 2
    //Linux specific commands
    #define CLS system("clear")
    #define wait(X) (sleep(X))
    #define DS "/"
#endif

//https://en.wikipedia.org/wiki/ANSI_escape_code
//https://stackoverflow.com/questions/33025599/move-the-cursor-in-a-c-program
//https://gcc.gnu.org/onlinedocs/cpp/Macro-Arguments.html
#define cursorGoTo(X,Y) (printf("\033[%i;%iH", Y, X))

//to ignore all typed in characters after the first one
#define EOL while(getchar() != '\n');

//defines colors
#define WHITE "\x1B[37m"
#define RED "\x1B[31m"

//main game structure
struct s_sudoku {
    int a_sudoku[9][3][3]; //Block, Row, Line
    int a_originalSudoku[9][3][3];
    int error;
    int moves;
    int navigation;
    time_t timeStart;
    time_t timeEnd;
};
