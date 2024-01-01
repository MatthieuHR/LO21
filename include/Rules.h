#include "FactList.h"

typedef struct elm1{
    Property* premise;
    struct elm1* next;
}ElmOfPremise;

typedef struct {
    ElmOfPremise* head;
    ElmOfPremise* tail;
}Premise;

typedef struct{
    Premise premise;
    Property* conclusion;
    FactList facts;
} Rule;


Rule* createEmptyRule(FactList facts);//work
Rule* addPremise(Rule* rule, Property* premise);//work
Rule* createConclusion(Rule* rule, Property* conclusion);//work
Bool PropertiesInPremise(Rule* rule, Property* prop);//work
Rule* removePremise(Rule* rule, Property* premise);//work
Bool isPremiseEmpty(Rule* rule);//work
ElmOfPremise* getHeadOfPremise(Rule* rule);//work
Property* getConclusion(Rule* rule);//work
