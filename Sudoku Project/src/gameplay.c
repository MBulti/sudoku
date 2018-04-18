#include "../include/gameplay.h"
#include "../include/constants.h"

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
        sleep(1);
    }
}
