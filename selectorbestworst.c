#include "selectorbestworst.h"
#include <stdio.h>
#include <stdlib.h>

void wificollector_select_best(int** source)
{

}

int returnquality(int* str, int size)
{
    char* ptr;
    char* string = calloc(size, sizeof(char));
    for(int i = 0; i < size; i++)
    {
        string[i] = str[i] + '0';
    }
    
    
    return 0;
}

char* splitstring(char* str, char div)
{
    char* sstring; = strtok(str, div);
    char** substr = malloc(sizeof(char*)*5);
    int numsstr = 0:
    for(int i = 0; i < 5; i++)
    {
        substr[i] = calloc(sizeof(char*)*MAX_VALUE/3);
    }

    while(sstring != NULL)
    {
        substr[numsstr] = sstring;
        sstring = strtok(NULL, div);
        numsstr++;
    }
    return substr;
}