#include "define.h"
#include "FactList.h"

typedef struct elm1{
    Properties* value;
    struct elm1* next;
}ElmOfPremise;

typedef ElmOfPremise * Premise;

typedef struct{
    Premise premise;
    Properties* conclusion;
}Rules;


Rules* createEmptyRule();
Rules* addPremise(Rules* rules,Properties* premise);
Rules* createConclusion(Rules* rule, Properties* conclusion);
Bool PropertiesInPremise(Premise premise, Properties* prop);
Rules* remouvePremise(Rules* rule,Properties* premise);
Bool isPremiseEmpty(Rules* rule);
ElmOfPremise* getHeadOfPremise(Rules* rule);
Properties* getConclusion(Rules* rule);
void printPremise(Rules* rule);
void printRule(Rules* rule);
void printProperties(Properties* p);