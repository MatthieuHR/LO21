#include "Rules.h"

typedef struct elm3{
    Rule* rule;
    struct elm3* next;
}ElmOfBC;

typedef ElmOfBC * BC;

BC createEmptyBC();
BC addRuleToBC(BC bc, Rule* rule);
Rule* getHeadRule(BC bc);