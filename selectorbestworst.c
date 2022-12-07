#include "selectorbestworst.h"
#include "appwifi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUE 500

void wificollector_select_best(lista nodos) //source == arraycollect de main
{
    lista* iterator = &nodos;
    int interiorcells[21]; //Guarda el número de celda interior correspondiente a la calidad más alta dentro de un archivo
    int collected[21]; //Guarda los valores de calidad más alta de cada archivo en source
    int size = 0;

    for(int i = 0; i < 21; i++)
    {
        collected[i] = 0;
    }
    while(iterator->prox != NULL)
    {
        if(iterator->prox == NULL) {break;}
        collected[iterator->prox->num] = returnquality(iterator->prox->info, iterator->prox->num, iterator->prox->tamanoarch, interiorcells, true);
        iterator = iterator->prox;
    }

    int max = collected[0];
    int count = 0;
    for(int i = 1; i < 21; i++)
    {
        if(collected[i] > max) {max = collected[i]; count = i;}
    }
    char* string = (char*) calloc(500, sizeof(char));

    iterator = &nodos;
    while(iterator->prox != NULL)
    {
        if(iterator->prox->num == count)
        {
            string = (char*) realloc(string, iterator->prox->tamanoarch*sizeof(char));
            for(int i = 0; i < iterator->prox->tamanoarch; i++)
            {
                string[i] = iterator->prox->info[i];
            }
            break;
        }
        iterator = iterator->prox;
    }
    printf("La mejor conexion tiene calidad %d/70", max); printf(", es del archivo %d", count); printf(" y celda %d:\n", interiorcells[count]);
    char** bestqdetails = splitstring(string, "\n", &size);
    for(int i = 1 + (9*interiorcells[count]); i < 1 + (9*interiorcells[count]) + 7; i++)
    {
        printf("%s\n", bestqdetails[i]);
    }
    free(bestqdetails);
    free(string);
}

void wificollector_select_worst(lista nodos) //source == arraycollect de main
{
    lista* iterator = &nodos;
    int interiorcells[21]; //Guarda el número de celda interior correspondiente a la calidad más alta dentro de un archivo
    int collected[21]; //Guarda los valores de calidad más alta de cada archivo en source
    int size = 0;

    for(int i = 0; i < 21; i++)
    {
        collected[i] = 80;
    }
    while(iterator->prox != NULL)
    {
        if(iterator->prox == NULL) {break;}
        collected[iterator->prox->num] = returnquality(iterator->prox->info, iterator->prox->num, iterator->prox->tamanoarch, interiorcells, false);
        iterator = iterator->prox;
    }

    int min = 70;
    int count = 0;
    for(int i = 1; i < 21; i++)
    {
        if(collected[i] < min) {min = collected[i]; count = i;}
    }
    char* string = (char*) calloc(500, sizeof(char));

    iterator = &nodos;
    while(iterator->prox != NULL)
    {
        if(iterator->prox->num == count)
        {
            string = (char*) realloc(string, iterator->prox->tamanoarch);
            for(int i = 0; i < iterator->prox->tamanoarch; i++)
            {
            string[i] = iterator->prox->info[i];
            }
            break;
        }
        iterator = iterator->prox;
    }
    printf("La peor conexion tiene calidad %d/70", min); printf(", es del archivo %d", count); printf(" y celda %d:\n", interiorcells[count]);
    char** worstqdetails = splitstring(string, "\n", &size);
    for(int i = 1 + (9*interiorcells[count]); i < 1 + (9*interiorcells[count]) + 7; i++)
    {
        printf("%s\n", worstqdetails[i]);
    }
    free(worstqdetails);
    free(string);
}


//void wificollector_display_all()

int returnquality(char* str, int numarchivo, int size, int* cell, bool best)
{
    char* ptr;
    char* str1 = (char*) calloc(size, sizeof(char));
    for(int i =0; i < size; i++)
    {
        str1[i] = str[i];
    } //Para evitar que en splitstring se modifique str, el original

    int quality[5]; for(int j=0;j<5;j++){quality[j]=0;}
    int lineas;
    int pos;
    int numceldas = 0;

    char** allstr = splitstring(str1, "\n", &lineas);
    for(int i = 6, j = 0; i < lineas; i+=9, j++, numceldas++) //Primer Quality está en línea 6, y después va de 9 en 9. Lineas indica la cantidad de espacios que tiene el array 2d
    {
        ptr = strstr(allstr[i], "="); //Retorna un puntero sobre el =
        pos = (int)(ptr - allstr[i]); //Conseguimos la posición del = en el texto
        quality[j] = (allstr[i][pos+1] -'0')*10 + (allstr[i][pos+2] -'0');
        //printf("%d", quality[j]);
        //printf("------------%d\n", j);
    }
    //printf("%d\n", quality[3]);
    //-----------------------FREE------------------
    free(allstr);
    //for(int i = 0; i < 5; i++) {free(allstr[i]);}
    //---------------------------------------------
    if(best)
    {
        int max = quality[0];
        int cellnum = 0;
        for(int i = 1; i < numceldas; i++)
        {
            if(quality[i] > max) {max = quality[i]; cellnum = i;}
        }
        cell[numarchivo] = cellnum;
        return max;
    }
    else
    {
        int min = quality[0];
        int cellnum = 0;
        for(int i = 1; i < numceldas; i++)
        {
            if(quality[i] < min) {min = quality[i]; cellnum = i;}
        }
        cell[numarchivo] = cellnum; //Retorna a través de cell el numero de la celda interior en la que se encuentra la red con mejor calidad
        free(str1);
        return min;
    }
}

char** splitstring(char* str, char* div, int* outputsize)
{
    char* sstring = strtok(str, div);
    int numsstr = 0;

    char** substr = calloc(50, sizeof(char*));
    for(int i = 0; i < 5; i++)
    {
        substr[i] = calloc(100, sizeof(char*));
    }

    while(sstring != NULL) //Si no hay más delimitadores, parar
    {
        substr[numsstr] = sstring;
        sstring = strtok(NULL, div); //Hace divisiones hasta el siguiente limitador
        numsstr++;
    }
    *outputsize = numsstr; //Accedemos a la variable a la que apuntamos para grabar en ella la cantidad de lineas en las que hemos dividido el texto
    return substr;
}