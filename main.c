#include "appwifi.h"
#include <stdbool.h>

int main()
{
  switch(printmenu())
  {
    case 1:
      wificollector_quit();
      break;
  }
  return 0;
}
