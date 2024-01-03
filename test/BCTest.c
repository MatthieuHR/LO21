/*#include "../include/DB.h"
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

int main() {
    Bool (*fnPointer)(void *, void *);
    fnPointer = cmpValue;
    FactList facts = createFactList(fnPointer);

    for (int i = 0; i < 6; ++i) {
        coucou *aFact = malloc(sizeof(coucou));
        *aFact = i;
        facts = addFact(facts, aFact);
    }

    Rule ruleA = createEmptyRule(facts);
    Rule ruleB = createEmptyRule(facts);

    for (int i = 0; i < 2; ++i) {
        ruleA = addPremise(ruleA, getById(ruleA->facts,i));
        ruleB = addPremise(ruleB, getById(ruleB->facts,i+3));
    }
    ruleA = createConclusion(ruleA, getById(ruleA->facts,2));
    ruleB = setConclusion(ruleB, getById(ruleB->facts,5));

    DB aBC = createEmptyBC(facts);
    aBC = addRuleToBC(aBC,ruleA);
    aBC = addRuleToBC(aBC,ruleB);
    print(getHeadRule(aBC)->premise.head->premise);
    print(aBC->head->next->rule->conclusion);

    DB copyBC = copyOfBC(aBC);
    print(getHeadRule(copyBC)->premise.head->premise);
    print(copyBC->head->next->rule->conclusion);

    FactList isfree = freeBC(aBC);
    if(isfree != NULL){
        printf("Pass\n");
    }
    isfree = freeBC(NULL);
    if(isfree == NULL){
        printf("Pass\n");
    }
    isfree = freeBC(copyBC);
    if(isfree != NULL){
        printf("Pass\n");
    }
    isfree = freeFactList(isfree);

    return 0;
}
*/