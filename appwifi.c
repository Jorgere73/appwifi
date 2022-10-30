#include <stdio.h>
#include <stdlib.h> //malloc()
#include <string.h>
#include <ctype.h>
#include "appwifi.h"

#define MAX_VALUE 500

int** wificollector_collect()//tenemos q abrir los archivos y recolectar lo q tiene dentro en un array
{
  bool exit2;
  int** collect;
  bool nosalir;
  char decision;
  int* cadena = malloc(sizeof(int)*MAX_VALUE);

  collect = malloc(sizeof(int*)*22);
  for(int it = 0; it <= 22; it++)
  {
    collect[it] = malloc(sizeof(int*)*MAX_VALUE);
  }

  do
  {
    do
    {
      int eleccion2;
      char celda[]="cells/info_cell_";
      char celda2[21];
      int tamano = 0;
      FILE *fcelda; //Archivo que contendrá la celda elegida
      printf("¿Qué celda desea recolectar? (1-21): \n");
      scanf("%d",&eleccion2);
      if(eleccion2>=1 && eleccion2<=21)
      {
        sprintf(celda2,"%u",eleccion2); //Concatenamos para tener la celda elegida
        strcat(celda,celda2);
        strcat(celda,".txt");
        printf("%s\n", celda);
        fcelda = fopen(celda, "r"); //Abrimos archivo en modo lectura

        tamano = filesize(fcelda);
        collect[eleccion2] = realloc(collect[eleccion2], sizeof(int*)*tamano); //Cambia el tamano de la celda al del archivo
        collect[22][eleccion2] = tamano;
        cadena = realloc(cadena, sizeof(int*)*tamano); //Cambia el tamano de cadena al del archivo en cuestion

        if(fcelda == NULL) {printf("Error al cargar el archivo\n");}
        else
        {    
          for(int cont = 0; !feof(fcelda); cont++)
          {
            int leido = fgetc(fcelda);
            cadena[cont] = leido; //Leemos archivo, y transferimos contenido a cadena
          }
        }
        exit2=true;
      }else {
        printf("Introduce un número valido. ");
        exit2=false;
      }
      //cadena = recortarcelda(cadena);
      for(int i = 0; i < MAX_VALUE; i++)
      {
        collect[eleccion2][i] = cadena[i]; //De cadena, transferimos el contenido a la matriz collect
      } 
      collect[0][eleccion2] = 1;
      fclose(fcelda);

    }while(exit2==false);
    printf("¿Desea añadir otro punto de acceso? [S/N]\n");
    scanf("%s", &decision); decision = tolower(decision);
    if(decision == 's') {nosalir= true;}
    else if(decision == 'n') {nosalir= false;}
    else {printf("Introduzca una de las opciones dadas [S/N]\n");}
    } while (nosalir);
    free(cadena); //Liberamos memoria
    return collect;
}

/*void wificollector_show_data_one_network(){
  int informacion;
  char celda[]="info_cell_";
  char celda2[21];
  FILE *fcelda;
  printf("Indique el ESSID (entre ""): \n");
  scanf("%d\n",&informacion);
  if(informacion>=1 && informacion<=21)
  {
    sprintf(celda2,"%u",informacion);//concatenamos para tener la celda elegida
    strcat(celda,celda2);
    strcat(celda,".txt");
    printf("%s\n", celda);
    fcelda = fopen(celda, "r");

  }else{
    printf("Introduce un número valido. ");

  }

}*/

void wificollector_display(int** celdas)
{
  inicio:
  char continuadisplay = '0';
  int numc; //Número de la celda de la cual queremos imprimir información
  printf("Indique el número de la celda del que desea conocer su información (1-21): \n");
  scanf("%d", &numc);
  if(celdas[numc][0] == 0) {printf("La celda que has seleccionado está vacía, elija otra\n");}
  else 
  {
    for(int c = 0; c < MAX_VALUE; c++)
    { 
      printf("%c", celdas[numc][c]);
    }
    printf("\n");
  }
  printf("¿Desea imprimir información de otra celda? [S/N]");
  getchar();
  scanf("%c", &continuadisplay);
  printf("\n");
  continuadisplay = tolower(continuadisplay);
  if(continuadisplay == 's') {goto inicio;}
}

void wificollector_display_all(int** celdas)
{
  for(int i = 1; i < 21; i++)
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

