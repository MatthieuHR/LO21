#ifndef DB_H
#define DB_H

#include "Rules.h"

typedef struct elm3{
    Rule rule;
    struct elm3* next;
}ElmOfDB;

typedef struct {
    ElmOfDB* head;
    ElmOfDB* tail;
    FactList facts;
}PreDB;

typedef PreDB* DB;

DB createEmptyDB(FactList facts);
DB addRuleToDB(DB db, Rule rule);
ElmOfDB* getHeadRule(DB db);
ElmOfDB* getNextRule(ElmOfDB* elm);
Rule getRule(ElmOfDB* elm);
DB copyOfDB(DB db);
FactList freeDB(DB db);
FactList getFactListOfDB(DB db);

#endif /* DB_H */
