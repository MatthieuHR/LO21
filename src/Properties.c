#include "../include/Properties.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

//Function to test if a Property is empty (based on selected criteria)
Bool isEmptyProperty(Property* prop){
    if(prop->name != NULL){
        return False;
    }else{
        return True;
    }
}

//Function to compare 2 Property (based on selected criteria) and return True if they are the same and False otherwise
Bool cmpProperty(Property* p1, Property* p2){
    if(strcmp(p1->name,p2->name)==0){
        return True;
    } else{
        return False;
    }
}

//Methode to display a Property
void printProperties(Property* p){
    if(p!=NULL){
        printf("name:%s desc:%s\n",p->name,p->desc);
    }
}

//Function to transform a Property to a Property pointer
Property* affectField(Property fact){
    if(fact.desc != NULL && fact.name != NULL){
        Property* newl = malloc(sizeof(Property));
        newl->name=fact.name;
        newl->desc=fact.desc;
        return newl;
    }else{
        return NULL;
    }
}
