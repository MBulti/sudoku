//  Created by Robin Winkler on 10.04.18.
#include <stdio.h>
#include "../include/constants.h"
#include "../include/gameMaster.h"
#include "../include/validator.h"

int mainMenu(int status)
{
    char selection = '\0';
    
    CLS;
    
    if (status == 0) {
        printf("Falsche Eingabe entdeckt!\n");
    }
    
    printf("Hauptmenü:\n");
    printf("Bitte wählen:\n");
    printf("n - neues Spiel\n");
    printf("e - Spiel beenden\n");
    printf("Eingabe: ");
    selection = getchar();
    
    //to ignore all typed in characters after the first one
    while(getchar() != '\n');
    
    if((int)selection == -1){
        selection = 1;
    }
    
    return validateMenuInput(selection);
}

int newGame()
{
    int gameLoop = 1;

    while (gameLoop) {
        
    }
    
    return 0;
}
