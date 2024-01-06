#include "../include/ExpertSys.h"
#include <stdlib.h>

void expertSystem(FactList factsToTest, FactList resultFacts, DB knowledgeBase){
    if(factsToTest == NULL || resultFacts == NULL || knowledgeBase == NULL){
        return;
    }

    while(!isEmptyFactList(factsToTest) && !isEmptyProperty(factsToTest->head->fact)){
        void* current_fact = factsToTest->head->fact;

        ElmOfDB* ruleNode = knowledgeBase->head;
        while(ruleNode != NULL){
            Rule currentRule = ruleNode->rule;
            ElmOfPremise* currentNode = currentRule->premise.head;
            ElmOfPremise* previousNode = NULL;

            while(currentNode != NULL){
                if(currentNode->premise == current_fact) {
                    if(previousNode == NULL) {
                        currentRule->premise.head = currentNode->next;
                    } else {
                        previousNode->next = currentNode->next;
                        if(currentNode->next == NULL) {
                            currentRule->premise.tail = previousNode;
                            previousNode->next = NULL;
                        }
                    }
                    free(currentNode);
                    currentNode = NULL;
                    if(isPremiseEmpty(currentRule)) {
                        resultFacts = addFact(resultFacts, currentRule->conclusion);
                        factsToTest = addFact(factsToTest, currentRule->conclusion);
                        knowledgeBase = removeARule(knowledgeBase, currentRule);
                    }
                }else{
                    previousNode = currentNode;
                    currentNode = currentNode->next;
                }
            }
            ruleNode = ruleNode->next;
        }
        factsToTest = removeAFact(factsToTest, current_fact);
    }
}
