#include "define.h"

typedef struct {
    char* name;
    char* desc;
}Property;


Bool isEmptyProperty(Property* prop);
Bool cmpProperty(Property* p1, Property* p2);
void printProperties(Property* p);
Property* affectField(Property fact);
