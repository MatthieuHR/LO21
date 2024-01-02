#include "../include/FactList.h"
#include "stdlib.h"

//Function to create an empty FactList
FactList createFactList(Bool (*cmpValue)(void*, void*)){
    FactList newl = {NULL,-1,cmpValue};
    return newl;
}

ElmOfFact* createElmOfFact() {
    ElmOfFact* newl = malloc(sizeof(ElmOfFact));
    newl->fact = NULL;
    newl->next = NULL;
    newl->id = -1;
    return newl;
}

//Fonction to get the fact in a FactList and NULL if the fact is not in a Factlist
Bool isInFactList(FactList list, void* fact){
    if(list.head==NULL){return False;}
    if(isEqual(list.head->fact,fact,list.cmpValue)){return True;}
    else {
        FactList next = {list.head->next,list.last_id,list.cmpValue};
        return isInFactList(next,fact);
    }
}

//Function to add a fact(Property) in tail to a FactList
FactList addFact(FactList list, void* fact){
    if(!isEmptyProperty(fact) && isInFactList(list,fact) == NULL) {
        ElmOfFact* newl = createElmOfFact();
        newl->fact=fact;
        newl->next=list.head;
        newl->id = list.last_id+1;
        list.head=newl;
        list.last_id+=1;
    }
    return list;
}

//Function to free() all element of a FactList
FactList remouveAllFacts(FactList list){
    ElmOfFact* point = list.head;
    while (point != NULL){
        list.head = point;
        point = point->next;
        free(list.head);
    }
    list.head=NULL;
    list.last_id=-1;
    return list;
}

void* getById(FactList list, long id){
    if(list.head != NULL && id <= list.last_id){
        ElmOfFact* point = list.head;
        while (point->id!=id){
            point=point->next;
        }
        return point->fact;
    }
    return NULL;
}

