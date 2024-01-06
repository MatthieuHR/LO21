#ifndef RULES_H
#define RULES_H

#include "FactList.h"

typedef struct elm1{
    long id;
    void* premise;
    struct elm1* next;
}ElmOfPremise;

typedef struct {
    ElmOfPremise* head;
    ElmOfPremise* tail;
    long last_id;
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
Rule removeConclusion(Rule rule);//work
Bool factInPremise(Rule rule, void* prop);//work
Rule removeFromPremise(Rule rule, void* premise);//work
Rule removeFromPremiseById(Rule rule, long id);//work
Bool isPremiseEmpty(Rule rule);//work
Bool isEqualsRule(Rule rule1, Rule rule2);//work
ElmOfPremise* getHeadOfPremise(Rule rule);//work
ElmOfPremise* nextOfPremise(ElmOfPremise* elm);//work
void* getPremise(ElmOfPremise* elm);//work
void* getConclusion(Rule rule);//work
long getIdOfPremise(ElmOfPremise* elm);//work
FactList getFactListOfRule(Rule rule);
FactList freeRule(Rule rule);

#endif // RULES_H
