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
    Boolean (*cmpValue)(void *, void*);
    Boolean (*isEmpty)(void *);
    void (*freeValue)(void*);
}PreFactList;

typedef PreFactList* FactList;

FactList createFactList(Boolean (*cmpValue)(void*, void*), Boolean (*isEmpty)(void *) , void(*freeValue)(void*));//
FactList addFact(FactList list, void* fact);//
FactList removeAllFactsAndFree(FactList list);//
FactList removeAllFacts(FactList list);//
FactList removeAFact(FactList list, void* fact);//
FactList removeAFactAndFree(FactList list, void* fact);//
FactList removeAFactById(FactList list, long id);//
FactList removeAFactByIdAndFree(FactList list, long id);//
FactList freeFactList(FactList list);//
Boolean isAlreadyInFactList(FactList list, void* fact);//
Boolean isPresentInFactList(FactList list, void* fact);//
Boolean isEmptyFactList(FactList list);//
Boolean isUndefinedFactList(FactList list);//
ElmOfFact* getHeadOfFactList(FactList list);//
ElmOfFact* nextOfFactList(ElmOfFact* elm);//
void* getFactById(FactList list, long id);//
long getIdOfFact(ElmOfFact*);//
void* getFact(ElmOfFact*);//
Boolean isEmptyProperty(FactList facts, void* prop);//

#endif // FACTLIST_H
