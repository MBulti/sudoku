//  Created by Robin Winkler on 06.05.18.
#include <stdio.h>
#include "../include/constants.h"
#include "../include/input.h"

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
        selection = getchar();
        EOL;
    #endif
    return selection;
}
