#include "define.h"

typedef struct {
    char* name;
    char* desc;
}Property;

typedef struct elm{
    Property* fact;
    struct elm* next;
}ElmOfFact;

typedef ElmOfFact* FactList;

Bool isEmptyProperty(Property* prop);
Bool cmpProperty(Property* p1, Property* p2);
void printProperties(Property* p);
FactList createFactList();
FactList addFact(FactList list, Property fact);
FactList remouveAllFacts(FactList list);
Property * isInFactList(FactList list, Property* fact);
