//  Created by Robin Winkler on 10.04.18.
#include <stdlib.h>

//--- Windows ---//
#define PLATFORM 1 //Windows

//--- Mac/Linux --//
//#define PLATFORM 2 //Linux/Mac

#if defined(PLATFORM) && PLATFORM == 1
    //Windows specific commands
    #include <windows.h>
    #define CLS system("cls")
    #define wait(X) (Sleep(X*1000))
#elif defined(PLATFORM) && PLATFORM == 2
    //Linux specific commands
    #define CLS system("clear")
    #define wait(X) (sleep(X))
#endif

//https://en.wikipedia.org/wiki/ANSI_escape_code
//https://stackoverflow.com/questions/33025599/move-the-cursor-in-a-c-program
//https://gcc.gnu.org/onlinedocs/cpp/Macro-Arguments.html
#define cursorGoTo(X,Y) (printf("\033[%i;%iH", Y, X))

//to ignore all typed in characters after the first one
#define EOL while(getchar() != '\n');

//main game structure
struct s_sudoku {
    int a_sudoku[9][3][3]; //Block, Row, Line
    int error;
};
