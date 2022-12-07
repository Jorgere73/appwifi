#ifndef APPWIFI_H
#define APPWIFI_H
#include <stdio.h>
#include <stdbool.h>


struct nodo
{
    char *info;
    struct nodo *prox;
    int num;
};
typedef struct nodo lista;

lista* crear_nodo(char* info1, int tamano, int numArchivo);
lista* wificollector_collect(); //Guarda contenido de un archivo en un array 
void wificollector_display(lista* nodos); //Imprime la celda elegida por el usuario, guardada en el array
void wificollector_display_all(int** celdas); //Imprime todas las celdas guardadas 
void freearraymem(int** arr); //Libera memoria para matrices
void aumentartamano(int** arr, int tamano); //Cambia el tamano de un array
int filesize(FILE* file); //Devuelve el tamano del archivo

#endif
