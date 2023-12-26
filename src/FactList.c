#include "../include/FactList.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

Bool isEmptyProperty(Properties* prop){
    if(prop->name != NULL){
        return False;
    }else{
        return True;
    }
}

Bool cmpProperty(Properties* p1, Properties* p2){
    if(strcmp(p1->name,p2->name)==0){
        return True;
    } else{
        return False;
    }
}

void printProperties(Properties* p){
    if(p!=NULL){
        printf("name:%s desc:%s\n",p->name,p->desc);
    }
}

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

FactList createFactList(){
    return malloc(sizeof(FactList));
}

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

FactList remouveAllFacts(FactList list){
    ElmOfFact* point = list;
    while (point != NULL){
        list = point;
        point = point->next;
        free(list);
    }
    return point;
}

Properties* isInFactList(FactList list, Properties* fact){
    if(list==NULL){return NULL;}
    if(cmpProperty(list->fact,fact)==True){return list->fact;}
    else{return isInFactList(list->next,fact);}
}

