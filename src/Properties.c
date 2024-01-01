#include "../include/Properties.h"
#include "stdlib.h"

//Function to test if a Property is empty (based on selected criteria)
Bool isEmptyProperty(Property* prop){
    if(prop->value != NULL){
        return False;
    }else{
        return True;
    }
}

//Function to compare 2 Property (based on selected criteria) and return True if they are the same and False otherwise
Bool isEqual(Property* p1, Property* p2, Bool (*cmpValue)(Property*, Property*)){
    if(cmpValue(p1,p2)) {
        return True;
    }else {
        return False;
    }
}