#ifndef DATETIME_H_INCLUDED
#define DATETIME_H_INCLUDED

/********************************************************************
 * Funktion int isLeapYear(int checkYear)
 * - ist übergebenes jahr ein Schaltjahr?
 * Paramater: zu überprüfendes jahr
 * Funktionsergebnis: wahrheitswert Schaltjahr
 *******************************************************************/
int isLeapYear(int checkYear);
 /********************************************************************
 * Funktion int isDateValid(TDate checkDate)
 * - ist übergebenes Datum gültig?
 * Paramater: zu überprüfendes Datum
 * Funktionsergebnis: wahrheitswert Gültigkeit
 *******************************************************************/
int isDateValid(TDate checkDate);

 /********************************************************************
 * Funktion int getDateFromString(char[] str,TDate *parsDate)
 * - ist übergebenes Datum gültig?
 * Paramater: zu überprüfendes Datum
 * Funktionsergebnis: wahrheitswert Gültigkeit
 *******************************************************************/
int getDateFromString(char str[], TDate *parsDate);

 /********************************************************************
 * Funktion int isDateValid(TDate checkTime)
 * - ist übergebenes Datum gültig?
 * Paramater: zu überprüfende Uhrzeit
 * Funktionsergebnis: wahrheitswert Gültigkeit
 *******************************************************************/
int isTimeValid(TTime checkTime);

 /********************************************************************
 * Funktion int getDateFromString(char[] str,TDate *parsDate)
 * - ist übergebenes Datum gültig?
 * Paramater: zu überprüfendes Datum
 * Funktionsergebnis: wahrheitswert Gültigkeit
 *******************************************************************/
 int getTimeFromString(char str[], TTime *parsTime);

/********************************************************************
 * Funktion void inputDate(void)
 *   - Benutzer soll ein Datum eingeben.
 *   - Eingabe wird mit Hilfe der Funktion getDateFromString geparst
 *     und geprueft. Bei gueltigem Datum steht dieses in der Datums-
 *     variable Date.
 *   - Ergebnis der Eingabe wird entsprechend angezeigt.
 *   - wird nur die Eingabetaste gedrueckt, wird die Funktion ohne
 *     weitere Bildschirmausgabe beendet.
 * Paramater: keine
 * Funktionsergebnis: nichts
 *******************************************************************/
void inputDate();

/********************************************************************
 * Funktion void inputTime(void)
 *   - Benutzer soll eine Uhrzeit eingeben.
 *   - Eingabe wird mit Hilfe der Funktion getTimeFromString geparst
 *     und geprueft. Bei gueltiger Uhrzeit steht diese in der
 *     Uhrzeitvariable Time.
 *   - Ergebnis der Eingabe wird entsprechend angezeigt.
 *   - wird nur die Eingabetaste gedrueckt, wird die Funktion ohne
 *     weitere Bildschirmausgabe beendet.
 * Paramater: keine
 * Funktionsergebnis: nichts
 *******************************************************************/
void inputTime();

/********************************************************************
 * Funktion void inputTime(void)
 *   - Benutzer soll eine Uhrzeit eingeben.
 *   - Eingabe wird mit Hilfe der Funktion getTimeFromString geparst
 *     und geprueft. Bei gueltiger Uhrzeit steht diese in der
 *     Uhrzeitvariable Time.
 *   - Ergebnis der Eingabe wird entsprechend angezeigt.
 *   - wird nur die Eingabetaste gedrueckt, wird die Funktion ohne
 *     weitere Bildschirmausgabe beendet.
 * Paramater: keine
 * Funktionsergebnis: nichts
 *******************************************************************/
 int getDate();

 /********************************************************************
 * Funktion void inputTime(void)
 *   - Benutzer soll eine Uhrzeit eingeben.
 *   - Eingabe wird mit Hilfe der Funktion getTimeFromString geparst
 *     und geprueft. Bei gueltiger Uhrzeit steht diese in der
 *     Uhrzeitvariable Time.
 *   - Ergebnis der Eingabe wird entsprechend angezeigt.
 *   - wird nur die Eingabetaste gedrueckt, wird die Funktion ohne
 *     weitere Bildschirmausgabe beendet.
 * Paramater: keine
 * Funktionsergebnis: nichts
 *******************************************************************/
 void printDate(TDate *Datum);
#endif // DATETIME_H_INCLUDED
