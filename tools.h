#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void clearScreen(void);
int askYesorNo(char[]);
void clearBuffer(void);
void printline(char,int);
void WaitForEnter(void);
int getText(char*,int,char**, int);
int getNumber(char[],int,int*, int, int);
//getText("Name: ", 50, 0, &((Teams + TeamCounter)->Name));






#endif // TOOLS_H_INCLUDED
