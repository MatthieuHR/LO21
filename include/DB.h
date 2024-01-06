#ifndef DB_H
#define DB_H

#include "Rules.h"

typedef struct elm3{
    long id;
    Rule rule;
    struct elm3* next;
}ElmOfDB;

typedef struct {
    ElmOfDB* head;
    ElmOfDB* tail;
    FactList facts;
    long last_id;
}PreDB;

typedef PreDB* DB;

DB createEmptyDB(FactList facts);
DB addRuleToDB(DB db, Rule rule);
ElmOfDB* getHeadRule(DB db);
ElmOfDB* getNextRule(ElmOfDB* elm);
Rule getRuleByIDd(DB db, long id);
Rule getRule(ElmOfDB* elm);
long getIdOfRule(ElmOfDB* elm);
DB copyOfDB(DB db);
FactList freeDB(DB db);
FactList getFactListOfDB(DB db);
DB removeARule(DB db,Rule rule);
DB removeARuleById(DB db, long id);
DB removeAllRules(DB db);
Bool isPresentInDB(DB db, Rule rule);
Bool isAlreadyInDB(DB db, Rule rule);
Bool isEmptyDB(DB db);

#endif /* DB_H */
