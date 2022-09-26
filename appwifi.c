#include <stdio.h>
#include <ctype.h> //Incluye función tolower()
#include <stdbool.h>
#include <string.h>

int printmenu()
{
  int eleccion;
  char text[] =
  "[1]wificollector_quit\n"
  "[2]wificollector_collect\n"
  "[3]wificollector_show_data_one_network\n"
  "[4]wificollector_select_best\n"
  "[5]wificollector_select_worst\n"
  "[6]wificollector_delete_net\n"
  "[7]wificollector_sort\n"
  "[8]wificollector_export\n"
  "[9]wificollector_import\n"
  "[10]wificollector_display\n"
  "[11]wificollector_display_all\n";
  printf("%sOpción elegida: ", text);
  scanf("%d", &eleccion);
  printf("Has elegido: %d\n", eleccion);
  return eleccion;
}

bool wificollector_quit()
{
  char exit; //S o N
  bool salida;
  do
  {
    printf("¿Está seguro de que quiere salir? [S/N]\n");
    scanf("%s", &exit); exit = tolower(exit);
    if(exit == 's') {return true;}
    else if(exit == 'n') {return false;}
    else {printf("Introduzca una de las opciones dadas [S/N]\n");}
  } while(true);


}

void wificollector_collect()
{

bool exit2;
bool salir;
char decision;
do
{
  do
  {
    int eleccion2;
    char celda[]="info_cell_";
    char celda2[21];
    FILE *fcelda; //Archivo que contendrá la celda elegida
    printf("¿Qué celda desea recolectar? (1-21): \n");
    scanf("%d",&eleccion2);
    if(eleccion2>=1 && eleccion2<=21)
    {
      sprintf(celda2,"%u",eleccion2);//concatenamos para tener la celda elegida
      strcat(celda,celda2);
      strcat(celda,".txt");
      printf("%s\n", celda);
      fcelda = fopen(celda, "r");
      if(fcelda == NULL) {printf("Error al cargar el archivo\n");}
      else
      {
        while(!feof(fcelda)) //Mientras no haya llegado al final del archivo...
        {
          printf("%c", fgetc(fcelda));
        }
      }
      exit2=true;
    }else {
      printf("Introduce un número valido. ");
      exit2=false;
    }
    fclose(fcelda);
  }while(exit2==false);
  printf("¿Desea añadir otro punto de acceso? [S/N]\n");
  scanf("%s", &decision); decision = tolower(decision);
  if(decision == 's') {salir= true;}
  else if(decision == 'n') {salir= false;}
  else {printf("Introduzca una de las opciones dadas [S/N]\n");}
  } while (salir==true);
}
