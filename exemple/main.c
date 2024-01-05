

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
    printf("rentre1\n");



        //verfie si la lsite est null
        while (factsToTest->head != NULL) {
            ElmOfFact *currentFact = factsToTest->head;



            //debug
            ElmOfFact *current = factsToTest->head;
            while (current != NULL) {

                printf("ID: %ld, Fact: %s\n", current->id, current->fact);
                current = current->next;
            }



            // enlève le fact tester de la liste des facts a tester
            factsToTest = removeAFact(factsToTest, currentFact->fact);


            //debug
            printf("test\n");
            printf("//////:: %s :://///\n", currentFact->fact);
            current = factsToTest->head;
            while (current != NULL) {

                printf("ID: %ld, Fact: %s\n", current->id, current->fact);
                current = current->next;
            }
            printf("rentre2\n");

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


                    printf("rentre dans la bouvle ou il test les prop\n");


                    // check si il y a l element est egale a un fait
                    if (strcmp(premise->premise, currentFact->fact) == 0) {


                        printf("supprimme les elllemments %s / %s\n", currentFact->fact, premise->premise);

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

            //passe au fact suivant de la liste des fact a tester

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

    printf("Fact list:\n");
    ElmOfFact* current =allFacts->head;
    while (current!=NULL) {
        printf("ID: %ld, Fact: %s\n", current->id, current->fact);
        current = current->next;
    }

    FactList factsToTest = createFactList(fnPointer);

    //Ajout des fait à testé dans la liste de fait a tester
    factsToTest = addFact(factsToTest, "I");
    factsToTest = addFact(factsToTest, "A");
    factsToTest = addFact( factsToTest, "B");
    factsToTest = addFact(factsToTest, "E");


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


    //... a continuer

    knowledgeBase = addRuleToDB(knowledgeBase, rule1);
    knowledgeBase = addRuleToDB(knowledgeBase, rule2);

    printf("//////////////////////////////////////////////////::::::\n");

    expertsystem(allFacts, factsToTest, resultFacts, knowledgeBase);





    printf("Results:\n");
    printFactList(resultFacts);


    removeAllFacts(allFacts);
    removeAllFacts(factsToTest);
    removeAllFacts(resultFacts);


    return 0;
}


