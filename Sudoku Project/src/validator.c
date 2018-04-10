//  Created by Robin Winkler on 10.04.18.
#include "constants.h"
#include "validator.h"

int validateMenuInput(char *var)
{
    if(strlen(var) > 1){
        return 0;
    }

    switch (var[0]) {
        case 'n':
            return 2;
            break;

        case 'e':
            return 1;
            break;

        default:
            return 0;
            break;
    }
    return 0;
}
