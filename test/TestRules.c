#include "../include/Rules.h"
#include "stdio.h"

int main(){
    Rules* r1 = createEmptyRule();
    Properties p1 = {"P1","P1"};
    r1 = addPremise(r1,p1);
    Properties p2 = {"P2","P2"};
    r1 = addPremise(r1, p2);
    p2.name = "CCL";p2.desc="CCL";
    r1= createConclusion(r1,&p2);
    printRule(r1);
    printf("\n");
    if(PropertiesInPremise(r1->premise,p1)==True){
        printf("p1 is in r1\n");
    }
    printf("\n");
    if(PropertiesInPremise(r1->premise,p2)==False){
        printf("p2 isn't in r1\n");
    }
    printf("\n");

    r1= remouvePremise(r1,p2);
    printRule(r1);
    printf("\n");

    p2.name = "P2";
    r1= remouvePremise(r1,p2);
    printRule(r1);
    printf("\n");

    r1= remouvePremise(r1,p1);
    printRule(r1);
    printf("\n");

    if(isPremiseEmpty(r1)==True){
        printf("The premise is empty");
    }
    printf("\n");

    if(getHeadOfPremise(r1) == NULL){
        printf("The premise head didn't exist\n");
    }

    Properties* ccl = getConclusion(r1);
    printProperties(ccl);
}
