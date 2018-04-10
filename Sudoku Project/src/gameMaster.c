//  Created by Robin Winkler on 10.04.18.
#include "gameMaster.h"

int mainMenu(int status = 1)
{
    char selection[] = "\0";
    
    CLS;
    
    if (status == 0) {
        printf("Falsche Eingabe entdeckt!\n");
    }
    
    printf("Hauptmenü:\n");
    printf("Bitte wählen:\n");
    printf("n - neues Spiel\n");
    printf("e - Spiel beenden\n");
    printf("Eingabe: ");
    scanf("%s", selection);
    
    return validateMenuInput(selection);
}

int newGame()
{
    int gameLoop = 1;
    
    while (gameLoop) {
        
    }
}
