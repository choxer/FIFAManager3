#include <stdio.h>
#include <stdlib.h>

int main()
{

    char Zeile[101];
    char Zeile2[101];
    char Zeile3[101];
    char Zeile4[101];

    char *Zeilenanfang;
    Zeilenanfang = Zeile;

    FILE *Datei = fopen("test.txt", "r");
    if(Datei)
    {

        fscanf(Datei, "%s[^\n]", Zeile2);
        fscanf(Datei, "%s[^\n]", Zeile);
        fscanf(Datei, "%s[^\n]", Zeile3);
        //fscanf(Datei, "%s[^\n]", Zeile4);
        fgets(Zeile4, 100, Datei);

        printf("%s\n", Zeile);
        printf("%s\n", Zeile2);
        printf("%s\n", Zeile3);
        printf("%s\n", Zeile4);

    }
    return 0;
}
