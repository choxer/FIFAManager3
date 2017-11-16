#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

/********************************************************************
 * Funktion void clearBuffer()
 * - löscht Tastaturpuffer
 * Paramater: -
 * Funktionsergebnis: -
 *******************************************************************/
void clearBuffer();

/********************************************************************
 * Funktion void clearScreen()
 * - löscht Bildschrirmausgabe
 * Paramater: -
 * Funktionsergebnis: -
 *******************************************************************/
void clearScreen();

/********************************************************************
 * Funktion int askYesOrNo(char[] str)
 * - fragt übergebene Frage auf Ja oder Nein ab
 * Paramater: fragestellung
 * Funktionsergebnis: wahrheitswert ( ja:1 ; nein:0 )
 *******************************************************************/
int askYesOrNo(char str[]);

/********************************************************************
 * Funktion int askYesOrNo(char[] str)
 * - fragt übergebene Frage auf Ja oder Nein ab
 * Paramater: fragestellung
 * Funktionsergebnis: wahrheitswert ( ja:1 ; nein:0 )
 *******************************************************************/
 void printLine(char in, int Anz);

 int getText(char input[], int maxIn, int wahr, char **ptrOnArray);

 int getNumber(char input[], int maxIn, int wahr, char **ptrOnArray, int von, int bis);
#endif // TOOLS_H_INCLUDED
