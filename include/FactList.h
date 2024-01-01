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
}FactList;

FactList createFactList(Bool (*cmpValue)(void*, void*));//work
FactList addFact(FactList list, void* fact);//work
FactList remouveAllFacts(FactList list);//work
void* isInFactList(FactList list, void* fact);//work
void* getById(FactList list, long id);//work
