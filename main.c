#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test1();
void test2();

int main()
{
    test1();
    //test2();

    return 0;
}

void test1()
{

char *Input;

    FILE *Datei = fopen("teams.xml", "r");

    char *Zeile = calloc( 101, sizeof(char));

    int i = 0;
    int DatenCounter    = 0;
    int TeamCounter     = 0;
    int PlayerCounter   = 0;
    int NamenCounter    = 0;
    int BirthDayCounter = 0;

    if(Datei)
    {
        do
        {

                i++;
                //printf("%i\n", i);

                Zeile = calloc(101, sizeof( char));

                char *Zeilenanfang;
                Zeilenanfang = Zeile;


                fscanf( Datei, "%s[^\n]",Zeile);
                printf("%s\n", Zeile);


                if( strncmp( Zeile, "<Daten>", 7) == 0)
                {
                    printf( "-------------------------------------------------------------DATEN %i\n", DatenCounter);
                    DatenCounter++;

                }
                if( ( strncmp( Zeile, "<Team>", 6) == 0)&&( DatenCounter > 0))
                {
                    printf( "-----------------------------------------------------------TEAM %i\n", TeamCounter);
                    //printf("%s\n", Zeile);
                    TeamCounter++;
                }
                if( ( strncmp( Zeile, "<Player>", 8) == 0)&&( TeamCounter > 0))
                {
                    printf( "---------------------------------------------------------PLAYER %i TEAM %i\n", PlayerCounter, TeamCounter);
                    PlayerCounter++;
                }
                if( (strncmp( Zeile, "<Name>", 6) == 0)&&( PlayerCounter > 0))
                {
                    printf( "---------------------------------------------------------PLAYER %i TEAM %i Name %i\n", PlayerCounter, TeamCounter, NamenCounter);
                    NamenCounter++;
                    printf( "SPIELERNAME: %s \n", Zeile+6);
                }
                if( (strncmp( Zeile, "<Name>", 6) == 0)&&( PlayerCounter > 0))
                {
                    printf( "---------------------------------------------------------PLAYER %i TEAM %i Name %i\n", PlayerCounter, TeamCounter, NamenCounter);
                    NamenCounter++;
                    printf( "TEAMNAME: %s \n", Zeile+6);
                }
                if( (strncmp( Zeile, "<Birthday>", 10) == 0)&&( NamenCounter > 0))
                {
                    printf( "---------------------------------------------------------PLAYER %i TEAM %i Name %i\n", PlayerCounter, TeamCounter, NamenCounter);
                    BirthDayCounter++;
                    printf( "GEBURTSTAG: %s \n", Zeile+10);
                }

                while( (*Zeilenanfang == ' ')||( *Zeilenanfang == 9))
                {
                    Zeilenanfang++;
                }

                if( strncmp(Zeile, "</Data>", 7) == 0)
                {
                        break;
                }


        }while( feof( Datei) == 0);









        Input = calloc(101, sizeof(char));
        strncpy( Input, Zeile, 101);

        printf("Input: %s\n", Input);

    }

}





void test2()
{

    FILE *data;
    data = fopen("teams.xml", "rw");

    char *zeile;
    char echt[101];


        zeile = calloc(5, sizeof(char));

        fscanf(data, "%100[^\n]", zeile);

        strcpy(echt, zeile);

        //printf("%s\n", zeile);
        printf("%s\n", echt);

        free(zeile);

    //fclose(data);

}
//















