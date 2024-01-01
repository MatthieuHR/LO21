#include "../include/BC.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct{
    int number;
}elm;

Bool cmp(elm* p1, elm* p2){
    if(p1->number == p2->number){
        return True;
    }else{
        return False;
    }
}

Bool cmpValue(Property *p, Property *c){
    return cmp(p->value,c->value);
}

void affectValue(elm* var, int value){
    var->number=value;
}

void print(elm* var){
    printf("%d",var->number);
}

int main(){
    Bool (*fnPointer)(Property*,Property*);
    fnPointer = cmpValue;
    FactList facts = createFactList(fnPointer);
    Property* aFact = malloc(sizeof(Property));
    aFact->value = malloc(sizeof(int));
    affectValue(aFact->value,3);
    facts = addFact(facts,aFact);

    Property* aFact2 = malloc(sizeof(Property));
    aFact2->value = malloc(sizeof(int));
    affectValue(aFact2->value,12);
    facts = addFact(facts,aFact2);

    Rule* aRule = createEmptyRule(facts);
    aRule = addPremise(aRule, getById(facts,1));
    print(aRule->facts.head->fact->value);

    aRule = addPremise(aRule, getById(facts,0));
    print(aRule->facts.head->next->fact->value);

    if(PropertiesInPremise(aRule, getById(facts,0))){
        printf("Pass");
    }

    aRule = removePremise(aRule, getById(facts,1));

    if(!PropertiesInPremise(aRule, getById(facts,2))){
        printf("Pass");
    }

    aRule = createConclusion(aRule, getById(facts,1));
    ElmOfPremise * ccl = getHeadOfPremise(aRule);
    print(ccl->premise->value);

    BC bc = createEmptyBC(facts);
    bc = addRuleToBC(bc,aRule);
    print(bc.head->rule->premise.head->premise->value);

    Rule* head = getHeadRule(bc);
    print(head->premise.tail->premise->value);

    BC copy = copyOfBC(bc);
    print(copy.head->rule->premise.head->premise->value);

    return 0;
}