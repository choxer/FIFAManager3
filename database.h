#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

// Laden und Speichern der Daten

// Laden
void load(FILE *);              // parameter: Datenstrom der offenen Datei
void loadTeam(FILE *,char *);
void loadPlayer(FILE *,char *);

//Save
void save(FILE *);              // parameter: Datenstrom der offenen Datei
void saveTeam(FILE *, int );
void savePlayer(FILE *,int,int);


//tools
char *  scanZeilenanfang(char[],char *,FILE *,char *,int);
void delete_newline(char Zeile[]);

#endif // DATABASE_H_INCLUDED
