#include "../include/Properties.h"
#include <stdlib.h>

/**
 * Function to test if a Property is empty.
 * 
 * @param prop A pointer to the Property to be tested.
 * @return True if the Property is empty (NULL), False otherwise.
 */
Boolean isUndefinedProperty(void* prop){
    if(prop != NULL){
        return False;
    }else{
        return True;
    }
}