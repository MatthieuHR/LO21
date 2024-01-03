#include <stdio.h>
#include "../include/FactList.h"

// Test createFactList function
void test_createFactList() {
    // Test case 1: cmpValue is not NULL
    FactList list1 = createFactList(NULL);
    if (list1 == NULL) {
        printf("Test case 1 failed: createFactList returned NULL\n");
    } else {
        printf("Test case 1 passed\n");
    }

    // Test case 2: cmpValue is not NULL
    Bool cmpValue(void* a, void* b) {
        return (*(int*)a == *(int*)b);
    }
    FactList list2 = createFactList(cmpValue);
    if (list2 == NULL) {
        printf("Test case 2 failed: createFactList returned NULL\n");
    } else {
        printf("Test case 2 passed\n");
    }
}

// Test addFact function
void test_addFact() {
    // Test case 1: Add a fact to an empty FactList
    FactList list1 = createFactList(NULL);
    int fact1 = 10;
    list1 = addFact(list1, &fact1);
    if (list1->head->fact != &fact1) {
        printf("Test case 1 failed: Fact not added to FactList\n");
    } else {
        printf("Test case 1 passed\n");
    }

    // Test case 2: Add a fact that is already in the FactList
    FactList list2 = createFactList(NULL);
    int fact2 = 20;
    list2 = addFact(list2, &fact2);
    list2 = addFact(list2, &fact2);
    if (list2->head->next != NULL) {
        printf("Test case 2 failed: Duplicate fact added to FactList\n");
    } else {
        printf("Test case 2 passed\n");
    }
}

// Test removeAllFacts function
void test_removeAllFacts() {
    // Test case 1: Remove all facts from a non-empty FactList
    FactList list1 = createFactList(NULL);
    int fact1 = 10;
    list1 = addFact(list1, &fact1);
    list1 = removeAllFacts(list1);
    if (list1->head != NULL || list1->last_id != -1) {
        printf("Test case 1 failed: Facts not removed from FactList\n");
    } else {
        printf("Test case 1 passed\n");
    }

    // Test case 2: Remove all facts from an empty FactList
    FactList list2 = createFactList(NULL);
    list2 = removeAllFacts(list2);
    if (list2->head != NULL || list2->last_id != -1) {
        printf("Test case 2 failed: Facts not removed from FactList\n");
    } else {
        printf("Test case 2 passed\n");
    }
}

// Test getById function
void test_getById() {
    // Test case 1: Get a fact by ID from a non-empty FactList
    FactList list1 = createFactList(NULL);
    int fact1 = 10;
    list1 = addFact(list1, &fact1);
    void* result1 = getById(list1, 0);
    if (result1 != &fact1) {
        printf("Test case 1 failed: Incorrect fact retrieved\n");
    } else {
        printf("Test case 1 passed\n");
    }

    // Test case 2: Get a fact by ID from an empty FactList
    FactList list2 = createFactList(NULL);
    void* result2 = getById(list2, 0);
    if (result2 != NULL) {
        printf("Test case 2 failed: Incorrect fact retrieved\n");
    } else {
        printf("Test case 2 passed\n");
    }
}

// Test isPresentInFactList function
void test_isPresentInFactList() {
    // Test case 1: Check if a fact is present in a non-empty FactList
    FactList list1 = createFactList(NULL);
    int fact1 = 10;
    list1 = addFact(list1, &fact1);
    Bool result1 = isPresentInFactList(list1, &fact1);
    if (result1 != True) {
        printf("Test case 1 failed: Fact not found in FactList\n");
    } else {
        printf("Test case 1 passed\n");
    }

    // Test case 2: Check if a fact is present in an empty FactList
    FactList list2 = createFactList(NULL);
    int fact2 = 20;
    Bool result2 = isPresentInFactList(list2, &fact2);
    if (result2 != False) {
        printf("Test case 2 failed: Fact found in FactList\n");
    } else {
        printf("Test case 2 passed\n");
    }
}

// Test freeFactList function
void test_freeFactList() {
    // Test case 1: Free a non-empty FactList
    FactList list1 = createFactList(NULL);
    int fact1 = 10;
    list1 = addFact(list1, &fact1);
    list1 = freeFactList(list1);
    if (list1 != NULL) {
        printf("Test case 1 failed: FactList not freed\n");
    } else {
        printf("Test case 1 passed\n");
    }

    // Test case 2: Free an empty FactList
    FactList list2 = createFactList(NULL);
    list2 = freeFactList(list2);
    if (list2 != NULL) {
        printf("Test case 2 failed: FactList not freed\n");
    } else {
        printf("Test case 2 passed\n");
    }
}

int main() {
    test_createFactList();
    test_addFact();
    test_removeAllFacts();
    test_getById();
    test_isPresentInFactList();
    test_freeFactList();

    return 0;
}