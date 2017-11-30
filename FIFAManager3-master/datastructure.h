#ifndef DATASTRUCTURE_H_INCLUDED
#define DATASTRUCTURE_H_INCLUDED

enum { MAXTEAMS = 10 };
enum { MAXPLAYERS = 20 };

// Struktur f�r Datum
typedef struct
{
    int Day;
    int Month;
    int Year;
} TDate;

// Struktur f�r Uhrzeit
typedef struct
{
    int Second;
    int Minute;
    int Hour;
} TTime;

// Struktur f�r Spieler
typedef struct
{
    char *Name;
    TDate *Birthday;
    int Trikot;
    int Goals;
} TPlayer;

// Struktur f�r Mannschaft
typedef struct
{
    char *TeamName;
    char *TrainerName;
    int Number;
    TPlayer Player[MAXPLAYERS];
} TTeam;

typedef struct
{
    char MenuPunkte[50];
} TMenuPkte;

extern int TeamCounter;
extern TTeam Teams[];

#endif // DATASTRUCTURE_H_INCLUDED
