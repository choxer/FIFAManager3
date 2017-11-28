#include <stdio.h>
#include <string.h>

void load()
{
    //char Zeile[101];

    FILE *Datei;
    Datei = fopen("test.txt", "r");

    char Array[200];

    if(Datei)
    {
        fscanf(Datei, "%s", &Array[0] );
        printf("%s\n", Array);

        fclose(Datei);
    }

    // Leerzeichen und TABS überspringen:
    char Zeile[101];
    char *Zeilenanfang;
    Zeilenanfang = Zeile;   // zeiger zeigt nun auf Zeilenanfang

    while ( (*Zeilenanfang == ' ')||(*Zeilenanfang == 9) )      // leerzeichen o. ASCII 9 nicht beachten
    {
        Zeilenanfang++;
    }
    // erkennen von ' < '
    if (*Zeilenanfang == '<')
        printf("< entdeckt!");
    // welcher Tag ?
    if ( strncmp( Zeile, "<Title>", 7) == 0 ) // bei 0 -> GLEICH!
}
