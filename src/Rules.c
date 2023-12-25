#include "../include/Rules.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

 void affectValues(Properties* source, Properties* dest){
    strcpy( dest->name,source->name);
    strcpy( dest->desc,source->desc);
}

Bool isEmptyProperty(Properties prop){
    if(prop.name != NULL){
        return False;
    }else{
        return True;
    }
}

Bool cmpProperty(Properties p1, Properties p2){
    if(p1.name==p2.name){
        return True;
    } else{
        return False;
    }
}

void printProperties(Properties* p){
    if(p!=NULL){
        printf("name:%s desc:%s\n",p->name,p->desc);
    }
}

Rules* createEmptyRule(){
    Rules* newl = malloc(sizeof (Rules));
    newl->is_true=False;
    newl->conclusion=NULL;
    newl->premise=NULL;
    return newl;
}

Rules* addPremise(Rules* rules,Properties premise){
    if(premise.name != NULL && premise.desc != NULL){
        if((strcmp(premise.name,"")!=0)){
            ElmOfProperties* newl = malloc(sizeof(ElmOfProperties));
            affectValues(&premise,&newl->value);
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


Rules* createConclusion(Rules* rule, Properties* conclusion){
    if(isEmptyProperty(*conclusion)){
        if(rule!=NULL || rule->premise!=NULL){
            if(isEmptyProperty(rule->premise->value)==False){
                   rule->conclusion=conclusion;
                   return rule;
            }
        }
    }
}

Bool PropertiesInPremise(ListOfProperties premise, Properties prop){
    if(cmpProperty(premise->value,prop)==True){
        return True;
    }
    return PropertiesInPremise(premise->next,prop);
}

Rules* remouvePremise(Rules* rule,Properties premise){
    if(rule->premise!=NULL){
        ElmOfProperties* point = rule->premise;
        while (point->next!=NULL){
            if(cmpProperty(point->value,premise)){
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

Properties* getConclusion(Rules* rule){
    return rule->conclusion;
}

void printPremise(Rules* rule){
    ElmOfProperties *point = rule->premise;
    while (point!=NULL){
        printProperties(&point->value);
        point=point->next;
    }
}

void printRule(Rules* rule){
    printPremise(rule);
    printProperties(rule->conclusion);
    if(rule->is_true==True){
        printf("Rule is True\n");
    }else{
        printf("Rule is False\n");
    }
}