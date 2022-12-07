#include "appwifi.h"
#include "menu.h"
#include "selectorbestworst.h"
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VALUE 500

int main()
{
  
  bool exit = false;
  /*
  int** arraycollect; //Array que contendrá el contenido de los archivos tras usar wificollector_collect()
  arraycollect = (int**)calloc(22, sizeof(int*)); //Reservamos espacio en memoria equivalente a 21 punteros a ints, uno por celda
  for(int it = 0; it <= 22; it++)
  {
    arraycollect[it] = (int*)calloc(MAX_VALUE, sizeof(int)); //Reservamos espacio suficiente como para que quepa el texto de la celda entero
    *(arraycollect[it]) = 0; //Primer elemento de cada celda será 0 hasta que sea modificado, para identificar celdas vacías
    arraycollect[0][it] = 0; //arraycollect[0] reservado para identificar celdas vacías, ya que no corresponde a ningún archivo
  }
*/

  lista *listatotal; 

  while(!exit)
  {
    switch(printmenu())
    {
     case 1:
       if(wificollector_quit()) {exit = true;} //Termina el programa
       break;
      case 2:
       listatotal = wificollector_collect();
       printf("%s", listatotal->prox->info);
       break;
      case 4:
       //wificollector_select_best(arraycollect)
       break;
      case 5:
       //wificollector_select_worst(arraycollect);
       break;
      case 10:
       //wificollector_display(arraycollect);
       break;
      case 11:
       //wificollector_display_all(arraycollect);
       break;
    }
  } 
  return 0;
  //freearraymem(arraycollect);
  
}
