#include "../include/define.h"
#include "stdlib.h"

/**
* Function to test if a pointer is empty.
*
* @param elm A pointer to be tested.
* @return True if the pointer is empty, False otherwise.
*/
Boolean isUndefined(void* elm){
    return elm == NULL;
}
