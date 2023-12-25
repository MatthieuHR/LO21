#include "../include/BC.h"
#include "stdlib.h"

BC createEmptyBC(){
    return malloc(sizeof(BC));
}

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

Rules* getHeadRule(BC bc){
    if(bc!=NULL){
        return bc->rule;
    }else{
        return NULL;
    }
}