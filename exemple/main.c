

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




void printFactList(FactList list) {
    ElmOfFact* current =list->head;
    while (current!=NULL) {
        printf("ID: %ld, Fact: %s\n",current->id, current->fact );
        current =current->next;
    }
}




void expertsystem(FactList allFacts, FactList factsToTest, FactList resultFacts, DB knowledgeBase){




        //boucle tant que tous les fait ne sont pas testé
        while (factsToTest->head != NULL) {
            ElmOfFact *currentFact = getHeadOfFactList(factsToTest);


            printf("\n caracteres a teste:\n");
            printFactList(factsToTest);




            //prend le premier element de la qui possede une rule
            ElmOfDB *ruleNode = knowledgeBase->head;




            //test si l element est null donc si il y a des rules
            while (ruleNode != NULL) {

                //prend sa rule
                Rule currentRule = ruleNode->rule;

                //prend le premier fait de la rule
                ElmOfPremise *premise = getHeadOfPremise(currentRule);



                //prend l element suiv jusqu a que sa soit nul
                while (premise != NULL) {


                    printf(" elements qui s'oppose  %s ,  %c  \n ",premise->premise,getValue(getFact(currentFact)));

                    // check si il y a l element est egale a un fait
                    if (strcmp(premise->premise, getFact(currentFact) ) == 0) {


                        printf("supprimme l'elements %s \n", currentFact->fact);

                        //supprime l'elements de la liste
                        currentRule = removeFromPremise(currentRule, currentFact->fact);

                    }

                    premise = premise->next;

                }


                //si la rule est vide alors met la conclusion et supprime la rule
                if (isPremiseEmpty(currentRule)) {

                    //recupere la conclusion et la met dans une chaine de caractere
                    char *conclusion = getConclusion(currentRule);

                    printf("vas dans la conclusion  %s  \n", conclusion);

                    //met la conclusion dans a tester et dans la liste de a resultat déduis
                    resultFacts = addFact(resultFacts, conclusion);
                    factsToTest = addFact(factsToTest, conclusion);


                    knowledgeBase = removeARule(knowledgeBase, currentRule);
                }

                //passe a la rule suivante
                ruleNode = ruleNode->next;

            }
            printDB(knowledgeBase);

            //passe au fact suivant de la liste des fact a tester
            factsToTest = removeAFact(factsToTest, currentFact->fact);
        }
}



int main(){

    Bool (*fnPointer)(void*, void*) = cmpValue;
    if(createFactList(NULL) != NULL){
        printf("createFactList() should return NULL if the function pointer is NULL\n");
        exit(1);
    }

    FactList allFacts= createFactList(fnPointer);

    //Ajout des fait à la  liste de tout les faits
    allFacts = addFact(allFacts, "A");
    allFacts = addFact(allFacts,"B");
    allFacts = addFact(allFacts, "C" );
    allFacts = addFact(allFacts, "D");
    allFacts = addFact(allFacts,"E");
    allFacts = addFact(allFacts, "F" );
    allFacts = addFact(allFacts, "G");
    allFacts = addFact(allFacts,"H");
    allFacts = addFact(allFacts, "I" );



    FactList factsToTest = createFactList(fnPointer);

    //Ajout des fait à testé dans la liste de fait a tester
    factsToTest = addFact(factsToTest, "E");
    factsToTest = addFact(factsToTest, "I");
    factsToTest = addFact(factsToTest, "A");
    factsToTest = addFact( factsToTest, "B");



    // Creation de la liste des fait conclu
    FactList resultFacts = createFactList(fnPointer);

    //Creation de la base de connaissance
    DB knowledgeBase = createEmptyDB(allFacts);

    //Création et ajout de règles à la base de connaissances
    Rule rule1 = createEmptyRule(allFacts);

    rule1 = addPremise(rule1,"A");
    rule1= addPremise(rule1,"B");
    rule1 = setConclusion(rule1, "C");

    Rule rule2 = createEmptyRule(allFacts);
    rule2 = addPremise(rule2,"E");
    rule2 = setConclusion(rule2, "D");


    Rule rule3 = createEmptyRule(allFacts);
    rule3 = addPremise(rule3,"D");
    rule3 = addPremise(rule3,"B");
    rule3 = setConclusion(rule3, "H");

    printf("Tout les fait existant:\n");
    printFactList(allFacts);

    printf("\n\nles differentes regles\n");
    printRule(rule1);
    printRule(rule2);
    printRule(rule3);

    //... a continuer

    knowledgeBase = addRuleToDB(knowledgeBase, rule1);
    knowledgeBase = addRuleToDB(knowledgeBase, rule2);
    knowledgeBase = addRuleToDB(knowledgeBase, rule3);

    printf("systeme expert:\n");

    expertsystem(allFacts, factsToTest, resultFacts, knowledgeBase);





    printf("Results:\n");
    printFactList(resultFacts);


    removeAllFacts(allFacts);
    removeAllFacts(factsToTest);
    removeAllFacts(resultFacts);


    return 0;
}


