#include "selectorbestworst.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUE 500

void wificollector_select_best(int** source) //source == arraycollect de main
{
    int interiorcells[21]; //Guarda el número de celda interior correspondiente a la calidad más alta dentro de un archivo
    int collected[21]; //Guarda los valores de calidad más alta de cada archivo en source
    int size = 0;

    for(int i = 0; i < 21; i++)
    {
        collected[i] = 0; //Para que al sacar la red con mayor calidad no haya problema con las celdas vacías
        if(source[0][i] == 0) {continue;}
        collected[i] = returnquality(source[i], source[22][i], i, interiorcells, true);
    }

    int max = collected[0];
    int count = 0;
    for(int i = 0; i < 21; i++)
    {
        if(collected[i] > max) {max = collected[i]; count = i;}
    }
    char* string = calloc(source[22][count], sizeof(char*));

    for(int i = 0; i < source[22][count]; i++)
    {
        string[i] = source[count][i];
    }

    printf("La mejor conexion tiene calidad %d/70", max); printf(", es del archivo %d", count); printf(" y celda %d:\n", interiorcells[count]);
    char** bestqdetails = splitstring(string, "\n", &size);
    for(int i = 1 + (9*interiorcells[count]); i < 1 + (9*interiorcells[count]) + 7; i++)
    {
        printf("%s\n", bestqdetails[i]);
    }
}

void wificollector_select_worst(int** source) //source == arraycollect de main
{
    int interiorcells[21]; //Guarda el número de celda interior correspondiente a la calidad más baja dentro de un archivo
    int collected[21]; //Guarda los valores de calidad más baja de cada archivo en source
    int size = 0;

    for(int i = 0; i < 21; i++)
    {
        collected[i] = 0; //Para que al sacar la red con mayor calidad no haya problema con las celdas vacías
        if(source[0][i] == 0) {continue;}
        collected[i] = returnquality(source[i], source[22][i], i, interiorcells, false);
    }

    int min = collected[0];
    int count = 0;
    for(int i = 0; i < 21; i++)
    {
        if(collected[i] < min) {min = collected[i]; count = i;}
    }
    char* string = calloc(source[22][count], sizeof(char*));

    for(int i = 0; i < source[22][count]; i++)
    {
        string[i] = source[count][i];
    }

    printf("La mejor conexion tiene calidad %d/70", min); printf(", es del archivo %d", count); printf(" y celda %d:\n", interiorcells[count]);
    char** bestqdetails = splitstring(string, "\n", &size);
    for(int i = 1 + (9*interiorcells[count]); i < 1 + (9*interiorcells[count]) + 7; i++)
    {
        printf("%s\n", bestqdetails[i]);
    }
}

int returnquality(int* str, int size, int numarchivo, int* cell, bool best)
{
    char* ptr;
    int quality[5]; for(int j=0;j<5;j++){quality[j]=0;}
    int lineas;
    int pos;
    int numceldas = 0;

    char* string = calloc(size, sizeof(char*));
    for(int i = 0; i < size; i++)
    {
        string[i] = str[i];
    }
    char** allstr = splitstring(string, "\n", &lineas);
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
    free(string);
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