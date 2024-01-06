#include "../include/DB.h"
#include "stdlib.h"

/**
 * Function to test if a DB is undefined.
 *
 * @param db the DB to be tested.
 * @return True if the DB is undefined (NULL), False otherwise.
 */
Boolean isUndefinedDB(DB db){
    return db==NULL;
}

/**
 * Function to test if a DB is empty.
 *
 * @param db the DB to be tested.
 * @return True if the DB is empty, False otherwise.
 */
Boolean isDBEmpty(DB db){
    if(!isUndefinedDB(db)){
        return db->head==NULL;
    }
    return True;
}

/**
 * Function to test if a Rule is addable.
 *
 * @param rule the Rule to be tested.
 * @return True if the Rule is addable, False otherwise.
 */
Boolean isRuleAddable(Rule rule){
    return !isRuleEmpty(rule) && !isUndefinedFactList(rule->facts);
}

/**
 * Function to test if a Rule is present in a DB with a comparaison on memory.
 *
 * @param rule the Rule to be tested.
 * @return True if the Rule is present, False otherwise.
 */
Boolean isPresentInDB(DB db, Rule rule){
    if(!isUndefinedRule(rule) && !isDBEmpty(db)){
        ElmOfDB* point = db->head;
        while (point!=NULL){
            if(point->rule==rule){
                return True;
            }
            point=point->next;
        }
    }
    return False;
}

/**
 * Function to test if a Rule is present in a DB with a comparaison on the values of the rules. Not recommended because it's not efficient. Use isPresentInDB instead.
 *
 * @param rule the Rule to be tested.
 * @return True if the Rule is present, False otherwise.
 */
Boolean isAlreadyInDB(DB db, Rule rule){
    if(!isUndefinedRule(rule) && !isDBEmpty(db)){
        ElmOfDB* point = db->head;
        while (point!=NULL){
            if(isEqualsRule(point->rule,rule)){
                return True;
            }
            point=point->next;
        }
    }
    return False;
}

/**
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
    if(!isEmptyFactList(facts)){
        DB new = (DB)malloc(sizeof(PreDB));
        new->tail=NULL;
        new->head=NULL;
        new->facts = facts;
        new->last_id=-1;
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
    if(!isUndefinedDB(db) && isRuleAddable(rule) && rule->facts->head == db->facts->head && !isPresentInDB(db,rule)){
        ElmOfDB* newl = (ElmOfDB*)malloc(sizeof (ElmOfDB));
        newl->rule=rule;
        newl->next=NULL;
        newl->id=db->last_id+1;
        if(db->head == NULL){
            db->head = newl;
            db->tail = newl;
        }else{
            db->tail->next=newl;
            db->tail=newl;
        }
        db->last_id++;
    }
    return db;
}

/**
* Function to add a Rule to a DB with a comparaison on the values of the rules. Not recommended because it's not efficient. Use addRuleToDB instead.
*
* @param db The DB to add the Rule to.
* @param rule The Rule to be added.
* @return The updated DB with the Rule added or not.
*/
DB addRuleToDB_Strict(DB db, Rule rule){
    if(!isUndefinedDB(db) && isRuleAddable(rule) && rule->facts->head == db->facts->head && !isAlreadyInDB(db,rule)){
        ElmOfDB* newl = (ElmOfDB*)malloc(sizeof (ElmOfDB));
        newl->rule=rule;
        newl->next=NULL;
        newl->id=db->last_id+1;
        if(db->head == NULL){
            db->head = newl;
            db->tail = newl;
        }else{
            db->tail->next=newl;
            db->tail=newl;
        }
        db->last_id++;
    }
    return db;
}

/**
 * Function to remove a Rule from a DB.
 *
 * @param db is the DB to remove the Rule from.
 * @param rule is the Rule to be removed.
 * @return the updated DB with the Rule removed or not.
 */
DB removeARule(DB db,Rule rule){
    if(!isDBEmpty(db) && !isUndefinedRule(rule)){
        ElmOfDB* point = db->head;
        ElmOfDB* prev = NULL;
        while (point!=NULL){
            if(point->rule==rule){
                if(prev==NULL){

                    db->head=point->next;
                    if(db->head==NULL){
                        db->tail=NULL;
                    }
                }else{
                    prev->next=point->next;
                    if(point->next==NULL){
                        db->tail=prev;
                    }
                }
                free(point);
                return db;
            }
            prev=point;
            point=point->next;
        }
    }
    return db;
}

/**
 * Function to remove a Rule from a DB and free the memory allocated for the Rule.
 *
 * @param db is the DB to remove the Rule from.
 * @param rule is the Rule to be removed.
 * @return the updated DB with the Rule removed or not.
 */
DB removeARuleAndFree(DB db, Rule rule){
    if(!isDBEmpty(db) && !isUndefinedRule(rule)){
        ElmOfDB* point = db->head;
        ElmOfDB* prev = NULL;
        while (point!=NULL){
            if(point->rule==rule){
                if(prev==NULL){

                    db->head=point->next;
                    if(db->head==NULL){
                        db->tail=NULL;
                    }
                }else{
                    prev->next=point->next;
                    if(point->next==NULL){
                        db->tail=prev;
                    }
                }
                freeRule(point->rule);
                free(point);
                return db;
            }
            prev=point;
            point=point->next;
        }
    }
    return db;
}

