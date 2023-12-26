#include "../include/Rules.h"
#include "stdlib.h"
#include "stdio.h"

//Function to create an empty Rules with all pointer initialise on NULL
Rules* createEmptyRule(){
    Rules* newl = malloc(sizeof (Rules));
    newl->conclusion=NULL;
    newl->premise=NULL;
    return newl;
}

//Function to add a Properties in the premise field to a Rules
Rules* addPremise(Rules* rules,Properties* premise){
        if(isEmptyProperty(premise) == False){
            ElmOfPremise* newl = malloc(sizeof(ElmOfPremise));
            newl->value=premise;
            newl->next=NULL;
            if(rules==NULL){
                rules = createEmptyRule();
            }
            if(rules->premise==NULL){
                rules->premise=newl;
            } else{
                ElmOfPremise* point = rules->premise;
                while (point->next != NULL){
                    point = point->next;
                }
                point->next=newl;
            }
    }
    return rules;
}

//Fonction to add or update the conclusion field of a rule
Rules* createConclusion(Rules* rule, Properties* conclusion){
    if(isEmptyProperty(conclusion)==False){
        if(isEmptyProperty(rule->conclusion)==False) {
            free(rule->conclusion);
        }
        rule->conclusion=conclusion;
    }
    return rule;
}

//Function to check if a Properties is in the premise field of a Rules
Bool PropertiesInPremise(Premise premise, Properties* prop){
    if(premise == NULL){return False;}
    if(cmpProperty(premise->value,prop)==True){
        return True;
    }
    return PropertiesInPremise(premise->next,prop);
}

//Function to remove(free) a Properties in the premise field of a Rules
Rules* remouvePremise(Rules* rule,Properties* premise){
    if(rule->premise!=NULL){
        ElmOfPremise* point = rule->premise;
        if(cmpProperty(point->value,premise)==True){
            rule->premise=point->next;
            free(point);

        }else{
            if(point->next!=NULL){
                while (point->next!=NULL){
                    if(cmpProperty(point->next->value,premise)==True){
                        ElmOfPremise* tmp = point->next;
                        point->next=point->next->next;
                        free(tmp);
                        return rule;
                    }
                    point = point->next;
                }
            }
        }
    }
    return rule;
}

//Function who return True if the premise is empty and False otherwise
Bool isPremiseEmpty(Rules* rule){
    if(rule->premise==NULL){
        return True;
    } else{
        return False;
    }
}

//Function who return the first Premise(ElmOfPremise) of a Rules
ElmOfPremise* getHeadOfPremise(Rules* rule){
    if(isPremiseEmpty(rule) == True){
        return NULL;
    }else{
        return rule->premise;
    }
}

//Function who always return the conclusion field
Properties* getConclusion(Rules* rule){
    return rule->conclusion;
}

//Function who display with style the premise field
void printPremise(Rules* rule){
    ElmOfPremise *point = rule->premise;
    while (point!=NULL){
        printProperties(&point->value);
        point=point->next;
    }
}

//Function who display with style a Rules
void printRule(Rules* rule){
    printf("Premise :\n");
    printPremise(rule);
    printf("Conclusion:\n");
    printProperties(rule->conclusion);
}