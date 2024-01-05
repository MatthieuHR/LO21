

#include "../include/FactList.h"
#include "../include/DB.h"
#include "../include/define.h"
#include "../include/Rules.h"
#include "../include/Properties.h"
#include "stdio.h"





typedef struct{
    int number;
}elm;

int getValue(elm* var){
    return var->number;
}


Bool cmp(void* p1, void* p2){
    if(getValue(p1) == getValue(p2)){
        return True;
    }else{
        return False;
    }
}


void expertsystem(FactList allFacts, FactList factsToTest, FactList resultFacts, DB knowledgeBase){
    Bool (*fnPointer)(void*,void*);
    fnPointer = cmp;


    FactList stack = createFactList(fnPointer);
    // Copie des faits à tester dans la pile
    ElmOfFact* factNode = factsToTest->head;
    while (factNode != NULL) {
        stack = addFact(stack, factNode->fact);
        factNode = factNode->next;
    }

    while (!isEmptyProperty(stack->head)) {
        char* currentFact = (char*)stack->head->fact;
        stack = removeAllFacts(stack);

        ElmOfDB* ruleNode = knowledgeBase->head;
        while (ruleNode != NULL) {
            Rule currentRule = ruleNode->rule;

            if (factInPremise(currentRule, currentFact)) {
                currentRule = removePremise(currentRule, currentFact);

                if (isPremiseEmpty(currentRule)) {
                    char* conclusion = getConclusion(currentRule);
                    resultFacts = addFact(resultFacts, conclusion);


                    stack = addFact(stack, conclusion);
                }
            }
            ruleNode = ruleNode->next;
        }
    }
}



void printFactList(FactList list) {
    ElmOfFact* current =list->head;
    while (current!=NULL) {
        printf("ID: %ld, Fact: %s\n",current->id, current->fact );
        current =current->next;
    }
}




int main(){

    Bool (*fnPointer)(void*,void*);
    fnPointer = cmp;


    FactList allFacts = createFactList(fnPointer);

    //Ajout des fait à la  liste de tout les faits
    allFacts =addFact(allFacts, "FactA");
    allFacts = addFact(allFacts,"FactB");
    allFacts = addFact(allFacts, "FactC" );


    FactList factsToTest = createFactList(fnPointer);

    //Ajout des fait à testé dans la liste de fait a tester
    factsToTest = addFact(factsToTest, "FactA");
    factsToTest = addFact( factsToTest, "FactB");

    // Creation de la liste des fait conclu
    FactList resultFacts = createFactList(fnPointer);

    //Creation de la base de connaissance
    DB knowledgeBase = createEmptyDB(allFacts);

    //Création et ajout de règles à la base de connaissances
    Rule* rule1 = createEmptyRule(allFacts);
    rule1 = addPremise(rule1,"FactA");
    rule1= addPremise(rule1,"FactB");
    rule1 = setConclusion(rule1, "FactC");

    //... a continuer

    knowledgeBase = addRuleToDB(knowledgeBase, rule1);


    expertsystem(allFacts, factsToTest, resultFacts, knowledgeBase);





    printf("Results:\n");
    printFactList(resultFacts);


    removeAllFacts(allFacts);
    removeAllFacts(factsToTest);
    removeAllFacts(resultFacts);


    return 0;
}


