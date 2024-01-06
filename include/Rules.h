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


Rule createEmptyRule(FactList facts);//
Rule addFactInPremise(Rule rule, void* premise);//
Rule setConclusion(Rule rule, void* conclusion);//
Rule removeConclusion(Rule rule);//
Boolean factInPremise(Rule rule, void* prop);//
Rule removeFromPremise(Rule rule, void* premise);//
Rule removeFromPremiseById(Rule rule, long id);//
Boolean isPremiseEmpty(Rule rule);//
Boolean isUndefinedConclusion(Rule rule);//
Boolean isEqualsRule(Rule rule1, Rule rule2);//
Boolean isRuleEmpty(Rule rule);//
Boolean isUndefinedRule(Rule rule);//
ElmOfPremise* getHeadOfPremise(Rule rule);//
ElmOfPremise* nextOfPremise(ElmOfPremise* elm);//
void* getPremise(ElmOfPremise* elm);//
void* getConclusion(Rule rule);//
long getIdOfPremise(ElmOfPremise* elm);//
FactList getFactListOfRule(Rule rule);//
FactList freeRule(Rule rule);//

#endif // RULES_H
