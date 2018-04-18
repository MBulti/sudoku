#include <stdio.h>
#include "../include/gameplay.h"
#include "../include/constants.h"

#if defined(PLATFORM) && PLATFORM == 1
    #include <windows.h>
#endif

int waitForInput()
{
    return 0;
}

int gameRoutine()
{
    int gameLoop = 1;
    int time_elapsed = 0.0;

    while (gameLoop) {
        CLS;
        time_elapsed++;
        printf("Time elapsed: %i\n", time_elapsed);
        #if defined(PLATFORM) && PLATFORM == 2
            sleep(1);

        #else
            Sleep(1000);
        #endif
    }

    return 0;
}
