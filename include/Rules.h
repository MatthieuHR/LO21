#include "define.h"
#include "FactList.h"

typedef struct elm1{
    Property* premise;
    struct elm1* next;
}ElmOfPremise;

typedef ElmOfPremise * Premise;

typedef struct{
    Premise premise;
    Property* conclusion;
}Rule;


Rule* createEmptyRule();
Rule* addPremise(Rule* rules, Property* premise);
Rule* createConclusion(Rule* rule, Property* conclusion);
Bool PropertiesInPremise(Premise premise, Property* prop);
Rule* remouvePremise(Rule* rule, Property* premise);
Bool isPremiseEmpty(Rule* rule);
ElmOfPremise* getHeadOfPremise(Rule* rule);
Property* getConclusion(Rule* rule);
void printPremise(Rule* rule);
void printRule(Rule* rule);
void printProperties(Property* p);