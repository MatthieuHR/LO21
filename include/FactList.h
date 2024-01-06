#ifndef FACTLIST_H
#define FACTLIST_H

#include "Properties.h"

typedef struct elm4{
    long id;
    void* fact;
    struct elm4* next;
}ElmOfFact;

typedef struct {
    ElmOfFact* head;
    long last_id;
    Bool (*cmpValue)(void *, void*);
    void (*freeValue)(void*);
}PreFactList;

typedef PreFactList* FactList;

FactList createFactList(Bool (*cmpValue)(void*, void*), void(*freeValue)(void*));//work
FactList addFact(FactList list, void* fact);//work
FactList removeAllFactsAndFree(FactList list);//work
FactList removeAllFacts(FactList list);//work
FactList removeAFact(FactList list, void* fact);//work
FactList removeAFactById(FactList list, long id);//work
FactList freeFactList(FactList list);//work
Bool isAlreadyInFactList(FactList list, void* fact);//work
Bool isPresentInFactList(FactList list, void* fact);
Bool isEmptyFactList(FactList list);
ElmOfFact* getHeadOfFactList(FactList list);//work
ElmOfFact* nextOfFactList(ElmOfFact* elm);//work
void* getFactById(FactList list, long id);//work
long getIdOfFact(ElmOfFact*);//work
void* getFact(ElmOfFact*);//work

#endif // FACTLIST_H
