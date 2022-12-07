#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "appwifi.h"

#define MAX_VALUE 500

/*ME CREO MI LISTA
cada nodo va a tener una wifi diferente no va a tener un archivo .cell*/


//para crear nodos y meter la información dentro

struct nodo *crear_nodo(char *info1, int tamano, int numArchivo)
{
    struct nodo *nodo_nuevo = (lista*) malloc(sizeof(lista));
    nodo_nuevo->info = (char*)calloc(sizeof(int), tamano);
    nodo_nuevo->info = info1;
    nodo_nuevo->prox = NULL;
    nodo_nuevo->num = numArchivo;

    return nodo_nuevo;
}
lista* wificollector_collect()
{
    lista raiz;
    lista* iterator = (lista*)calloc(sizeof(lista),1);
    iterator = &raiz;


    bool exit2;
    bool nosalir;
    char decision;
    int numchar; //Numero de caracteres en un archivo, para hacer realloc
    //mi collec==raiz

    do
    {
        do
        {
            int eleccion2;
            char celda[] = "cells/info_cell_";
            char celda2[21];

            FILE *fcelda; //Archivo que contendrá la celda elegida
            printf("¿Qué celda desea recolectar? (1-21): \n");
            scanf("%d", &eleccion2);
            if (eleccion2 >= 1 && eleccion2 <= 21)
            {
                sprintf(celda2, "%u", eleccion2); //Concatenamos para tener la celda elegida
                strcat(celda, celda2);
                strcat(celda, ".txt");
                //printf("%s", celda);
                fcelda = fopen(celda, "r"); //Abrimos archivo en modo lectura
                if (fcelda == NULL)
                {
                    printf("Error al cargar el archivo\n");
                }
                else
                {
                    char *infoA = (char *)calloc(sizeof(char), 500);
                    for (int cont = 0; !feof(fcelda); cont++)
                    {
                        int leido = fgetc(fcelda);
                        infoA[cont] = leido; //Leemos archivo, y transferimos contenido a cadena
                        numchar = cont;
                    }
                    iterator->prox = crear_nodo(infoA, numchar, eleccion2); //creamos el nodo y metemos la información de las wifis
                
                    //free(infoA);
                }
                exit2 = true;
            }
            else
            {
                printf("Introduce un número valido.\n");
                exit2 = false;
                continue;
            }
            fclose(fcelda);
        } while (exit2 == false);
        printf("¿Desea añadir otro punto de acceso? [S/N]\n");
        scanf("%s", &decision);
        //decision = tolower(decision);
        if (decision == 's' || decision == 'S')
        {
            nosalir = true;
            iterator = iterator->prox;
        }
        else if (decision == 'n' || decision == 'N')
        {
            nosalir = false;
        }
        else
        {
            printf("Introduzca una de las opciones dadas [S/N]\n");
        }
    } while (nosalir);
    iterator = &raiz;
    return iterator;
}

/*

Celda 1: 3 wifis.
Celda 2: 3 wifis
Celda 3: 3 wifis
Celda 4: 3 wifis.
Celda 5: 3 wifis
Celda 6: 3 wifis.
    
Celda 7: 2 wifis.
Celda 8: 2 wifis
Celda 9: 2 wifis
Celda 10: 2 wifis.
Celda 11: 2 wifis
Celda 12: 2 wifis
Celda 13: 2 wifis.
Celda 14: 2 wifis
Celda 15: 2 wifis
Celda 16: 2 wifis.
Celda 17: 2 wifis
Celda 18: 2 wifis
Celda 19: 2 wifis.
Celda 20: 2 wifis
Celda 21: 1 wifis

En total tenemos 48 wifis difrentes
*/

void wificollector_display(lista nodos)
{
  lista* iterator;
  char continuadisplay = '0';
  bool vacia;
  do
  {
    iterator = &nodos;
    vacia = true;
    int numc; //Número de la celda de la cual queremos imprimir información
    printf("Indique el número de la celda del que desea conocer su información (1-21): \n");
    scanf("%d", &numc);
    while(iterator->prox != NULL)
    {
        if(iterator->prox->num == numc)
        {
            printf("%s", iterator->prox->info);
            vacia = false;
            break;
        }
        iterator = iterator->prox;
    }
    if(vacia) {printf("La celda que busca esta vacia\n");}
    printf("¿Desea imprimir información de otra celda? [S/N]");
    getchar();
    scanf("%c", &continuadisplay);
    printf("\n");
    continuadisplay = tolower(continuadisplay);
  }while(continuadisplay == 's');
}
/*
void wificollector_display_all(int** celdas)
{
  for(int i = 1; i <= 21; i++)
  {
    if(celdas[0][i] == 0) {continue;} //Si está vacía, pasamos a la siguiente
    else
    {
      printf("Celda %d:\n\n", i);
      for(int c = 0; c < MAX_VALUE; c++)
      {
        printf("%c", celdas[i][c]);
      }
      printf("\n\n");
    }
  }
}

//----------------------------FUNCIONES PROPIAS-----------------------------
/*
void freearraymem(int** arr)
{
  for(int c = 0; c <= 22; c++)
  {
    free(arr[c]);
  }
  free(arr);
}

void aumentartamano(int** arr, int tamano)
{
  for(int i = 0; i <= 21; i++)
  {
    arr[i] = realloc(arr[i], tamano);
  }
}

int filesize(FILE* file)
{
  int sz;
  fseek(file, 0L, SEEK_END); //Va hasta final del archivo y retorna posicion, así sabemos el tamaño
  sz = ftell(file);
  rewind(file);
  return sz;
}
*/