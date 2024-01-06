#include "../include/ExpertSys.h"
#include <stdlib.h>

int expertSystem(FactList factsToTest, FactList resultFacts, DB db){
    if(isDBEmpty(db)){
        return 1;
    }
    if(isEmptyFactList(factsToTest)){
        return 2;
    }
    if(isEmptyFactList(resultFacts)){
        return 3;
    }

    while(!isEmptyFactList(factsToTest) && !isUndefinedProperty(factsToTest->head->fact)){
        void* current_fact = factsToTest->head->fact;

        ElmOfDB* ruleNode = db->head;
        while(ruleNode != NULL){
            Rule current_rule = ruleNode->rule;
            ElmOfPremise* current_node = current_rule->premise.head;
            ElmOfPremise* previous_node = NULL;

            while(current_node != NULL){
                if(current_node->premise == current_fact) {
                    if(previous_node == NULL) {
                        current_rule->premise.head = current_node->next;
                    } else {
                        previous_node->next = current_node->next;
                        if(current_node->next == NULL) {
                            current_rule->premise.tail = previous_node;
                            previous_node->next = NULL;
                        }
                    }
                    free(current_node);
                    current_node = NULL;
                    if(isPremiseEmpty(current_rule)) {
                        resultFacts = addFact(resultFacts, current_rule->conclusion);
                        factsToTest = addFact(factsToTest, current_rule->conclusion);
                        db = removeARuleAndFree(db, current_rule);
                    }
                }else{
                    previous_node = current_node;
                    current_node = current_node->next;
                    ruleNode = ruleNode->next;
                }
            }
        }
        factsToTest = removeAFact(factsToTest, current_fact);
    }
    return 0;
}
