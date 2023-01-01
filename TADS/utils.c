#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "Queue.h"

boolean elementExist(ELEMENT_ST element, KEY_ST key){
    if(*(element.key) == key)
      {
        return true;
      }
      return false;
}
