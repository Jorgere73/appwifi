#include "appwifi.h"
#include "menu.h"
#include "selectorbestworst.h"
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VALUE 500

int main()
{
  
  bool exit = false;
  lista *listatotal = crear_nodo("raiz", 4, 25);
  lista raiz;

  while(!exit)
  {
    switch(printmenu())
    {
     case 1:
       if(wificollector_quit()) {exit = true;} //Termina el programa
       break;
      case 2:
       listatotal = wificollector_collect();
       raiz = *listatotal;
       break;
      case 4:
       wificollector_select_best(raiz);
       break;
      case 5:
       wificollector_select_worst(raiz);
       break;
      case 10:
       wificollector_display(raiz);
       break;
      case 11:
       wificollector_display_all(raiz);
       break;
    }
  } 
  //free(listatotal);
  return 0;
  
  
}
