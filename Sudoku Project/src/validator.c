//  Created by Robin Winkler on 10.04.18.
#include <string.h>
#include "../include/constants.h"
#include "../include/validator.h"

int validateMenuInput(char var)
{
    switch (var) {
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
