#include "menu.h"
#include <stdio.h>
#include <ctype.h> //Incluye función tolower()
#include <stdbool.h>

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