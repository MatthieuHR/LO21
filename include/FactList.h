#include "define.h"

typedef struct {
    char* name;
    char* desc;
}Properties;

typedef struct elm{
    Properties* fact;
    struct elm* next;
}ElmOfFact;

typedef ElmOfFact* FactList;

Bool isEmptyProperty(Properties* prop);
Bool cmpProperty(Properties* p1, Properties* p2);
void printProperties(Properties* p);
FactList createFactList();
FactList addFact(FactList list,Properties fact);
FactList remouveAllFacts(FactList list);
Properties * isInFactList(FactList list, Properties* fact);
