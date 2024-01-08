#include "../include/Rules.h"
#include "stdlib.h"

/**
 * Checks if a given rule is empty.
 *
 * @param rule The rule to check.
 * @return True if the rule is empty, False otherwise.
 */
Boolean isRuleEmpty(Rule rule) {
    if (rule != NULL) {
        if (rule->conclusion != NULL && rule->premise.head != NULL) {
            return False;
        }
    }
    return True;
}

/**
 * Checks if a given rule is undefined.
 *
 * @param rule The rule to check.
 * @return True if the rule is undefined, False otherwise.
 */
Boolean isUndefinedRule(Rule rule) {
    return rule == NULL;
}

/**
 * Retrieves the premise from the given ElmOfPremise structure.
 *
 * @param elm The ElmOfPremise structure to retrieve the premise from.
 * @return The premise stored in the ElmOfPremise structure.
 *
 * Note : Usage of this function is not recommended due to the operation cost it performs.
 */
Boolean isEqualsRule(Rule rule1, Rule rule2){
    if(!isUndefinedRule(rule1) && !isUndefinedRule(rule2) && rule1->facts->head == rule2->facts->head && rule1->facts->cmpValue(rule1->conclusion,rule2->conclusion)){
        ElmOfPremise* point1 = rule1->premise.head;
        while (point1 != NULL){
            if(!factInPremise(rule2, point1->premise)){
                return False;
            }
            point1=point1->next;
        }
        ElmOfPremise *point2 = rule2->premise.head;
        while (point2 != NULL){
            if(!factInPremise(rule1, point2->premise)){
                return False;
            }
            point2=point2->next;
        }
        return True;
    }
    return False;
}

/**
 * Function to create an empty Rule with all pointers initialized to NULL and the FactList set to the given FactList
 * 
 * @param facts The FactList to be associated with the Rule.
 * @return The newly created Rule.
 */
Rule createEmptyRule(FactList facts){
    if(isUndefinedFactList(facts)){return NULL;}
    Rule newl = (Rule)malloc(sizeof (PreRule));
    newl->conclusion=NULL;
    newl->premise.tail=NULL;
    newl->premise.head=NULL;
    newl->premise.last_id=-1;
    newl->facts = facts;
    return newl;
}

/**
 * Checks if the premise of a rule is empty.
 *
 * @param rule The rule to check.
 * @return True if the premise is empty, False otherwise.
 */
Boolean isPremiseEmpty(Rule rule){
    if(!isUndefinedRule(rule) && rule->premise.head==NULL){
        return True;
    } else{
        return False;
    }
}

/**
 * Checks if the conclusion of a rule is empty.
 *
 * @param rule The rule to check.
 * @return True if the conclusion is empty, False otherwise.
 */
Boolean isUndefinedConclusion(Rule rule) {
    if (!isUndefinedRule(rule) && rule->conclusion == NULL) {
        return True;
    } else {
        return False;
    }
}

/**
 * Function to check if a Property is in the premise field of a Rule.
 *
 * @param rule The Rule to check.
 * @param prop The Property to search for in the premise field.
 * @return True if the Property is found in the premise field, False otherwise.
 */
Boolean factInPremise(Rule rule, void* prop){
    if(isUndefinedRule(rule) || rule->premise.head == NULL || isUndefinedProperty(prop)){return False;}
    if(rule->premise.head->premise==prop){
        return True;
    }
    PreRule new = *rule;
    new.premise.head = new.premise.head->next;
    return factInPremise(&new, prop);
}

/**
 * Function to add a Property in the premise field to a Rule.
 * 
 * @param rule The Rule to which the premise will be added.
 * @param premise The premise to be added.
 * @return The updated Rule with the premise added or not.
 */
Rule addFactInPremise(Rule rule, void* premise){
    if(!isUndefinedProperty(premise) && !isUndefinedRule(rule) && isPresentInFactList(rule->facts, premise) && !factInPremise(rule, premise) && rule->conclusion != premise){
        ElmOfPremise* new = malloc(sizeof(ElmOfPremise));
        new->premise=premise;
        new->id=rule->premise.last_id+1;
        new->next=NULL;
        if(rule->premise.head==NULL){
            rule->premise.head=new;
            rule->premise.tail=new;
        }else{
            rule->premise.tail->next = new;
            rule->premise.tail=new;
        }
        rule->premise.last_id++;
    }
    return rule;
}

/**
 * Removes a Property from the premise field of a Rule.
 *
 * @param rule The Rule from which to remove the Property.
 * @param premise The Property to be removed.
 * @return The updated Rule after removing the Property.
 */
Rule removeFromPremise(Rule rule, void* premise){
    if(!isUndefinedRule(rule) && !isUndefinedProperty(premise)){
        if(rule->premise.head != NULL) {
            ElmOfPremise* point = rule->premise.head;
            if(point->premise == premise){
                rule->premise.head = point->next;
                free(point);
            }else{
                while (point->next != NULL && point->next->premise != premise){
                    point = point->next;
                }
                if(point->next != NULL) {
                    if(point->next == rule->premise.tail) {
                        rule->premise.tail = point;
                    }
                    ElmOfPremise *temp = point->next;
                    point->next = point->next->next;
                    free(temp);
                }
            }
        }
    }
    return rule;
}

