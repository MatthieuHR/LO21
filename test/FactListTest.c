#include "../include//FactList.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct{
    int value;
}elm;

int getValue(elm* var){
    return var->value;
}

Bool cmpValue(void* p1,void* p2){
    if(getValue(p1) == getValue(p2)){
        return True;
    }else{
        return False;
    }
}

void print(elm* var){
    printf("%d\n",var->value);
}

int main(){
    Bool (*fnPointer)(void*, void*);
    fnPointer = cmpValue;
    FactList facts = createFactList(fnPointer);

    elm* aFact = malloc(sizeof(elm));
    aFact->value=1;
    facts = addFact(facts,aFact);
    print(facts->head->fact);

    if(isPresentInFactList(facts,aFact)){
        printf("Pass\n");
    }
    if(isAlreadyInFactList(facts,aFact)){
        printf("Pass\n");
    }

    elm* aCopyOfFact = malloc(sizeof(elm));
    aCopyOfFact->value=1;
    if(isAlreadyInFactList(facts,aCopyOfFact)){
        printf("Pass\n");
    }
    if(!isPresentInFactList(facts,aCopyOfFact)){
        printf("Pass\n");
    }
    aCopyOfFact->value=2;
    facts= addFact(facts,aCopyOfFact);
    print(facts->head->fact);
    print(facts->head->next->fact);

    print(getById(facts,0));
    print(getById(facts,1));
    if(isAlreadyInFactList(facts,aFact)){
        printf("Pass\n");
    }
    if(isPresentInFactList(facts,aFact)){
        printf("Pass\n");
    }
    facts = removeAllFacts(facts);
    if(facts->head ==  NULL){
        printf("Pass\n");
    }

    facts = freeFactList(facts);
    if(facts ==  NULL){
        printf("Pass");
    }
    return 0;
}