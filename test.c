/*#include "include/DB.h"
#include <stdio.h>
#include <stdlib.h>

typedef int* elm;

int getValue(elm a){
    return *a;
}
Bool cmpValue(void* a, void* b){
    if(a==NULL || b==NULL){return False;}
    if(getValue(a)== getValue(b)){
        return True;
    }else{
        return False;
    }
}

void printValue(void* a){
    printf("%d\n", getValue(a));
}

void printFactList(FactList list){
    ElmOfFact* now = getHeadOfFactList(list);
    while(now!=NULL){
        printf("%ld: ", getIdOfFact(now));
        printValue(getFact(now));
        now = nextOfFactList(now);
    }
    printf("\n");
}

void printRule(Rule rule){
    ElmOfPremise* now = getHeadOfPremise(rule);
    while(now!=NULL){
        printValue(getPremise(now));
        now = nextOfPremise(now);
    }
    printf("=> ");
    printValue(getConclusion(rule));
    printf("\n");
}

void printDB(DB db){
    ElmOfDB* now = getHeadRule(db);
    while(now!=NULL){
        printf("Rule:\n");
        printRule(getRule(now));
        now = getNextRule(now);
    }
}

int test(){
    Bool (*fnPointer)(void*, void*) = cmpValue;
    if(createFactList(NULL) != NULL){
        printf("createFactList() should return NULL if the function pointer is NULL\n");
        exit(1);
    }

    FactList facts = createFactList(fnPointer);

    for(int i=0; i<10; i++){
        elm e = malloc(sizeof(int));
        *e = i;
        facts = addFact(facts, e);
    }

    printf("Fact list:\n");
    printFactList(facts);

    for(int i=0; i<10; i++){
        elm e = malloc(sizeof(elm));
        *e = i;
        if(isPresentInFactList(facts, e) == True){
            printf("isPresentInFacList() should return False if the element isn't in the list (same memory space)\n");
            exit(1);
        }
        free(e);
    }

    for(int i=0; i<10; i++){
        elm e = malloc(sizeof(elm));
        *e = i;
        if(isAlreadyInFactList(facts, e) == False){
            printf("isAlreadyInFactList() should return True if the element is in the list\n");
            exit(1);
        }
        free(e);
    }

    for(int i=0; i<10; i++){
        if(getById(facts, i) == NULL){
            printf("getById() should return the element with the given id\n");
            exit(1);
        }
    }

    Rule rule = createEmptyRule(facts);
    Rule rule2 = createEmptyRule(facts);
    Rule rule3 = createEmptyRule(facts);

    for(int i=0; i<2; i++){
        rule = addPremise(rule, getById(getFactListOfRule(rule),i));
        rule2 = addPremise(rule2, getById(getFactListOfRule(rule2),i+3));
        rule3 = addPremise(rule3, getById(getFactListOfRule(rule3),i+6));
    }
    rule = setConclusion(rule, getById(getFactListOfRule(rule),2));
    rule2 = setConclusion(rule2, getById(getFactListOfRule(rule2),5));
    rule3 = setConclusion(rule3, getById(getFactListOfRule(rule3),8));

    rule2 = removeFromPremise(rule2, getById(getFactListOfRule(rule2),4));

    printf("Rule 1:\n");
    printRule(rule);
    printf("Rule 2:\n");
    printRule(rule2);
    printf("Rule 3:\n");
    printRule(rule3);

    for (int i=0; i<2; i++){
        if(factInPremise(rule, getById(getFactListOfRule(rule),i)) == False){
            printf("factInPremise() should return False if the element isn't in the premise (same memory space)\n");
            exit(1);
        }
    }

    for (int i=0; i<2; i++){
        if(!factInPremise(rule2, getFactById(getFactListOfRule(rule2),i))){
            printf("factInPremise() should return True if the element is in the premise\n");
            exit(1);
        }
    }

    for (int i=0; i<2; i++){
        if(!factInPremise(rule3, getById(getFactListOfRule(rule3),i))){
            printf("factInPremise() should return True if the element is in the premise\n");
            exit(1);
        }
    }

    DB aDB = createEmptyDB(facts);
    aDB = addRuleToDB(aDB, rule);
    aDB = addRuleToDB(aDB, rule2);

    printf("DB:\n");
    printDB(aDB);

    elm* n9 = getById(getFactListOfDB(aDB), 9);
    if(removeAFact(facts, getById(facts, 9)) == NULL){
        printf("removeAFact() should return a fact list\n");
        exit(1);
    }
    free(n9);

    if(getFactListOfDB(aDB) != facts){
        printf("getFactListOfDB() should return the fact list associated with the DB\n");
        exit(1);
    }

    DB copy = copyOfDB(aDB);

    if(freeDB(aDB) == NULL){
        printf("freeDB() should return a fact list\n");
        exit(1);
    }

    printf("Copy of DB:\n");
    printDB(copy);


    if(freeDB(copy) == NULL){
        printf("freeDB() should return a fact list\n");
        exit(1);
    }

    DB new = createEmptyDB(facts);
    new = addRuleToDB(new, rule3);
    new = removeARule(new, rule3);
    printf("New DB:\n");
    printDB(new);
    if (freeRule(rule3) == NULL){
        printf("freeRule() should return a fact list\n");
        exit(1);
    }

    if (freeDB(new) == NULL){
        printf("freeDB() should return a fact list\n");
        exit(1);
    }

    freeFactList(facts);

    printf("All tests passed!\n");
    return 0;

}
*/