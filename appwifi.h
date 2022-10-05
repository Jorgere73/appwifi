#ifndef APPWIFI_H
#define APPWIFI_H
#include <stdio.h>
#include <stdbool.h>



int printmenu(); //Imprime el menú y devuelve valor introducido
bool wificollector_quit(); //Sirve para cerrar el programa
int** wificollector_collect(); //Guarda contenido de un archivo en un array 
void wificollector_display(int** celdas); //Imprime la celda elegida por el usuario, guardada en el array
void wificollector_display_all(int** celdas); //Imprime todas las celdas guardadas 
#endif
