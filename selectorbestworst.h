#ifndef SELECTORBESTWORST_H
#define SELECTORBESTWORST_H
#include <stdio.h>
#include <stdbool.h>
#include "appwifi.h"

void wificollector_select_best(int **source); //De entre las celdas de la matriz, saca la información asociada al punto de acceso con mayor calidad
void wificollector_select_worst(int** source);
int returnquality(int* str, int size, int numarchivo, int* cell, bool best);
char** splitstring(char* str, char* div, int* outputsize);

#endif