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
    Bool (*isEmpty)(void *);
    void (*freeValue)(void*);
}PreFactList;

typedef PreFactList* FactList;

FactList createFactList(Bool (*cmpValue)(void*, void*),Bool (*isEmpty)(void *) , void(*freeValue)(void*));//
FactList addFact(FactList list, void* fact);//
FactList removeAllFactsAndFree(FactList list);//
FactList removeAllFacts(FactList list);//
FactList removeAFact(FactList list, void* fact);//
FactList removeAFactAndFree(FactList list, void* fact);//
FactList removeAFactById(FactList list, long id);//
FactList removeAFactByIdAndFree(FactList list, long id);//
FactList freeFactList(FactList list);//
Bool isAlreadyInFactList(FactList list, void* fact);//
Bool isPresentInFactList(FactList list, void* fact);//
Bool isEmptyFactList(FactList list);//
Bool isUndefinedFactList(FactList list);//
ElmOfFact* getHeadOfFactList(FactList list);//
ElmOfFact* nextOfFactList(ElmOfFact* elm);//
void* getFactById(FactList list, long id);//
long getIdOfFact(ElmOfFact*);//
void* getFact(ElmOfFact*);//
Bool isEmptyProperty(FactList facts,void* prop);//

#endif // FACTLIST_H
