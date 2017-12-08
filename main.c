#include <stdio.h>
#include <stdlib.h>
#include "database.h"
#include "tools.h"
int main()
{


    FILE *Datei = fopen("test.txt", "r");

    if(Datei)
    {
        load(Datei);
    }
    else
    {
        printf("ERROR: datei konnte nicht geoffnet werden\n");
    }
    FILE *Datei2= fopen("save2.txt", "w");
    if(Datei2)
    {

        save(Datei2);
    }
    else
    {
        printf("ERROR: datei2 konnte nicht geoffnet werden\n");
    }

    fclose(Datei2);
    fclose(Datei);
    return 0;
}
