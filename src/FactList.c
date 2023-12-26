#include "../include/FactList.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

//Function to test if a Properties is empty (based on selected criteria)
Bool isEmptyProperty(Properties* prop){
    if(prop->name != NULL){
        return False;
    }else{
        return True;
    }
}

//Function to compare 2 Properties (based on selected criteria) and return True if they are the same and False otherwise
Bool cmpProperty(Properties* p1, Properties* p2){
    if(strcmp(p1->name,p2->name)==0){
        return True;
    } else{
        return False;
    }
}

//Methode to display a Properties
void printProperties(Properties* p){
    if(p!=NULL){
        printf("name:%s desc:%s\n",p->name,p->desc);
    }
}

//Function to transform a Properties to a Properties pointer
Properties* affectField(Properties fact){
    if(fact.desc != NULL && fact.name != NULL){
        Properties* newl = malloc(sizeof(Properties));
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

//Function to add a fact(Properties) in tail to a FactList
FactList addFact(FactList list,Properties fact){
    ElmOfFact* newl = malloc(sizeof(ElmOfFact));
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

//Fonction to get the fact in a FactList and NULL if the fact is not in the Factlist
Properties* isInFactList(FactList list, Properties* fact){
    if(list==NULL){return NULL;}
    if(cmpProperty(list->fact,fact)==True){return list->fact;}
    else{return isInFactList(list->next,fact);}
}

