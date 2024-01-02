#include "Properties.h"

typedef struct elm{
    long id;
    void* fact;
    struct elm* next;
}ElmOfFact;

typedef struct {
    ElmOfFact* head;
    int last_id;
    Bool (*cmpValue)(void *, void*);
}PreFactList;

typedef PreFactList* FactList;

FactList createFactList(Bool (*cmpValue)(void*, void*));//work
FactList addFact(FactList list, void* fact);//work
FactList removeAllFacts(FactList list);//work
FactList freeFactList(FactList list);
Bool isAlreadyInFactList(FactList list, void* fact);//work
Bool isPresentInFactList(FactList list, void* fact);
void* getById(FactList list, long id);//work
