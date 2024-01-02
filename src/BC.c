#include "../include/BC.h"
#include "stdlib.h"

//Function to create an empty BC
BC createEmptyBC(FactList facts){
    BC new = {NULL,NULL,facts};
    return new;
}

//Function to add a Rule to a BC
BC addRuleToBC(BC bc, Rule* rule){
    if(!isPremiseEmpty(rule) && getConclusion(rule)!=NULL && rule->facts.head == bc.facts.head){
        ElmOfBC* newl = malloc(sizeof (ElmOfBC));
        newl->rule=rule;
        newl->next=NULL;
        if(bc.head == bc.tail){
            bc.head = newl;
            bc.tail = newl;
        }else{
            bc.tail->next=newl;
            bc.tail=newl;
        }
    }
    return bc;
}

//Function to get the first Rule of a BC
Rule* getHeadRule(BC bc){
    if(bc.tail!=NULL){
        return bc.head->rule;
    }else{
        return NULL;
    }
}

BC copyOfBC(BC bc){
    BC new_bc = createEmptyBC(bc.facts);
    ElmOfBC* point = bc.head;
    while (point!=NULL){
        Rule* new_rule = createEmptyRule(bc.facts);
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