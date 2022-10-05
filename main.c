#include "appwifi.h"
#include <stdbool.h>
#include <stdlib.h>

int main()
{
  int** arraycollect;
  arraycollect = malloc(sizeof(int*)*21);
  for(int it = 0; it < 21; it++)
  {
    arraycollect[it] = malloc(sizeof(int*)*500);
    *(arraycollect[it]) = 0;
  }
  while(true)
  {
    switch(printmenu())
    {
     case 1:
       if(wificollector_quit()) {return 0;} //Termina el programa
       break;
      case 2:
       arraycollect = wificollector_collect();
       break;
     case 10:
       wificollector_display(arraycollect);
        break;
    }
  } 
  return 0;
}
