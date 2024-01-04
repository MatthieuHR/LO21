#ifndef RULES_H
#define RULES_H

#include "FactList.h"

typedef struct elm1{
    void* premise;
    struct elm1* next;
}ElmOfPremise;

typedef struct {
    ElmOfPremise* head;
    ElmOfPremise* tail;
}Premise;

typedef struct{
    Premise premise;
    void* conclusion;
    FactList facts;
} PreRule;

typedef PreRule* Rule;


Rule createEmptyRule(FactList facts);//work
Rule addPremise(Rule rule, void* premise);//work
Rule setConclusion(Rule rule, void* conclusion);//work
ElmOfPremise* factInPremise(Rule rule, void* prop);//work
Rule removeFromPremise(Rule rule, void* premise);//work
Bool isPremiseEmpty(Rule rule);//work
ElmOfPremise* getHeadOfPremise(Rule rule);//work
ElmOfPremise* nextOfPremise(ElmOfPremise* elm);//work
void* getPremise(ElmOfPremise* elm);//work
void* getConclusion(Rule rule);//work
FactList getFactListOfRule(Rule rule);
FactList freeRule(Rule rule);

#endif // RULES_H
