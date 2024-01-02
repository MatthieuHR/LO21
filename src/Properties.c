#include "../include/Properties.h"
#include "stdlib.h"

//Function to test if a Property is empty (based on selected criteria)
Bool isEmptyProperty(void* prop){
    if(prop != NULL){
        return False;
    }else{
        return True;
    }
}