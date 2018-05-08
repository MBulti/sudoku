//  Created by Robin Winkler on 06.05.18.
#include <stdio.h>
#include <stdlib.h>
#include "../include/constants.h"
#include "../include/input.h"
#if defined(PLATFORM) && PLATFORM == 1
    #include <conio.h>
#endif

void waitForUserInput()
{
    char wait;
    scanf("%c", &wait);
}

char getInput(){
    char selection = '\0';

    #if defined(PLATFORM) && PLATFORM == 2
        fflush(stdout);
        read(0, &selection, 4);
    #else
        //https://www.c-plusplus.net/forum/39320-full
        while(selection == '\0'){
            if(kbhit()){
                selection = getch();
            }
        }
    #endif
    return selection;
}

int getMove(){
    char move = '\0';

    #if defined(PLATFORM) && PLATFORM == 2
        fflush(stdout);
        read(0, &move, 4);
    #else
        //https://www.c-plusplus.net/forum/39320-full
        while(move == '\0'){
            //if keyboardhit then exec
            if(kbhit())
            {
                move = getch();

                //if pressed key sends -32 (probably escape sequence)
                if((int)move == -32)
                {
                    move = getch();
                }

                switch(move)
                {
                    case 75: //left
                        return -1;
                        break;
                    case 77: //right
                        return 1;
                        break;
                    case 72: //up
                        return 2;
                        break;
                    case 80: //down
                        return -2;
                        break;
                    /*case '0' ... '9':
                        return move;
                        break;*/
                    default:
                        return move;
                        break;
                }
            }
        }
    #endif

    return 0;
}
