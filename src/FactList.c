#include "../include/FactList.h"
#include "stdlib.h"

/**
 * Function to test if a Property is empty.
 *
 * @param facts A pointer to the FactList which contain the pointer to the Empty test (provided by the user).
 * @param prop A pointer to the Property to be tested.
 * @return True if the Property is empty, False otherwise.
 */
Boolean isEmptyProperty(FactList facts, void* prop){
    if (!isUndefinedFactList(facts) && !isUndefinedProperty(prop)){
        return facts->isEmpty(prop);
    }
    return True;
}

/**
 * Function to test if a FactList is Undefined.
 *
 * @param list A pointer to the FactList to be tested.
 * @return True if the Undefined is empty (NULL), False otherwise.
 */
Boolean isUndefinedFactList(FactList list){
    if (list == NULL){
        return True;
    }
    return False;
}

/**
 * Function to test if a FactList is empty.
 *
 * @param list A pointer to the FactList to be tested.
 * @return True if the FactList is empty, False otherwise.
 */
Boolean isEmptyFactList(FactList list){
    if(list != NULL){
        return list->head == NULL;
    }
    return True;
}

/**
 * Function to create an empty FactList.
 * 
 * @param cmpValue A function pointer to the comparison function used to compare values in the FactList.
 * @return A pointer to the newly created FactList, or NULL if cmpValue is NULL.
 */
FactList createFactList(Boolean (*cmpValue)(void*, void*), Boolean (*isEmpty)(void *), void (*freeValue)(void*)) {
    if(cmpValue!=NULL && isEmpty!=NULL && freeValue!=NULL){
        FactList new = (FactList)malloc(sizeof(PreFactList));
        new->head=NULL;
        new->last_id=-1;
        new->cmpValue = cmpValue;
        new->freeValue = freeValue;
        new->isEmpty = isEmpty;
        return new;
    }else{
        return NULL;
    }
}

/**
 * Creates a new element of a fact list.
 * 
 * @return The newly created element.
 */
ElmOfFact* createElmOfFact() {
    ElmOfFact* new = malloc(sizeof(ElmOfFact));
    new->fact = NULL;
    new->next = NULL;
    new->id = -1;
    return new;
}

/**
 * Checks if a given fact is already present in a FactList by compare its value with the values of the facts in the FactList.
 * 
 * @param list The FactList to search in.
 * @param fact The fact to check for.
 * @return True if the fact is already in the FactList, False otherwise.
 */
Boolean isAlreadyInFactList(FactList list, void* fact){
    if(isEmptyFactList(list) || isUndefinedProperty(fact)){return False;}
    if(list->cmpValue(list->head->fact,fact)){return True;}
    else {
        PreFactList next = *list;
        next.head=next.head->next;
        return isAlreadyInFactList(&next,fact);
    }
}

/**
 * Checks if a given fact is present in a FactList by memory comparison.
 *
 * @param list The FactList to search in.
 * @param fact The fact to search for.
 * @return True if the fact is present in the list, False otherwise.
 */
Boolean isPresentInFactList(FactList list, void* fact){
    if(isEmptyFactList(list) || isUndefinedProperty(fact)){return False;}
    if(list->head->fact==fact){return True;}
    else{
        PreFactList new = *list;
        new.head = new.head->next;
        return isPresentInFactList(&new,fact);
    }
}

/**
 * Function to add a fact (Property) to the tail of a FactList.
 *
 * @param list The FactList to add the fact to.
 * @param fact The fact (Property) to be added.
 * @return The updated FactList with the fact added or not.
 */
FactList addFact(FactList list, void* fact){
    if(!isUndefinedFactList(list) && !isEmptyProperty(list,fact) && !isAlreadyInFactList(list, fact)) {
        ElmOfFact* newl = createElmOfFact();
        newl->fact=fact;
        newl->next=list->head;
        newl->id = list->last_id+1;
        list->head=newl;
        list->last_id+=1;
    }
    return list;
}

/**
 * Function to remove a fact from a FactList.
 *
 * @param list The FactList to remove the fact from.
 * @param fact The fact to be removed.
 * @return The updated FactList with the fact removed or not.
 */
FactList removeAFact(FactList list, void* fact){
    if(!isEmptyFactList(list) && !isUndefinedProperty(fact)){
        ElmOfFact* point = list->head;
        if(point->fact==fact) {
            list->head = point->next;
            free(point);
        }else{
            ElmOfFact* prev = point;
            point = point->next;
            while(point != NULL){
                if(point->fact==fact){
                    prev->next = point->next;
                    free(point);
                    return list;
                }
                prev = point;
                point = point->next;
            }
        }
    }
    return list;
}

/**
 * Function to remove a fact from a FactList and free the memory.
 *
 * @param list The FactList to remove the fact from.
 * @param fact The fact to be removed.
 * @return The updated FactList with the fact removed or not.
 */
