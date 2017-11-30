#include <stdio.h>
#include <stdlib.h>
#include "database.h"

int main()
{


    FILE *Datei = fopen("test.txt", "r");

    if(Datei)
    {

        save(Datei);

    }


    else
    {
        printf("ERROR:datei konnte nicht geoffnet werden");
    }

    fclose(Datei);
    return 0;
}
