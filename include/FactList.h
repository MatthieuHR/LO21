#include "Properties.h"

typedef struct elm{
    Property* fact;
    struct elm* next;
}ElmOfFact;

typedef ElmOfFact* FactList;

FactList createFactList();
FactList addFact(FactList list, Property fact);
FactList remouveAllFacts(FactList list);
Property * isInFactList(FactList list, Property* fact);
FactList transferFact(FactList list, Property* fact);
