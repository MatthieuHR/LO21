#include "../include/ExpertSys.h"
#include "stdlib.h"
#include "stdio.h"

typedef int* elm;

Bool cmpValue(void* a, void* b){
    if(*(elm*)a == *(elm*)b) {
        return True;
    } else{
        return False;
    }
}

int main(){

    FactList facts = createFactList(cmpValue);
    FactList factsToShearch = createFactList(cmpValue);
    FactList result = createFactList(cmpValue);

    DB aDB = createEmptyDB(facts);



    return 0;
}