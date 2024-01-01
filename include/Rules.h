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
} Rule;


Rule* createEmptyRule(FactList facts);//work
Rule* addPremise(Rule* rule, void* premise);//work
Rule* createConclusion(Rule* rule, void* conclusion);//work
Bool factInPremise(Rule* rule, void* prop);//work
Rule* removePremise(Rule* rule, void* premise);//work
Bool isPremiseEmpty(Rule* rule);//work
ElmOfPremise* getHeadOfPremise(Rule* rule);//work
void* getConclusion(Rule* rule);//work
