//  Created by Robin Winkler on 10.04.18.
#include <stdlib.h>

//--- Windows ---//
//#define PLATFORM 1 //Windows
//#define CLS system("cls")

//--- Mac/Linux --//
#define PLATFORM 2 //Linux/Mac
#define CLS system("clear")

//https://en.wikipedia.org/wiki/ANSI_escape_code
//https://stackoverflow.com/questions/33025599/move-the-cursor-in-a-c-program
#define cursorGoTo(X,Y) (printf("\033[%i;%iH", X, Y))