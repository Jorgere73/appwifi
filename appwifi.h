#ifndef APPWIFI_H
#define APPWIFI_H
#include <stdio.h>
#include <stdbool.h>


int** wificollector_collect(); //Guarda contenido de un archivo en un array 
void wificollector_display(int** celdas); //Imprime la celda elegida por el usuario, guardada en el array
void wificollector_display_all(int** celdas); //Imprime todas las celdas guardadas 
void freearraymem(int** arr); //Libera memoria para matrices
void aumentartamano(int** arr, int tamano); //Cambia el tamano de un array
int filesize(FILE* file); //Devuelve el tamano del archivo
//int* recortarcelda(int* celda) //Recorta información de la celda e imprime los datos únicamente
#endif
