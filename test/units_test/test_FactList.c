#include "stdlib.h"
#include "stdio.h"
#include "test_include.c"

// Test case for createFactList
void testCreateFactList() {
    Bool (*fnPointer)(void*, void*);
    fnPointer = cmpValue;
    FactList facts = createFactList(fnPointer);
    if (facts != NULL) {
        printf("Pass: createFactList\n");
    } else {
        printf("Fail: createFactList\n");
    }
}

// Test case for addFact and getById
void testAddFactAndGetById() {
    Bool (*fnPointer)(void*, void*);
    fnPointer = cmpValue;
    FactList facts = createFactList(fnPointer);

    elm* aFact = malloc(sizeof(elm));
    aFact->value = 1;
    facts = addFact(facts, aFact);

    elm* retrievedFact = getById(facts, 0);
    if (retrievedFact != NULL && retrievedFact->value == 1) {
        printf("Pass: addFact and getById\n");
    } else {
        printf("Fail: addFact and getById\n");
    }
}

// Test case for isAlreadyInFactList
void testIsAlreadyInFactList() {
    Bool (*fnPointer)(void*, void*);
    fnPointer = cmpValue;
    FactList facts = createFactList(fnPointer);

    elm* aFact = malloc(sizeof(elm));
    aFact->value = 1;
    facts = addFact(facts, aFact);

    elm* aCopyOfFact = malloc(sizeof(elm));
    aCopyOfFact->value = 1;

    if (isAlreadyInFactList(facts, aCopyOfFact)) {
        printf("Pass: isAlreadyInFactList\n");
    } else {
        printf("Fail: isAlreadyInFactList\n");
    }
}

// Test case for isPresentInFactList
void testIsPresentInFactList() {
    Bool (*fnPointer)(void*, void*);
    fnPointer = cmpValue;
    FactList facts = createFactList(fnPointer);

    elm* aFact = malloc(sizeof(elm));
    aFact->value = 1;
    facts = addFact(facts, aFact);

    if (isPresentInFactList(facts, aFact)) {
        printf("Pass: isPresentInFactList\n");
    } else {
        printf("Fail: isPresentInFactList\n");
    }
}

// Test case for removeAllFacts
void testRemoveAllFacts() {
    Bool (*fnPointer)(void*, void*);
    fnPointer = cmpValue;
    FactList facts = createFactList(fnPointer);

    elm* aFact = malloc(sizeof(elm));
    aFact->value = 1;
    facts = addFact(facts, aFact);

    facts = removeAllFacts(facts);

    if (facts->head == NULL) {
        printf("Pass: removeAllFacts\n");
    } else {
        printf("Fail: removeAllFacts\n");
    }
}

// Test case for freeFactList
void testFreeFactList() {
    Bool (*fnPointer)(void*, void*);
    fnPointer = cmpValue;
    FactList facts = createFactList(fnPointer);

    elm* aFact = malloc(sizeof(elm));
    aFact->value = 1;
    facts = addFact(facts, aFact);

    facts = freeFactList(facts);

    if (facts == NULL) {
        printf("Pass: freeFactList\n");
    } else {
        printf("Fail: freeFactList\n");
    }
}

int main() {
    testCreateFactList();
    testAddFactAndGetById();
    testIsAlreadyInFactList();
    testIsPresentInFactList();
    testRemoveAllFacts();
    testFreeFactList();

    return 0;
}