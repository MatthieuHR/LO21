#include "../include/FactList.h"
#include "stdlib.h"

/**
 * Function to create an empty FactList.
 * 
 * @param cmpValue A function pointer to the comparison function used to compare values in the FactList.
 * @return A pointer to the newly created FactList, or NULL if cmpValue is NULL.
 */
FactList createFactList(Bool (*cmpValue)(void*, void*)){
    if(cmpValue!=NULL){
        FactList newl = (FactList)malloc(sizeof(PreFactList));
        newl->head=NULL;
        newl->last_id=-1;
        newl->cmpValue = cmpValue;
        return newl;
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
    ElmOfFact* newl = malloc(sizeof(ElmOfFact));
    newl->fact = NULL;
    newl->next = NULL;
    newl->id = -1;
    return newl;
}

/**
 * Checks if a given fact is already present in a FactList by compare its value with the values of the facts in the FactList.
 * 
 * @param list The FactList to search in.
 * @param fact The fact to check for.
 * @return True if the fact is already in the FactList, False otherwise.
 */
Bool isAlreadyInFactList(FactList list, void* fact){
    if(fact==NULL || list->head==NULL){return False;}
    if(list->cmpValue(list->head->fact,fact)){return True;}
    else {
        PreFactList next = *list;
        next.head=next.head->next;
        return isAlreadyInFactList(&next,fact);
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
    if(!isEmptyProperty(fact) && !isAlreadyInFactList(list, fact)) {
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
 * Function to remove all elements from a FactList and free the memory.
 * 
 * @param list The FactList to be modified.
 * @return The modified FactList with all elements removed.
 */
FactList removeAllFacts(FactList list){
    ElmOfFact* point = list->head;
    while (point != NULL){
        list->head = point;
        point = point->next;
        free(list->head->fact);
        free(list->head);
    }
    list->head=NULL;
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
void* getById(FactList list, long id){
    if(list != NULL && id <= list->last_id){
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
 * Checks if a given fact is present in a FactList by memory comparison.
 *
 * @param list The FactList to search in.
 * @param fact The fact to search for.
 * @return True if the fact is present in the list, False otherwise.
 */
Bool isPresentInFactList(FactList list, void* fact){
    if(fact == NULL || list->head == NULL){return False;}
    if(list->head->fact==fact){return True;}
    else{
        PreFactList new = *list;
        new.head = new.head->next;
        return isPresentInFactList(&new,fact);
    }
}

/**
 * Frees the memory occupied by a FactList.
 * 
 * @param list The FactList to be freed.
 * @return NULL.
 */
FactList freeFactList(FactList list){
    if(list != NULL){
        if(list->head != NULL){
            list = removeAllFacts(list);
        }
        free(list);
    }
    return NULL;
}

/**
 * Function to remove a fact from a FactList.
 *
 * @param list The FactList to remove the fact from.
 * @param fact The fact to be removed.
 * @return The updated FactList with the fact removed or not.
 */
 FactList removeAFact(FactList list, void* fact){
     if(list!=NULL && fact != NULL && list->head!=NULL){
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

 ElmOfFact* getHeadOfFactList(FactList list){
     if(list != NULL){
         return list->head;
     }
     return NULL;
 }

 ElmOfFact* nextOfFactList(ElmOfFact* elm){
     if(elm != NULL){
         return elm->next;
     }
     return NULL;
 }

    long getId(ElmOfFact* elm){
        if(elm != NULL){
            return elm->id;
        }
        return -1;
    }

    void* getFact(ElmOfFact* elm){
        if(elm != NULL){
            return elm->fact;
        }
        return NULL;
    }

