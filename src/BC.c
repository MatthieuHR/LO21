#include "../include/BC.h"
#include "stdlib.h"

//Function to create an empty BC
BC createEmptyBC(){
    return malloc(sizeof(BC));
}

//Function to add a Rule to a BC
BC addRuleToBC(BC bc, Rule* rule){
    ElmOfBC* newl = malloc(sizeof (BC));
    newl->rule=rule;
    newl->next=NULL;
    if(bc!=NULL){
        ElmOfBC* point = bc;
        while (point->next!=NULL){
            point=point->next;
        }
        point->next=newl;
        return bc;
    } else{
        return newl;
    }
}

//Function to get the first Rule of a BC
Rule* getHeadRule(BC bc){
    if(bc!=NULL){
        return bc->rule;
    }else{
        return NULL;
    }
}