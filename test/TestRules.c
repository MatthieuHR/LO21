#include "../include/BC.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct{
    int number;
}elm;

int getValue(elm* var){
    return var->number;
}

Bool cmp(void* p1, void* p2){
    if(getValue(p1) == getValue(p2)){
        return True;
    }else{
        return False;
    }
}

void print(elm* var){
    printf("%d",var->number);
}

int main(){
    Bool (*fnPointer)(void*,void*);
    fnPointer = cmp;
    FactList facts = createFactList(fnPointer);
    elm* aFact = malloc(sizeof(elm));
    aFact->number = 3;
    facts = addFact(facts,aFact);

    elm* aFact2 = malloc(sizeof(elm));
    aFact2->number = 12;
    facts = addFact(facts,aFact2);

    Rule* aRule = createEmptyRule(facts);
    aRule = addPremise(aRule, getById(facts,1));
    print(aRule->facts.head->fact);

    aRule = addPremise(aRule, getById(facts,0));
    print(aRule->facts.head->next->fact);

    if(PropertiesInPremise(aRule, getById(facts,0))){
        printf("Pass");
    }

    aRule = removePremise(aRule, getById(facts,1));

    if(!PropertiesInPremise(aRule, getById(facts,2))){
        printf("Pass");
    }

    aRule = createConclusion(aRule, getById(facts,1));
    ElmOfPremise * ccl = getHeadOfPremise(aRule);
    print(ccl->premise);

    BC bc = createEmptyBC(facts);
    bc = addRuleToBC(bc,aRule);
    print(bc.head->rule->premise.head->premise);

    Rule* head = getHeadRule(bc);
    print(head->premise.tail->premise);

    BC copy = copyOfBC(bc);

    return 0;
}