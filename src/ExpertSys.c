#include "../include/ExpertSys.h"
#include <stdlib.h>

int expertSystem(FactList factsToTest, FactList resultFacts, DB db){
    if(isDBEmpty(db)){
        return 1;
    }
    if(isEmptyFactList(factsToTest)){
        return 2;
    }
    if(!isEmptyFactList(resultFacts)){
        return 3;
    }

    while(!isEmptyFactList(factsToTest) && !isUndefinedProperty(factsToTest->head->fact)){
        void* current_fact = factsToTest->head->fact;

        ElmOfDB* current_elm_of_db = db->head;
        while(current_elm_of_db != NULL){
            Boolean is_rule_find = False;
            Rule current_rule = current_elm_of_db->rule;
            ElmOfPremise* current_premise = current_rule->premise.head;
            ElmOfPremise* previous_premise = NULL;

            while(current_premise != NULL){
                if(current_premise->premise == current_fact) {
                    if(previous_premise == NULL) {
                        current_rule->premise.head = current_premise->next;
                    } else {
                        previous_premise->next = current_premise->next;
                        if(current_premise->next == NULL) {
                            current_rule->premise.tail = previous_premise;
                            previous_premise->next = NULL;
                        }
                    }
                    current_elm_of_db = current_elm_of_db->next;
                    is_rule_find = True;
                    free(current_premise);
                    current_premise = NULL;
                    if(isPremiseEmpty(current_rule)) {
                        resultFacts = addFact(resultFacts, current_rule->conclusion);
                        factsToTest = addFact(factsToTest, current_rule->conclusion);
                        db = removeARuleAndFree(db, current_rule);
                    }
                }else{
                    previous_premise = current_premise;
                    current_premise = current_premise->next;
                }
            }
            if(is_rule_find == False){
                current_elm_of_db = current_elm_of_db->next;
            }
        }
        factsToTest = removeAFact(factsToTest, current_fact);
    }
    return 0;
}
