//  Created by Team-FMR on 06.05.18.

#include <stdio.h>
#include <stdlib.h>
#include "../include/constants.h"
#include "../include/input.h"
#if defined(PLATFORM) && PLATFORM == 1
#include <conio.h>
#elif defined(PLATFORM) && PLATFORM == 2
#include <unistd.h>
#endif

/*
gets generic input instantly
params: -
returns: char key pressed
*/
char getInput()
{
    char selection = '\0';

#if defined(PLATFORM) && PLATFORM == 1
    //https://www.c-plusplus.net/forum/39320-full
    while(selection == '\0')
    {
        if(kbhit())
        {
            selection = getch();
        }
    }
#elif defined(PLATFORM) && PLATFORM == 2
    fflush(stdout);
    read(0, &selection, 4);
#endif
    return selection;
}

/*
gets arrow key presses
params: -
returns: int direction pressed
*/
int getMove()
{
#if defined(PLATFORM) && PLATFORM == 2
    char move[4] = {'\0'}; //needs to be an array because the read method can get multiple chars back (for example keys with an escape sequence in front of like arrow keys)
    fflush(stdout);
    read(0, &move, 4);

    if(move[0] == 27) //escape sequence as int
    {
        if(move[1] == 91) //always after escape sequence
        {
            switch(move[2])
            {
            case 68: //left
                return -1;
                break;
            case 67: //right
                return 1;
                break;
            case 65: //up
                return 2;
                break;
            case 66: //down
                return -2;
                break;
            }
        }
    }
    return move[0];
#else
    char move = '\0';
    //https://www.c-plusplus.net/forum/39320-full
    while(move == '\0')
    {
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
            default:
                return move;
                break;
            }
        }
    }
#endif

    return 0;
}
