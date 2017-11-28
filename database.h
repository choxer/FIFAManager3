#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

// Ldaen und Speichern der Daten

// speichern
void save();
void saveTeam();    // parameter: Datenstrom der offenen Datei
void savePlayer();

// laden
void load();
void loadTeam();
void loadPlayer();

#endif // DATABASE_H_INCLUDED
