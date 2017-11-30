#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

// Laden und Speichern der Daten

// speichern
void save(FILE *);
void saveTeam(FILE *);    // parameter: Datenstrom der offenen Datei
void savePlayer(FILE *);
void scanZeilenanfang(char[],char *,FILE *,char *,int);
// laden
void load();
void loadTeam();
void loadPlayer();

#endif // DATABASE_H_INCLUDED