FactList removeAFactAndFree(FactList list, void* fact) {
    if (!isEmptyFactList(list) && !isUndefinedProperty(fact)) {
        ElmOfFact *point = list->head;
        if (point->fact == fact) {
            list->head = point->next;
            list->freeValue(point->fact);
            free(point);
        } else {
            ElmOfFact *prev = point;
            point = point->next;
            while (point != NULL) {
                if (point->fact == fact) {
                    prev->next = point->next;
                    list->freeValue(point->fact);
                    free(point);
                    return list;
                }
                prev = point;
                point = point->next;
            }
        }
    }
    return list;
}
/**
 * Function to remove a fact from a FactList by its ID.
 *
 * @param list The FactList to remove the fact from.
 * @param id The ID of the fact to be removed.
 * @return The updated FactList with the fact removed or not.
 */
FactList removeAFactById(FactList list, long id){
    if(!isUndefinedFactList(list) && id <= list->last_id && id >= 0){
        ElmOfFact* point = list->head;
        if(point->id==id){
            list->head = point->next;
            free(point);
        }else{
            ElmOfFact* prev = point;
            point = point->next;
            while(point != NULL){
                if(point->id==id){
                    prev->next = point->next;
                    free(point);
                    return list;
                }
                prev = point;
                point = point->next;
            }
        }
    }
    return list;
}

/**
 * Function to remove a fact from a FactList by its ID and free the memory.
 *
 * @param list The FactList to remove the fact from.
 * @param id The ID of the fact to be removed.
 * @return The updated FactList with the fact removed or not.
 */
FactList removeAFactByIdAndFree(FactList list, long id) {
    if (!isUndefinedFactList(list) && id <= list->last_id && id >= 0) {
        ElmOfFact *point = list->head;
        if (point->id == id) {
            list->head = point->next;
            list->freeValue(point->fact);
            free(point);
        } else {
            ElmOfFact *prev = point;
            point = point->next;
            while (point != NULL) {
                if (point->id == id) {
                    prev->next = point->next;
                    list->freeValue(point->fact);
                    free(point);
                    return list;
                }
                prev = point;
                point = point->next;
            }
        }
    }
    return list;
}

/**
 * Function to remove all elements from a FactList and free the memory.
 * 
 * @param list The FactList to be modified.
 * @return The modified FactList with all elements removed.
 */
FactList removeAllFactsAndFree(FactList list){
    if(!isEmptyFactList(list)){
        ElmOfFact* point = list->head;
        while (point != NULL){
            list->head = point;
            point = point->next;
            if (list->head != NULL && list->head->fact != NULL){
                list->freeValue(list->head->fact);
            }
            free(list->head);
        }
        list->head=NULL;
    }
    list->last_id=-1;
    return list;
}

FactList removeAllFacts(FactList list){
    if (!isEmptyFactList(list)){
        ElmOfFact* point = list->head;
        while (point != NULL){
            list->head = point;
            point = point->next;
            free(list->head);
        }
        list->head=NULL;
    }
    list->last_id=-1;
    return list;
}

/**
 * Retrieves a fact from the given fact list based on its ID.
 *
 * @param list The fact list to search in.
 * @param id The ID of the fact to retrieve.
 * @return A pointer to the fact with the specified ID, or NULL if not found.
 */
void* getFactById(FactList list, long id){
    if(!isEmptyFactList(list) && id <= list->last_id && id >= 0){
        ElmOfFact* point = list->head;
        while (point != NULL){
            if(point->id==id){
                return point->fact;
            }
            point=point->next;
        }
    }
    return NULL;
}

/**
 * Retrieves a fact from the given fact list based on its value.
 *
 * @param list The fact list to search in.
 * @param fact The value of the fact to retrieve.
 * @return A pointer to the fact with the specified value, or NULL if not found.
 */
ElmOfFact* getHeadOfFactList(FactList list){
    if(!isUndefinedFactList(list)){
        return list->head;
    }
    return NULL;
}

/**
 * Retrieves a fact from the given fact list based on its value.
 *
 * @param list The fact list to search in.
 * @param fact The value of the fact to retrieve.
 * @return A pointer to the fact with the specified value, or NULL if not found.
 */
ElmOfFact* nextOfFactList(ElmOfFact* elm){
    if(!isUndefined(elm)){
        return elm->next;
    }
    return NULL;
}

/**
 * Retrieves a fact from the given fact list based on its value.
 *
 * @param list The fact list to search in.
 * @param fact The value of the fact to retrieve.
 * @return A pointer to the fact with the specified value, or NULL if not found.
 */
long getIdOfFact(ElmOfFact* elm){
    if(!isUndefined(elm)){
        return elm->id;
    }
    return -1;
}

/**
 * Retrieves a fact from the given fact list based on its value.
 *
 * @param list The fact list to search in.
 * @param fact The value of the fact to retrieve.
 * @return A pointer to the fact with the specified value, or NULL if not found.
 */
void* getFact(ElmOfFact* elm){
    if(!isUndefined(elm)){
        return elm->fact;
    }
    return NULL;
}

/**
* Frees the memory occupied by a FactList.
*
* @param list The FactList to be freed.
* @return NULL.
*/
FactList freeFactList(FactList list){
    if(!isUndefinedFactList(list)){
        removeAllFactsAndFree(list);
        free(list);
    }
    return NULL;
}

