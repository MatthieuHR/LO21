#include "Rules.h"

typedef struct elm3{
    Rules* rule;
    struct elm3* next;
}ElmBC;

typedef ElmBC * BC;

BC createEmptyBC();
BC addRuleToBC(BC bc,Rules* rule);
Rules* getHeadRule(BC bc);