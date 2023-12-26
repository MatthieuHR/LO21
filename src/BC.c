#include "../include/BC.h"
#include "stdlib.h"

//Function to create an empty BC
BC createEmptyBC(){
    return malloc(sizeof(BC));
}

//Function to add a Rules to a BC
BC addRuleToBC(BC bc,Rules* rule){
    ElmBC* newl = malloc(sizeof (BC));
    newl->rule=rule;
    newl->next=NULL;
    if(bc!=NULL){
        ElmBC* point = bc;
        while (point->next!=NULL){
            point=point->next;
        }
        point->next=newl;
        return bc;
    } else{
        return newl;
    }
}

//Function to get the first Rules of a BC
Rules* getHeadRule(BC bc){
    if(bc!=NULL){
        return bc->rule;
    }else{
        return NULL;
    }
}