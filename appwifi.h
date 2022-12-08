#ifndef APPWIFI_H
#define APPWIFI_H
#include <stdio.h>
#include <stdbool.h>


struct nodo
{
    char *info; //El texto que contendrá el nodo
    struct nodo *prox; //Una referencia al nodo que lo seguirá
    int num; //Número del archivo al cual pertenece el texto guardado en el nodo
    int tamanoarch; //Tamaño del texto/archivo guardado en nodo
};
typedef struct nodo lista; //Abreviar

lista* crear_nodo(char* info1, int tamano, int numArchivo); //Crea un nuevo nodo con un texto como informacion
lista* wificollector_collect(); //Guarda contenido de un archivo en un array 
void wificollector_display(lista nodos); //Imprime la celda elegida por el usuario, guardada en el array
void wificollector_display_all(lista nodos); //Imprime todas las celdas guardadas 

#endif
