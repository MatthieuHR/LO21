#include "../include/FactList.h"
#include "stdlib.h"

//Function to create an empty FactList
FactList createFactList(){
    return malloc(sizeof(FactList));
}

//Function to add a fact(Property) in tail to a FactList
FactList addFact(FactList list, Property fact){
    ElmOfFact* newl = createFactList();
    if((newl->fact= affectField(fact)) == NULL){
        return NULL;
    }
    newl->next=NULL;
    if(list != NULL){
        newl->next=list;
    }
    return newl;
}

//Function to free() all element of a FactList
FactList remouveAllFacts(FactList list){
    ElmOfFact* point = list;
    while (point != NULL){
        list = point;
        point = point->next;
        free(list);
    }
    return point;
}

//Fonction to get the fact in a FactList and NULL if the fact is not in a Factlist
Property* isInFactList(FactList list, Property* fact){
    if(list==NULL){return NULL;}
    if(cmpProperty(list->fact,fact)==True){return list->fact;}
    else{return isInFactList(list->next,fact);}
}

FactList transferFact(FactList list, Property* fact){
    if(isInFactList(list,fact)==NULL){
        ElmOfFact* new = malloc(sizeof(ElmOfFact));
        new->fact = fact;
        new->next=list;
        return new;
    } else{
        return list;
    }
}

