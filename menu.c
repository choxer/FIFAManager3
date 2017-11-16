#include "tools.h"
#include "datastructure.h"
#include <stdio.h>
#include "menu.h"

int getMenu(char MenuTitel[], TMenuPkte MenuPunkte[], int AnzMenuPkt)
{
    int i = 1;
    int ok = 1;
    char eingabe;

    do
    {
        clearScreen();

        printf("%s", MenuTitel);

        for(i=1; i < AnzMenuPkt; i++)
        {
            printf("%i. %s\n", i, MenuPunkte[i].MenuPunkte );
        }

        printf("\n Bitte wahlen Sie einen Menupunkt: ");
        scanf("%c", &eingabe);
        clearBuffer();
        if((eingabe < 1)||(eingabe > AnzMenuPkt))
            printf("Ungultige Auswahl!");
        else
            ok = 0;
    } while(ok);

    return eingabe;
}
