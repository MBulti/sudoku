//  Created by Robin Winkler on 10.04.18.
#include <stdlib.h>

//--- Windows ---//
#define PLATFORM 1 //Windows
#define CLS system("cls")

//--- Mac/Linux --//
//#define PLATFORM 2 //Linux/Mac
//#define CLS system("clear")

//https://en.wikipedia.org/wiki/ANSI_escape_code
//https://stackoverflow.com/questions/33025599/move-the-cursor-in-a-c-program
//https://gcc.gnu.org/onlinedocs/cpp/Macro-Arguments.html
#define cursorGoTo(X,Y) (printf("\033[%i;%iH", X, Y))

//to ignore all typed in characters after the first one
#define EOL while(getchar() != '\n');

//Arraymapping (line -> block / row -> block)
const int a_ConvertLineNumberToBlock[9] = { 0, 0, 0, 3, 3, 3, 6, 6, 6};
const int a_ConvertRowNumberToBlock[9] = { 0, 0, 0, 1, 1, 1, 2, 2, 2};
