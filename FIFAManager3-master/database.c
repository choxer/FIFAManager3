#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum{MAXZEICHEN=101};


void scanZeilenanfang(char Zeile[MAXZEICHEN],char *Zeilenanfang,FILE *data)
{
    fscanf(data,"%s[^\n]",Zeile);
    Zeilenanfang = Zeile;

    while( ( *Zeilenanfang == ' ' ) || ( *Zeilenanfang == 9 ) )
    {
        Zeilenanfang++;

    }
   printf("%s\n",Zeilenanfang);


}


void savePlayer(FILE *data)
{
    char Zeile[MAXZEICHEN];
    char *Zeilenanfang;

    do
    {

        fscanf(data,"%s[^\n]",Zeile);

        if(strncmp(Zeile,"<Name>",6)==0)
        {
            printf("  ");
            int Len;
            char *Title;

            Len = strlen( Zeile + 7 ) - 8;

            if ( strncmp( Zeile + 7 + Len, "</Title>", 8) == 0 )
            {
                Title = calloc( Len + 1, sizeof( char ) );

                    if ( Title )
                    strncpy( Title, Zeile + 7, Len );
                    printf("title: %s\n",Title);
            }


        }

    if ( feof( data) )
            break;

    }while(strncmp(Zeile,"</Player>",9)!=0);
}


void saveTeam(FILE *data)
{
    char Zeile[MAXZEICHEN];
    char *Zeilenanfang;

    do
    {

        printf("  ");//leerzeichen für team
        scanZeilenanfang(Zeile,Zeilenanfang,data);


        if(strncmp(Zeile,"<Player>",8)==0)
        {

            savePlayer(data);
        }


        if ( feof( data ) )
            break;



    }while(strncmp(Zeile,"</Team>",7)!=0);
}


void save(FILE *data)
{

    char Zeile[MAXZEICHEN];
    char *Zeilenanfang;

    do
    {


        scanZeilenanfang(Zeile,Zeilenanfang,data);



        if(  strncmp(Zeile,"<Team>",6 ) == 0 )
        {

           saveTeam(data);
        }

            if ( feof( data ) )
            {
                break;
                printf("feof von save");
            }

    }while(strncmp(Zeile,"</Data>",7)!=0);


}
