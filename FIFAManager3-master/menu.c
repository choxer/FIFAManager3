#include "menu.h"



int getmenu(char Menutitel[] , TMTitel ArrMTitel[] , int anzmenu){

int eingabe;
int OK=0;
    do{

        clearScreen();  // aus Tools löscht Bildschirm

        printf("%s\n",Menutitel);
        printline('-',30);
        printline('-',30);
        printf("\n");

        //Mit einer Schleife werden die einzelnen Titel aus dem Titel array
        //geprintet

        int i;
        for(i=0;i<anzmenu;i++){
            printf("%i. %s\n",i,(ArrMTitel[i].MTitel));
        };

        //Eingabe Aufforderung und Überprüfung
        printf("\nIhre Wahl: ");


        scanf("%i",&eingabe);
        clearBuffer();


        if(eingabe>anzmenu||eingabe<0){
                printf("Ihre Eingabe ist nicht Gueltig!\n");
                WaitForEnter();
        }
        else{
                OK=1;
        }

    }while(OK==0);

    return eingabe;
 }

