/*#include "../include/Rules.h"
#include "stdlib.h"
#include "stdio.h"

typedef int coucou;

int getValue(coucou* var){
    return *var;
}

Bool cmpValue(void* p1,void* p2){
    if(getValue(p1) == getValue(p2)){
        return True;
    }else{
        return False;
    }
}

void print(coucou* var){
    printf("%d\n",*var);
}

int main(){
    Bool (*fnPointer)(void*, void*);
    fnPointer = cmpValue;
    FactList facts = createFactList(fnPointer);

    for (int i = 0; i <= 4; ++i) {
        coucou* aFact = malloc(sizeof(coucou));
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
        coucou* add;
        add = getById(aRule->facts,j);
        aRule = addPremise(aRule, add);
    }
    aRule = createConclusion(aRule, getById(aRule->facts,4));
    print(getHeadOfPremise(aRule)->premise);
    print(getHeadOfPremise(aRule)->next->premise);
    print(getConclusion(aRule));

    aRule = removePremise(aRule, getById(aRule->facts,0));

    if(!factInPremise(aRule, getById(aRule->facts,0))){
        printf("Pass\n");
    }

    if(factInPremise(aRule, getById(aRule->facts,2))){
        printf("Pass\n");
    }

    FactList end = freeRule(aRule);
    end = freeFactList(end);
    if(end == NULL){
        printf("Final Pass\n");
    }

    return 0;
}*/
