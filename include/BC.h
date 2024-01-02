#include "Rules.h"

typedef struct elm3{
    Rule rule;
    struct elm3* next;
}ElmOfBC;

typedef struct {
    ElmOfBC* head;
    ElmOfBC* tail;
    FactList facts;
}PreBC;

typedef PreBC* BC;

BC createEmptyBC(FactList facts);
BC addRuleToBC(BC bc, Rule rule);
Rule getHeadRule(BC bc);
BC copyOfBC(BC bc);
FactList freeBC(BC bc);