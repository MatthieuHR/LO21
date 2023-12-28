#include "../include/FactList.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

//Function to test if a Property is empty (based on selected criteria)
Bool isEmptyProperty(Property* prop){
    if(prop->name != NULL){
        return False;
    }else{
        return True;
    }
}

//Function to compare 2 Property (based on selected criteria) and return True if they are the same and False otherwise
Bool cmpProperty(Property* p1, Property* p2){
    if(strcmp(p1->name,p2->name)==0){
        return True;
    } else{
        return False;
    }
}

//Methode to display a Property
void printProperties(Property* p){
    if(p!=NULL){
        printf("name:%s desc:%s\n",p->name,p->desc);
    }
}

//Function to transform a Property to a Property pointer
Property* affectField(Property fact){
    if(fact.desc != NULL && fact.name != NULL){
        Property* newl = malloc(sizeof(Property));
        newl->name=fact.name;
        newl->desc=fact.desc;
        return newl;
    }else{
        return NULL;
    }
}

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

