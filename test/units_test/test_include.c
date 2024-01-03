#include "../../include/DB.h"
#include <stdlib.h>

typedef struct elm{
    int value;
}elm;

// Function to compare two elm
Bool cmpValue(void* elm1, void* elm2) {
    if (elm1 == NULL || elm2 == NULL) {
        return False;
    }
    elm* e1 = (elm*)elm1;
    elm* e2 = (elm*)elm2;
    if (e1->value == e2->value) {
        return True;
    } else {
        return False;
    }
}