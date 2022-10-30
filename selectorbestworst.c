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
    char* charcell = malloc(sizeof(char)*4);
    sprintf(charcell,"%u",cell);
    char s1[] = "Cell ";
    strcat(s1, charcell);

    /*char* string = malloc(size*sizeof(char*));
    for(int i = 0; i < size; i++)
    {
        string[i] = str[i] + '0';
    }
*/
    //char** allstr = splitstring(string, s1);
    //printf(allstr[0]);
    //free(string);
    return 0;
}

char** splitstring(char* str, char* div)
{
    char* sstring = strtok(str, div);
    int numsstr = 0;

    char** substr = malloc(sizeof(char*)*5);
    for(int i = 0; i < 5; i++)
    {
        substr[i] = malloc(250*sizeof(char*));
    }

    while(sstring != NULL) //Si no hay más delimitadores, parar
    {
        substr[numsstr] = sstring;
        sstring = strtok(NULL, div); //Hace divisiones hasta el siguiente limitador
        numsstr++;
    }
    return substr;
}