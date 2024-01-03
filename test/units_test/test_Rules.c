#include "stdio.h"
#include "test_include.c"



int main() {
    // Create a FactList
    Bool (*fnPointer)(void*, void*);
    fnPointer = cmpValue;
    FactList facts = createFactList(fnPointer);

    // Create an empty Rule
    Rule rule = createEmptyRule(facts);

    // Add premises to the Rule
    elm* premise1 = malloc(sizeof(elm));
    premise1->value = 1;
    rule = addPremise(rule, premise1);

    elm* premise2 = malloc(sizeof(elm));
    premise2->value = 2;
    rule = addPremise(rule, premise2);

    // Set the conclusion of the Rule
    elm* conclusion = malloc(sizeof(elm));
    conclusion->value = 3;
    rule = setConclusion(rule, conclusion);

    // Check if a Property is in the premise field of the Rule
    if (factInPremise(rule, premise1)) {
        printf("Pass\n");
    }

    // Remove a Property from the premise field of the Rule
    rule = removeFromPremise(rule, premise2);

    // Check if the premise of the Rule is empty
    if (isPremiseEmpty(rule)) {
        printf("Pass\n");
    }

    // Get the head element of the premise
    ElmOfPremise* head = getHeadOfPremise(rule);
    if (head != NULL) {
        elm* premise = (elm*)getPremise(head);
        printf("%d\n", premise->value);
    }

    // Get the conclusion of the Rule
    elm* ruleConclusion = (elm*)getConclusion(rule);
    if (ruleConclusion != NULL) {
        printf("%d\n", ruleConclusion->value);
    }

    // Get the FactList associated with the Rule
    FactList ruleFacts = getFactListOfRule(rule);
    if (ruleFacts != NULL) {
        printf("FactList found\n");
    }

    // Free the Rule and its associated premise
    facts = freeRule(rule);
    if (facts != NULL) {
        printf("FactList freed\n");
    }

    // Free the FactList
    facts = freeFactList(facts);
    if (facts == NULL) {
        printf("FactList freed\n");
    }

    return 0;
}