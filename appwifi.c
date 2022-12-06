#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*ME CREO MI LISTA
cada nodo va a tener una wifi diferente no va a tener un archivo .cell*/

struct nodo
{
    char *info;
    struct nodo *prox;
};
typedef struct nodo lista;

//para crear nodos y meter la información dentro
struct nodo *crear_nodo(char *info1)
{
    struct nodo *nodo_nuevo = (struct nodo *)malloc(sizeof(struct nodo));

    nodo_nuevo->info = info1;
    nodo_nuevo->prox = NULL;

    return nodo_nuevo;
}
lista *wificollector_collect()
{
    lista *milista = calloc(sizeof(lista *), 48); //Reservo memoria para cada posición de cada wifi 1wifi 1nodo.

    for (int it = 0; it <= 48; it++)
    {
        milista->info = (char *)calloc(sizeof(int), 500);
    }

    bool exit2;
    bool nosalir;
    char decision;
    //mi collec==milista

    char *infoA = (char *)calloc(sizeof(int), 500);

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

                    for (int cont = 0; !feof(fcelda); cont++)
                    {
                      
                        int leido = fgetc(fcelda);
                        infoA[cont] = leido; //Leemos archivo, y transferimos contenido a cadena
                        printf("Impresión numero %d:\n%s", cont, infoA);
                    }
                    printf("Estoy vacio:\ndd%s", infoA);
                    milista->prox = crear_nodo(infoA); //creamos el nodo y metemos la información de las wifis
                                                       // printf("Estoy vacio:\ndd%s", infoA);
                    /*COMPROBAMOS QUE ESTAMOS METIENDO BIEN LA INFORMACION
                    printf("tonto");
                    while (infoA != NULL)
                    {
                        printf("%s", infoA);
                    }*/
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
            milista = milista->prox;
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
    return milista;
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