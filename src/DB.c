#include "../include/DB.h"
#include "stdlib.h"

//Function to create an empty DB
DB createEmptyBC(FactList facts){
    if(facts->head!=NULL){
        DB new = (DB)malloc(sizeof(PreDB));
        new->tail=NULL;
        new->head=NULL;
        new->facts = facts;
        return new;
    }
    return NULL;
}

//Function to add a Rule to a DB
DB addRuleToBC(DB bc, Rule rule){
    if(bc!=NULL && !isPremiseEmpty(rule) && getConclusion(rule)!=NULL && rule->facts->head == bc->facts->head){
        ElmOfDB* newl = malloc(sizeof (ElmOfDB));
        newl->rule=rule;
        newl->next=NULL;
        if(bc->head == NULL){
            bc->head = newl;
            bc->tail = newl;
        }else{
            bc->tail->next=newl;
            bc->tail=newl;
        }
    }
    return bc;
}

//Function to get the first Rule of a DB
ElmOfDB* getHeadRule(DB bc){
    if(bc != NULL && bc->tail!=NULL){
        return bc->head;
    }else{
        return NULL;
    }
}

DB copyOfBC(DB bc){
    DB new_bc = createEmptyBC(bc->facts);
    ElmOfDB* point = bc->head;
    while (point!=NULL){
        Rule new_rule = createEmptyRule(bc->facts);
        new_rule->conclusion=point->rule->conclusion;
        ElmOfPremise* premise = point->rule->premise.head;
        while (premise!=NULL){
            new_rule = addPremise(new_rule,premise->premise);
            premise=premise->next;
        }
        new_bc = addRuleToBC(new_bc,new_rule);
        point=point->next;
    }
    return new_bc;
}

FactList getFactListOfBC(DB bc){
    return bc->facts;
}

FactList freeBC(DB bc){
    if(bc!=NULL && bc->head!=NULL){
        if(bc->facts==NULL){
            return NULL;
        }
        ElmOfDB* point = bc->head;
        while (point!=NULL){
            ElmOfDB* temp = point;
            freeRule(temp->rule);
            point=point->next;
            free(temp);
        }
        FactList rtn = bc->facts;
        free(bc);
        return rtn;
    }
    return NULL;
}

FactList getFactListOfDB(DB bc){
    if(bc!=NULL){
        return bc->facts;
    }
    return NULL;
}

ElmOfDB* getNextRule(ElmOfDB* elm){
    if(elm!=NULL){
        return elm->next;
    }
    return NULL;
}

Rule getRule(ElmOfDB* elm){
    if(elm!=NULL){
        return elm->rule;
    }
    return NULL;
}