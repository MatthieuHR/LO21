#include "../include/Rules.h"
#include "stdlib.h"
#include "stdio.h"

//Function to create an empty Rule with all pointer initialise on NULL
Rule* createEmptyRule(){
    Rule* newl = malloc(sizeof (Rule));
    newl->conclusion=NULL;
    newl->premise=NULL;
    return newl;
}

//Function to add a Property in the premise field to a Rule
Rule* addPremise(Rule* rules, Property* premise){
        if(isEmptyProperty(premise) == False){
            ElmOfPremise* newl = malloc(sizeof(ElmOfPremise));
            newl->premise=premise;
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
Rule* createConclusion(Rule* rule, Property* conclusion){
    if(isEmptyProperty(conclusion)==False){
        if(isEmptyProperty(rule->conclusion)==False) {
            free(rule->conclusion);
        }
        rule->conclusion=conclusion;
    }
    return rule;
}

//Function to check if a Property is in the premise field of a Rule
Bool PropertiesInPremise(Premise premise, Property* prop){
    if(premise == NULL){return False;}
    if(cmpProperty(premise->premise, prop) == True){
        return True;
    }
    return PropertiesInPremise(premise->next,prop);
}

//Function to remove(free) a Property in the premise field of a Rule
Rule* remouvePremise(Rule* rule, Property* premise){
    if(rule->premise!=NULL){
        ElmOfPremise* point = rule->premise;
        if(cmpProperty(point->premise, premise) == True){
            rule->premise=point->next;
            free(point);

        }else{
            if(point->next!=NULL){
                while (point->next!=NULL){
                    if(cmpProperty(point->next->premise, premise) == True){
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
Bool isPremiseEmpty(Rule* rule){
    if(rule->premise==NULL){
        return True;
    } else{
        return False;
    }
}

//Function who return the first Premise(ElmOfPremise) of a Rule
ElmOfPremise* getHeadOfPremise(Rule* rule){
    if(isPremiseEmpty(rule) == True){
        return NULL;
    }else{
        return rule->premise;
    }
}

//Function who always return the conclusion field
Property* getConclusion(Rule* rule){
    return rule->conclusion;
}

//Function who display with style the premise field
void printPremise(Rule* rule){
    ElmOfPremise *point = rule->premise;
    while (point!=NULL){
        printProperties(&point->premise);
        point=point->next;
    }
}

//Function who display with style a Rule
void printRule(Rule* rule){
    printf("Premise :\n");
    printPremise(rule);
    printf("Conclusion:\n");
    printProperties(rule->conclusion);
}