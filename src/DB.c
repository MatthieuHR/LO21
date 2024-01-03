    #include "../include/DB.h"
    #include "stdlib.h"

    /*
     * Function to create an empty DB.
     * 
     * This function creates a new DB (Database) with no entries.
     * It takes a FactList as a parameter, which is a linked list of facts.
     * If the FactList is not empty, it allocates memory for a new DB,
     * initializes its fields, and returns the new DB.
     * If the FactList is empty, it returns NULL.
     * 
     * @param facts The FactList to be associated with the new DB.
     * @return The newly created DB, or NULL if the FactList is empty.
     */
    DB createEmptyDB(FactList facts){
        if(facts->head!=NULL){
            DB new = (DB)malloc(sizeof(PreDB));
            new->tail=NULL;
            new->head=NULL;
            new->facts = facts;
            return new;
        }
        return NULL;
    }

    /**
     * Function to add a Rule to a DB.
     * 
     * @param db The DB to add the Rule to.
     * @param rule The Rule to be added.
     * @return The updated DB with the Rule added or not.
     */
    DB addRuleToDB(DB db, Rule rule){
        if(db!=NULL && !isPremiseEmpty(rule) && getConclusion(rule)!=NULL && rule->facts->head == db->facts->head){
            ElmOfDB* newl = malloc(sizeof (ElmOfDB));
            newl->rule=rule;
            newl->next=NULL;
            if(db->head == NULL){
                db->head = newl;
                db->tail = newl;
            }else{
                db->tail->next=newl;
                db->tail=newl;
            }
        }
        return db;
    }

    /**
     * Function to get the first Rule of a DB.
     * 
     * @param db The DB to retrieve the first Rule from.
     * @return The first Rule of the DB, or NULL if the DB is empty.
     */
    ElmOfDB* getHeadRule(DB db){
        if(db != NULL && db->tail!=NULL){
            return db->head;
        }else{
            return NULL;
        }
    }

    /**
     * @brief Creates a copy of a database.
     * 
     * This function creates a copy of the given database by iterating through each rule in the database
     * and creating a new rule with the same conclusion and premises. The copied rules are then added to
     * the new database.
     * 
     * @param db The original database to be copied.
     * @return The copied database.
     */
    DB copyOfDB(DB db){
        DB new_db = createEmptyDB(db->facts);
        ElmOfDB* point = db->head;
        while (point!=NULL){
            Rule new_rule = createEmptyRule(db->facts);
            new_rule->conclusion=point->rule->conclusion;
            ElmOfPremise* premise = point->rule->premise.head;
            while (premise!=NULL){
                new_rule = addPremise(new_rule,premise->premise);
                premise=premise->next;
            }
            new_db = addRuleToDB(new_db,new_rule);
            point=point->next;
        }
        return new_db;
    }

    /**
     * Retrieves the list of facts associated with a given DB (DB).
     *
     * @param db The DB for which to retrieve the fact list.
     * @return The fact list associated with the DB.
     */
    FactList getFactListOfDB(DB db){
        return db->facts;
    }

    /**
     * @brief Frees the memory allocated for a database and returns the list of facts.
     * 
     * This function frees the memory allocated for a database and returns the list of facts.
     * It iterates through each element of the database, frees the associated rule, and then frees the element itself.
     * Finally, it frees the database structure itself and returns the list of facts.
     * 
     * @param db The database to be freed.
     * @return The list of facts.
     *         If the database is NULL or empty, returns NULL.
     */
    FactList freeDB(DB db){
        if(db!=NULL && db->head!=NULL){
            if(db->facts==NULL){
                return NULL;
            }
            ElmOfDB* point = db->head;
            while (point!=NULL){
                ElmOfDB* temp = point;
                freeRule(temp->rule);
                point=point->next;
                free(temp);
            }
            FactList rtn = db->facts;
            free(db);
            return rtn;
        }
        return NULL;
    }

    /**
     * Retrieves the list of facts from the given database.
     *
     * @param db The database to retrieve the facts from.
     * @return The list of facts in the database, or NULL if the database is empty.
     */
    FactList getFactListOfDB(DB db){
        if(db!=NULL){
            return db->facts;
        }
        return NULL;
    }

    /**
     * Retrieves the next element in the database.
     *
     * @param elm The current element in the database.
     * @return The next element in the database, or NULL if there is no next element.
     */
    ElmOfDB* getNextRule(ElmOfDB* elm){
        if(elm!=NULL){
            return elm->next;
        }
        return NULL;
    }

    /**
     * Retrieves the rule associated with the given element of the database.
     * 
     * @param elm The element of the database.
     * @return The rule associated with the element, or NULL if the element is NULL.
     */
    Rule getRule(ElmOfDB* elm){
        if(elm!=NULL){
            return elm->rule;
        }
        return NULL;
    }