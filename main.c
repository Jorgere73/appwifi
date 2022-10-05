#include "appwifi.h"
#include <stdbool.h>

int main()
{
  int** arraycollect;
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
       wificollector_display();
        break;
    }
  } 
  return 0;
}
