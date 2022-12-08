#ifndef SELECTORBESTWORST_H
#define SELECTORBESTWORST_H
#include <stdio.h>
#include <stdbool.h>
#include "appwifi.h"

void wificollector_select_best(lista nodos); //De entre las celdas de la matriz, saca la información asociada al punto de acceso con mayor calidad
void wificollector_select_worst(lista nodos); //Encuentra la peor calidad de conexion de entre todas las redes 
int returnquality(char* str, int numarchivo, int size, int* cell, bool best); //Retorna la mayor o menor calidad de todas las celdas de un archivo
char** splitstring(char* str, char* div, int* outputsize); //Divide el texto en líneas, para que sea más facil de manipular

#endif