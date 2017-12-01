#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

// Laden und Speichern der Daten

// speichern
void save(FILE *);
void saveTeam(FILE *,char *);    // parameter: Datenstrom der offenen Datei
void savePlayer(FILE *,char *);
char *  scanZeilenanfang(char[],char *,FILE *,char *,int);
void delete_newline(char Zeile[]);
// laden
void load();
void loadTeam();
void loadPlayer();

#endif // DATABASE_H_INCLUDED
