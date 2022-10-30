#include "selectorbestworst.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUE 500

void wificollector_select_best(int** source) //source == arraycollect de main
{
    for(int i = 0; i < 21; i++)
    {
        if(source[0][i] == 0) {continue;}
        returnquality(source[i], source[22][i], i);
    }
}

int returnquality(int* str, int size, int cell)
{
    char* ptr;
    int lineas;
    int pos;
    char* charcell = malloc(sizeof(char)*4);
    sprintf(charcell,"%u",cell);
    char s1[] = "Cell ";
    //char quality[];
    strcat(s1, charcell);

    char* string = calloc(size, sizeof(char*));
    for(int i = 0; i < size; i++)
    {
        string[i] = str[i];
    }
    char** allstr = splitstring(string, "\n", &lineas);
    for(int i = 6; i <= lineas; i+=9) //Primer Quality está en línea 6, y después va de 9 en 9. Lineas indica la cantidad de espacios que tiene el array 2d
    {
        ptr = strstr(allstr[i], "="); //Retorna un puntero sobre el =
        pos = (int)(ptr - allstr[i]); //Conseguimos la posición del = en el texto
        
    }
    free(string);
    return 0;
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