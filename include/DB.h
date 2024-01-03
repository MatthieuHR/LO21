#include "Rules.h"

typedef struct elm3{
    Rule rule;
    struct elm3* next;
}ElmOfDB;

typedef struct {
    ElmOfDB* head;
    ElmOfDB* tail;
    FactList facts;
}PreDB;

typedef PreDB* DB;

DB createEmptyBC(FactList facts);
DB addRuleToBC(DB bc, Rule rule);
Rule getHeadRule(DB bc);
DB copyOfBC(DB bc);
FactList freeBC(DB bc);