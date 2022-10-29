#ifndef SELECTORBESTWORST_H
#define SELECTORBESTWORST_H
#include <stdio.h>
#include <stdbool.h>

void wificollector_select_best(int** source); //De entre las celdas de la matriz, saca la información asociada al punto de acceso con mayor calidad
void wificollector_select_worst(int** source);

#endif