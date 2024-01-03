#include "test_include.c"
#include "stdio.h"

int main() {
    // Test createEmptyDB
    FactList facts = createFactList(cmpValue);
    DB db = createEmptyDB(facts);
    if (db != NULL) {
        printf("Pass: createEmptyDB\n");
    } else {
        printf("Fail: createEmptyDB\n");
    }

    // Test addRuleToDB
    Rule rule = createEmptyRule(facts);
    db = addRuleToDB(db, rule);
    if (db->head != NULL) {
        printf("Pass: addRuleToDB\n");
    } else {
        printf("Fail: addRuleToDB\n");
    }

    // Test getHeadRule
    ElmOfDB* headRule = getHeadRule(db);
    if (headRule != NULL) {
        printf("Pass: getHeadRule\n");
    } else {
        printf("Fail: getHeadRule\n");
    }

    // Test copyOfDB
    DB copiedDB = copyOfDB(db);
    if (copiedDB != NULL) {
        printf("Pass: copyOfDB\n");
    } else {
        printf("Fail: copyOfDB\n");
    }

    // Test getFactListOfDB
    FactList factList = getFactListOfDB(db);
    if (factList != NULL) {
        printf("Pass: getFactListOfDB\n");
    } else {
        printf("Fail: getFactListOfDB\n");
    }

    // Test freeDB
    FactList freedFactList = freeDB(db);
    if (freedFactList == facts) {
        printf("Pass: freeDB\n");
    } else {
        printf("Fail: freeDB\n");
    }

    // Test getNextRule
    ElmOfDB* nextRule = getNextRule(headRule);
    if (nextRule == NULL) {
        printf("Pass: getNextRule\n");
    } else {
        printf("Fail: getNextRule\n");
    }

    // Test getRule
    Rule retrievedRule = getRule(headRule);
    if (retrievedRule == rule) {
        printf("Pass: getRule\n");
    } else {
        printf("Fail: getRule\n");
    }

    return 0;
}