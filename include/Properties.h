#include "define.h"

typedef struct {
    void *value;
}Property;


Bool isEmptyProperty(Property* prop);
Bool isEqual(Property* p1, Property* p2, Bool (*cmpValue)(Property*, Property*));
