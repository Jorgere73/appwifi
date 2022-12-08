#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "appwifi.h"

#define MAX_VALUE 500

struct nodo *crear_nodo(char *info1, int tamano, int numArchivo)
{
    struct nodo *nodo_nuevo = (lista*) malloc(sizeof(lista));
    nodo_nuevo->info = (char*)calloc(sizeof(int), tamano);
    nodo_nuevo->info = info1;
    nodo_nuevo->prox = NULL;
    nodo_nuevo->num = numArchivo;
    nodo_nuevo->tamanoarch = tamano;

    return nodo_nuevo;
}
lista* wificollector_collect()
{
    lista raiz; //Nodo raíz, el primero de todos 
    lista* iterator = (lista*)calloc(sizeof(lista),1); //Puntero que servirá para trabajar y movernos a través de los diferentes nodos
    iterator = &raiz; //Seleccionamos el nodo raíz para crear una secuencia


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
                    char *infoA = (char *)calloc(sizeof(char), 500); //Guardará el texto del archivo seleccionado
                    for (int cont = 0; !feof(fcelda); cont++)
                    {
                        int leido = fgetc(fcelda);
                        infoA[cont] = leido; //Leemos archivo, y transferimos contenido a cadena
                        numchar = cont;
                    }
                    iterator->prox = crear_nodo(infoA, numchar, eleccion2); //creamos el nodo y metemos la información del archivo
                    //No hacemos free a infoA es un puntero al texto del archivo, si lo liberamos, se elimina este también
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
            iterator = iterator->prox; //Si quiere seleccionar más, pasamos al siguiente nodo para poder seguir con la secuencia
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
    iterator = &raiz; //Devolvemos un puntero al nodo raíz
    return iterator;
}


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
    while(iterator->prox != NULL) //Hasta que no se haya acabado la cadena de nodos, el bucle sigue
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

void wificollector_display_all(lista nodos)
{
  lista* iterator = &nodos;
  for(int i = 1; i <= 21; i++)
  {
    iterator = &nodos;
    printf("-------------------------Archivo %d-----------------------\n", i);
    while(iterator->prox != NULL)
    {
      if(iterator->prox->num == i)
      {
        printf("%s", iterator->prox->info);
        break;
      }
      iterator = iterator->prox;
    }
  }
}