/**
 * Removes a premise from a rule by its ID.
 *
 * @param rule The rule to remove the premise from.
 * @param id The ID of the premise to remove.
 * @return The updated rule.
 */
Rule removeFromPremiseById(Rule rule, long id) {
    if (!isUndefinedRule(rule) && id >= 0 && id <= rule->premise.last_id) {
        if (rule->premise.head != NULL) {
            ElmOfPremise *point = rule->premise.head;
            if (point->id == id) {
                rule->premise.head = point->next;
                free(point);
            } else {
                while (point->next != NULL && point->next->id != id) {
                    point = point->next;
                }
                if (point->next != NULL) {
                    if(point->next == rule->premise.tail) {
                        rule->premise.tail = point;
                    }
                    ElmOfPremise *temp = point->next;
                    point->next = point->next->next;
                    free(temp);
                }
            }
        }
    }
    return rule;
}

/**
 * Sets or updates the conclusion field of a rule.
 *
 * @param rule The rule to modify.
 * @param conclusion The new conclusion value.
 * @return The modified rule.
 */
Rule setConclusion(Rule rule, void* conclusion){
    if(!isUndefinedRule(rule) && isPresentInFactList(rule->facts, conclusion) && !factInPremise(rule, conclusion)){
        rule->conclusion=conclusion;
    }
    return rule;
}

/**
 * Removes the conclusion field of a rule and set to NULL.
 *
 * @param rule The rule to modify.
 * @return The modified rule.
 */
Rule removeConclusion(Rule rule){
    if(!isUndefinedRule(rule)){
        rule->conclusion = NULL;
    }
    return rule;
}

/**
 * Retrieves the premise field of a rule.
 *
 * @param rule The rule to retrieve the premise from.
 * @return The premise field of the rule, or NULL if the rule is NULL.
 */
void* getPremise(ElmOfPremise* elm){
    if(isUndefined(elm)){return NULL;}
    else{return elm->premise;}
}

/**
 * Retrieves the premise field of a rule by its ID.
 *
 * @param rule The rule to retrieve the premise from.
 * @param id The ID of the premise to retrieve.
 * @return The premise field of the rule, or NULL if the rule is NULL or the premise is not found.
 */
void* getPremiseById(Rule rule, long id) {
    if (!isRuleEmpty(rule) && id >= 0 && id <= rule->premise.last_id) {
        ElmOfPremise *point = rule->premise.head;
        while (point != NULL) {
            if (point->id == id) {
                return point->premise;
            }
        }
    }
    return NULL;
}

/**
 * Returns the first premise element of a rule.
 *
 * @param rule The rule to retrieve the premise from.
 * @return The head element of the premise, or NULL if the rule is NULL.
 */
ElmOfPremise* getHeadOfPremise(Rule rule){
    if(isUndefinedRule(rule)){
        return NULL;
    }else{
        return rule->premise.head;
    }
}

/**
 * Returns the next element of a given premise element.
 *
 * @param elm The premise element.
 * @return The next element of the premise element, or NULL if the given element is NULL.
 */
ElmOfPremise* nextOfPremise(ElmOfPremise* elm){
    if(isUndefinedProperty(elm)){return NULL;}
    else{return elm->next;}
}

/**
 * Retrieves the ID of a premise element.
 *
 * @param elm The premise element.
 * @return The ID of the premise element, or -1 if the premise element is NULL.
 */
long getIdOfPremise(ElmOfPremise* elm) {
    if (isUndefinedProperty(elm)) { return -1; }
    else { return elm->id; }
}

/**
 * Retrieves the conclusion field of a given rule.
 *
 * @param rule The rule to retrieve the conclusion from.
 * @return The conclusion field of the rule, or NULL if the rule is NULL.
 */
void* getConclusion(Rule rule){
    if(isUndefinedRule(rule)){return NULL;}
    else{
        return rule->conclusion;
    }
}

/**
 * Retrieves the fact list associated with a given rule.
 *
 * @param rule The rule for which to retrieve the fact list.
 * @return The fact list associated with the rule, or NULL if the rule is NULL.
 */
FactList getFactListOfRule(Rule rule){
    if(isUndefinedRule(rule)){return NULL;}
    else{return rule->facts;}
}

/**
 * Frees the memory allocated for a Rule and its associated premise.
 *
 * @param rule The Rule to be freed.
 * @return The FactList associated with the Rule, or NULL if the Rule is NULL or has no premise.
 */
FactList freeRule(Rule rule){
    if(!isUndefinedRule(rule)){
        if(rule->premise.head!=NULL){
            ElmOfPremise* point = rule->premise.head;
            while (point!=NULL){
                ElmOfPremise* temp = point;
                point=point->next;
                free(temp);
            }
        }
        FactList rtn = rule->facts;
        free(rule);
        return rtn;
    }
    return NULL;
}