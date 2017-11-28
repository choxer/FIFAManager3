#ifndef DATETIME_H_INCLUDED
#define DATETIME_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "datastruct.h"

int isleapyear(TDate);
int isdatevalid(TDate);
int getDate(char [], int );
void printDate(TDate*);

#endif // DATETIME_H_INCLUDED
