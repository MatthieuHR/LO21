#include "Rules.h"

typedef struct elm{
    Rules* rule;
    struct elm* next;
}ElmBC;

typedef ElmBC * BC;

BC createEmptyBC();
BC addRuleToBC(BC bc,Rules* rule);
Rules* getHeadRule(BC bc);