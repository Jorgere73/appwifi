#include "appwifi.h"
#include <stdbool.h>

int main()
{
  int** arraycollect;
  switch(printmenu())
  {
    case 1:
      if(wificollector_quit()==false)
      {
        main();
      }
      break;
  case 2:
    arraycollect = wificollector_collect();
    break;
  }
  return 0;
}
