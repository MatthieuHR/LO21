#include "../include/Rules.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

Rules* createEmptyRule(){
    Rules* newl = malloc(sizeof (Rules));
    newl->is_true=False;
    newl->conclusion.name="None";
    newl->conclusion.desc="None";
    newl->premise=NULL;
    return newl;
}

Rules* addPremise(Rules* rules,Properties premise){
    if(premise.name != NULL && premise.desc != NULL){
        if((strcmp(premise.name,"")!=0)){
            ElmOfProperties* newl = malloc(sizeof(ElmOfProperties));
            strcpy( newl->value.name,premise.name);
            strcpy( newl->value.desc,premise.desc);
            newl->next=NULL;
            newl->prev=NULL;
            if(rules==NULL){
                rules = createEmptyRule();
            }
            if(rules->premise==NULL){
                rules->premise=newl;
            } else{
                ElmOfProperties* point = rules->premise;
                while (point->next != NULL){
                    point = point->next;
                }
                point->next=newl;
                newl->prev=point;
            }
            return rules;
        }
    }
}


Rules* createConclusion(Rules* rule, Properties conclusion){
    if(conclusion.name != NULL && conclusion.desc != NULL){
        if(strcmp(conclusion.name,"")!=0){
            if(rule!=NULL || rule->premise!=NULL){
                if(rule->premise->value.name != NULL){
                    rule->conclusion=conclusion;
                    return rule;
                }
            }
        }
    }
}

Bool PropertiesInPremise(ListOfProperties premise, Properties prop){
    if(premise->value.name==prop.name){
        return True;
    }
    return PropertiesInPremise(premise->next,prop);
}

Rules* remouvePremise(Rules* rule,Properties premise){
    if(rule->premise!=NULL){
        ElmOfProperties* point = rule->premise;
        while (point->next!=NULL){
            if(point->value.name == premise.name){
                point->prev->next=point->next;
                point->next->prev=point->prev;
                free(point);
                return rule;
            }
            point = point->next;
        }
    }
    return rule;
}

Bool isPremiseEmpty(Rules* rule){
    if(rule->premise==NULL){
        return True;
    } else{
        return False;
    }
}

ElmOfProperties* getHeadOfPremise(Rules* rule){
    if(isPremiseEmpty(rule) == True){
        return NULL;
    }else{
        return rule->premise;
    }
}

Properties getConclusion(Rules* rule){
    return rule->conclusion;
}