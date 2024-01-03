#include "Rules.h"

typedef struct elm3{
    Rule rule;
    struct elm3* next;
}ElmOfBC;

typedef struct {
    ElmOfBC* head;
    ElmOfBC* tail;
    FactList facts;
}PreCB;

typedef PreCB* CB;

CB createEmptyBC(FactList facts);
CB addRuleToBC(CB bc, Rule rule);
Rule getHeadRule(CB bc);
CB copyOfBC(CB bc);
FactList freeBC(CB bc);