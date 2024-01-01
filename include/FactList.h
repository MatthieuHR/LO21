#include "Properties.h"

typedef struct elm{
    long id;
    Property* fact;
    struct elm* next;

}ElmOfFact;

typedef struct {
    ElmOfFact* head;
    int last_id;
    Bool (*cmpValue)(Property*, Property*);
}FactList;

FactList createFactList(Bool (*cmpValue)(Property*, Property*));//work
FactList addFact(FactList list, Property* fact);//work
FactList remouveAllFacts(FactList list);//work
Property* isInFactList(FactList list, Property* fact);//work
Property* getById(FactList list, long id);//work
