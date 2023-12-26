#include "../include/Rules.h"
#include "stdlib.h"
#include "stdio.h"


Rules* createEmptyRule(){
    Rules* newl = malloc(sizeof (Rules));
    newl->is_true=False;
    newl->conclusion=NULL;
    newl->premise=NULL;
    return newl;
}

Rules* addPremise(Rules* rules,Properties* premise){
        if(isEmptyProperty(premise) == False){
            ElmOfRules* newl = malloc(sizeof(ElmOfRules));
            newl->value=premise;
            newl->next=NULL;
            if(rules==NULL){
                rules = createEmptyRule();
            }
            if(rules->premise==NULL){
                rules->premise=newl;
            } else{
                ElmOfRules* point = rules->premise;
                while (point->next != NULL){
                    point = point->next;
                }
                point->next=newl;
            }
    }
    return rules;
}


Rules* createConclusion(Rules* rule, Properties* conclusion){
    if(isEmptyProperty(conclusion)==False){
        if(isEmptyProperty(rule->conclusion)==False) {
            free(rule->conclusion);
        }
        rule->conclusion=conclusion;
    }
    return rule;
}

Bool PropertiesInPremise(ListOfProperties premise, Properties* prop){
    if(premise == NULL){return False;}
    if(cmpProperty(premise->value,prop)==True){
        return True;
    }
    return PropertiesInPremise(premise->next,prop);
}

Rules* remouvePremise(Rules* rule,Properties* premise){
    if(rule->premise!=NULL){
        ElmOfRules* point = rule->premise;
        if(cmpProperty(point->value,premise)==True){
            rule->premise=point->next;
            free(point);

        }else{
            if(point->next!=NULL){
                while (point->next!=NULL){
                    if(cmpProperty(point->next->value,premise)==True){
                        ElmOfRules* tmp = point->next;
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

Bool isPremiseEmpty(Rules* rule){
    if(rule->premise==NULL){
        return True;
    } else{
        return False;
    }
}

ElmOfRules* getHeadOfPremise(Rules* rule){
    if(isPremiseEmpty(rule) == True){
        return NULL;
    }else{
        return rule->premise;
    }
}

Properties* getConclusion(Rules* rule){
    return rule->conclusion;
}

void printPremise(Rules* rule){
    ElmOfRules *point = rule->premise;
    while (point!=NULL){
        printProperties(&point->value);
        point=point->next;
    }
}

void printRule(Rules* rule){
    printf("Premise :\n");
    printPremise(rule);
    printf("Conclusion:\n");
    printProperties(rule->conclusion);
    if(rule->is_true==True){
        printf("Rule is True\n");
    }else{
        printf("Rule is False\n");
    }
}