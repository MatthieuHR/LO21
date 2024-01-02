#include "../include/Rules.h"
#include "stdlib.h"
#include "stdio.h"

typedef int elm;

int getValue(elm* var){
    return *var;
}

Bool cmpValue(void* p1,void* p2){
    if(getValue(p1) == getValue(p2)){
        return True;
    }else{
        return False;
    }
}

void print(elm* var){
    printf("%d\n",*var);
}

int main(){
    Bool (*fnPointer)(void*, void*);
    fnPointer = cmpValue;
    FactList facts = createFactList(fnPointer);

    for (int i = 0; i <= 4; ++i) {
        elm* aFact = malloc(sizeof(elm));
        *aFact = i;
        facts = addFact(facts,aFact);
    }

    Rule aRule = createEmptyRule(facts);
    print(aRule->facts->head->fact);

    FactList copyOfFact = getFactListOfRule(aRule);
    if(copyOfFact == facts){
        printf("Pass\n");
    }

    for (int j =0; j < 4; ++j) {
        printf("a");
        elm* add;
        printf("a");
        add = getById(aRule->facts,j);
        printf("a");
        aRule = addPremise(aRule, add);
        printf("a\n");
    }
    aRule = createConclusion(aRule, getById(aRule->facts,4));
    print(getHeadOfPremise(aRule)->premise);
    print(getHeadOfPremise(aRule)->next->premise);
    print(getConclusion(aRule));

    return 0;
}
