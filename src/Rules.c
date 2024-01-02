#include "../include/Rules.h"
#include "stdlib.h"
#include "stdio.h"

//Function to create an empty Rule with all pointer initialise on NULL
Rule createEmptyRule(FactList facts){
    Rule newl = malloc(sizeof (Rule));
    newl->conclusion=NULL;
    newl->premise.tail=NULL;
    newl->premise.head=NULL;
    newl->facts = facts;
    return newl;
}

//Function to add a Property in the premise field to a Rule
Rule addPremise(Rule rule, void* premise){
    printf("b");
        if(!isEmptyProperty(premise) && rule!=NULL && isPresentInFactList(rule->facts, premise)){
            printf("b");
            ElmOfPremise* new = (ElmOfPremise*)malloc(sizeof(ElmOfPremise));
            printf("b");
            new->premise=premise;
            printf("b");
            new->next=NULL;
            printf("b");
            if(rule->premise.head==NULL){
                printf("c");
                rule->premise.head=new;
                printf("c");
                rule->premise.tail=new;
                printf("c");
            }else{
                printf("b");
                rule->premise.tail->next = new;
                printf("b");
                rule->premise.tail=new;
                printf("b");
            }
    }
    return rule;
}

//Fonction to add or update the conclusion field of a rule
Rule createConclusion(Rule rule, void* conclusion){
    if(rule!=NULL && isPresentInFactList(rule->facts, conclusion)){
        rule->conclusion=conclusion;
    }
    return rule;
}

//Function to check if a Property is in the premise field of a Rule
Bool factInPremise(Rule rule, void* prop){
    if(rule == NULL || rule->premise.head == NULL || prop == NULL){return False;}
    if(rule->premise.head->premise==prop){
        return True;
    }
    PreRule new = *rule;
    new.premise.head = new.premise.head->next;
    return factInPremise(&new, prop);
}

//Function to remove(free) a Property in the premise field of a Rule
Rule removePremise(Rule rule, void* premise){
    if(rule != NULL && !isEmptyProperty(premise)){
        if(rule->premise.head != NULL){
            ElmOfPremise* prev = rule->premise.head;
            ElmOfPremise* now = prev->next;
            if(premise==prev->premise){
                if(rule->premise.head==rule->premise.tail){
                    free(prev);
                    rule->premise.head=NULL;
                    rule->premise.tail=NULL;
                }else{
                    free(prev);
                    rule->premise.head=now;
                }
                return rule;
            }else{
                while(now!=NULL){
                    if(now->premise==premise){
                        prev->next=now->next;
                        free(now);
                        return rule;
                    }
                    prev=now;
                    now=now->next;
                }
            }
        }
    }
    return rule;
}

//Function who return True if the premise is empty and False otherwise
Bool isPremiseEmpty(Rule rule){
    if(rule != NULL && rule->premise.head==NULL){
        return True;
    } else{
        return False;
    }
}

//Function who return the first Premise(ElmOfPremise) of a Rule
ElmOfPremise* getHeadOfPremise(Rule rule){
    if(rule == NULL){
        return NULL;
    }else{
        return rule->premise.head;
    }
}

//Function who always return the conclusion field
void* getConclusion(Rule rule){
    if(rule == NULL){return NULL;}
    else{
        return rule->conclusion;
    }
}

FactList getFactListOfRule(Rule rule){
    if(rule == NULL){return NULL;}
    else{return rule->facts;}
}

FactList freeFactList(FactList list){
    if(list != NULL){
        if(list->head != NULL){
            list = removeAllFacts(list);
        }
        free(list);
    }
    return NULL;
}