/**
 * Function to remove a Rule from a DB by its ID.
 *
 * @param db is the DB to remove the Rule from.
 * @param id is the ID of the Rule to be removed.
 * @return the updated DB with the Rule removed or not.
 */
DB removeARuleByIdAndFree(DB db, long id){
    if(!isDBEmpty(db) && id >= 0 && id <= db->last_id){
        ElmOfDB* point = db->head;
        ElmOfDB* prev = NULL;
        while (point!=NULL){
            if(point->id==id){
                if(prev==NULL){
                    db->head=point->next;
                    if(db->head==NULL){
                        db->tail=NULL;
                    }
                }else{
                    prev->next=point->next;
                    if(point->next==NULL){
                        db->tail=prev;
                    }
                }
                freeRule(point->rule);
                free(point);
                return db;
            }
            prev=point;
            point=point->next;
        }
    }
    return db;
}

/**
 * Function to remove a Rule from a DB by its ID.
 *
 * @param db is the DB to remove the Rule from.
 * @param id is the ID of the Rule to be removed.
 * @return the updated DB with the Rule removed or not.
 */
DB removeARuleById(DB db, long id){
    if(!isDBEmpty(db) && id >= 0 && id <= db->last_id){
        ElmOfDB* point = db->head;
        ElmOfDB* prev = NULL;
        while (point!=NULL){
            if(point->id==id){
                if(prev==NULL){
                    db->head=point->next;
                    if(db->head==NULL){
                        db->tail=NULL;
                    }
                }else{
                    prev->next=point->next;
                    if(point->next==NULL){
                        db->tail=prev;
                    }
                }
                free(point);
                return db;
            }
            prev=point;
            point=point->next;
        }
    }
    return db;
}

/**
 * Function to remove all the Rules from a DB.
 *
 * @param db is the DB to remove the Rules from.
 * @return the updated DB with the Rules removed or not.
 */
DB removeAllRules(DB db){
    if(!isDBEmpty(db)){
        ElmOfDB* point = db->head;
        while (point!=NULL){
            ElmOfDB* temp = point;
            point=point->next;
            free(temp);
        }
        db->head=NULL;
        db->tail=NULL;
        db->last_id = -1;
    }
    return db;
}

/**
 * Function to remove all the Rules from a DB and free the memory allocated for the Rules.
 *
 * @param db is the DB to remove the Rules from.
 * @return the updated DB with the Rules removed or not.
 */
DB removeAllRulesAndFree(DB db){
    if(db!=NULL && db->head!=NULL){
        ElmOfDB* point = db->head;
        while (point!=NULL){
            ElmOfDB* temp = point;
            point=point->next;
            freeRule(temp->rule);
            free(temp);
        }
        db->head=NULL;
        db->tail=NULL;
        db->last_id = -1;
    }
    return db;
}

/**
 * Function to remove all the Rules from a DB and free the memory allocated for the Rules and the DB.
 *
 * @param db is the DB to remove the Rules from.
 * @return the updated DB with the Rules removed or not.
 */
Rule getRuleByIDd(DB db, long id){
    if(!isDBEmpty(db) && id >= 0 && id <= db->last_id){
        ElmOfDB* point = db->head;
        while (point!=NULL){
            if(point->id==id){
                return point->rule;
            }
            point=point->next;
        }
    }
    return NULL;
}

/**
* Function to get the first Rule of a DB.
*
* @param db The DB to retrieve the first Rule from.
* @return The first Rule of the DB, or NULL if the DB is empty.
*/
ElmOfDB* getHeadRule(DB db) {
    if (!isDBEmpty(db)) {
        return db->head;
    } else {
        return NULL;
    }
}

/**
* Retrieves the list of facts from the given database.
*
* @param db The database to retrieve the facts from.
* @return The list of facts in the database, or NULL if the database is empty.
*/
FactList getFactListOfDB(DB db){
    if(!isUndefinedDB(db)){
        return db->facts;
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
 * Retrieves the ID of the given element of the database.
 *
 * @param elm is the element of the database.
 * @return the ID of the element, or -1 if the element is NULL.
 */
long getIdOfRule(ElmOfDB* elm){
     if(elm!=NULL){
         return elm->id;
     }
     return -1;
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
     if(isUndefinedDB(db) || isEmptyFactList(db->facts)){
         return NULL;
     }
     DB new_db = createEmptyDB(db->facts);
     ElmOfDB* point = db->head;
     while (point!=NULL){
         Rule new_rule = createEmptyRule(db->facts);
         new_rule->conclusion=point->rule->conclusion;
         ElmOfPremise* premise = point->rule->premise.head;
         while (premise!=NULL){
             new_rule = addFactInPremise(new_rule, premise->premise);
             premise=premise->next;
         }
         new_db = addRuleToDB(new_db,new_rule);
         point=point->next;
     }
     return new_db;
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
        if(!isUndefinedDB(db)){
            if(db->head!=NULL){
                ElmOfDB* point = db->head;
                while (point!=NULL){
                    ElmOfDB* temp = point;
                    freeRule(temp->rule);
                    point=point->next;
                    free(temp);
                }
            }
            FactList rtn = db->facts;
            free(db);
            return rtn;
        }
        free(db);
        return NULL;
    }