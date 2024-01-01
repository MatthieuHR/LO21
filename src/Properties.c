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

//Function to compare 2 Property (based on selected criteria) and return True if they are the same and False otherwise
Bool isEqual(void* p1, void* p2, Bool (*cmpValue)(void*, void*)){
    if(cmpValue(p1,p2)) {
        return True;
    }else {
        return False;
    }
}