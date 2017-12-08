#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED
#include "datastruct.h"

// Laden und Speichern der Daten

// Laden
void load(FILE *);              // parameter: Datenstrom der offenen Datei
void loadTeam(FILE *,char *);
void loadPlayer(FILE *,char *);

//Save
void save(FILE *);              // parameter: Datenstrom der offenen Datei
void saveTeam(FILE *,int TC);
void savePlayer(FILE *,int TC,int PC);


//tools
char *  scanZeilenanfang(char[],char *,FILE *,char *,int);
void delete_newline(char Zeile[]);
//TDate * strDate(char *, const char *)
#endif // DATABASE_H_INCLUDED
