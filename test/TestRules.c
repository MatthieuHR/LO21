#include "../include/Rules.h"

int main(){
    Rules* r1 = createEmptyRule();
    Properties p1 = {"P1","P1"};
    r1 = addPremise(r1,p1);
    Properties p2 = {"P2","P2"};
    r1 = addPremise(r1, p2);
    r1= createConclusion(r1,&p1);
    printRule(r1);

}
