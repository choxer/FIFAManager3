#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

/********************************************************************
 * Funktion void clearBuffer()
 * - l�scht Tastaturpuffer
 * Paramater: -
 * Funktionsergebnis: -
 *******************************************************************/
void clearBuffer();

/********************************************************************
 * Funktion void clearScreen()
 * - l�scht Bildschrirmausgabe
 * Paramater: -
 * Funktionsergebnis: -
 *******************************************************************/
void clearScreen();

/********************************************************************
 * Funktion int askYesOrNo(char[] str)
 * - fragt �bergebene Frage auf Ja oder Nein ab
 * Paramater: fragestellung
 * Funktionsergebnis: wahrheitswert ( ja:1 ; nein:0 )
 *******************************************************************/
int askYesOrNo(char str[]);

/********************************************************************
 * Funktion int askYesOrNo(char[] str)
 * - fragt �bergebene Frage auf Ja oder Nein ab
 * Paramater: fragestellung
 * Funktionsergebnis: wahrheitswert ( ja:1 ; nein:0 )
 *******************************************************************/
 void printLine(char in, int Anz);

#endif // TOOLS_H_INCLUDED
