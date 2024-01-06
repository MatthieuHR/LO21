#include "../include/ExpertSys.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char* name;
    char* description;
} my_struct;

void* my_struct_new() {
    my_struct* self = malloc(sizeof(my_struct));
    self->name = NULL;
    self->description = NULL;
    return self;
}

void my_struct_delete(void* self) {
    free(((my_struct*)self)->name);
    free(((my_struct*)self)->description);
    free(self);
}

void my_struct_set_name(void* self, char* name) {
    ((my_struct*)self)->name = strdup(name);
}

void my_struct_set_description(void* self, char* description) {
    ((my_struct*)self)->description = strdup(description);
}

char* my_struct_get_name(void* self) {
    return ((my_struct*)self)->name;
}

char* my_struct_get_description(void* self) {
    return ((my_struct*)self)->description;
}

void my_struct_print(void* self) {
    if (self == NULL) {
        printf("NULL\n");
        return;
    }
    printf("name: %s\n", ((my_struct*)self)->name);
    printf("description: %s\n", ((my_struct*)self)->description);
}

void printFactList(FactList fact_list) {
    printf("Fact list:\n");
    ElmOfFact * current = getHeadOfFactList(fact_list);
    while (current != NULL) {
        printf("Fact id:%ld :\n", getIdOfFact(current));
        my_struct_print(current->fact);
        current = nextOfFactList(current);
    }

}

void printPremise(ElmOfPremise * premise) {
    printf("Premise:\n");
    printf("___\n");
    while (premise != NULL) {
        printf("Id:%ld :\n", getIdOfPremise(premise));
        my_struct_print(premise->premise);
        premise = nextOfPremise(premise);
    }
    printf("___\n");
}

void printRule(Rule rule) {
    printf("Rule n:\n");
    printf("___\n");
    ElmOfPremise * current = getHeadOfPremise(rule);
    printPremise(current);
    printf("Conclusion:\n");
    my_struct_print(getConclusion(rule));
}


void printDB(DB db) {
    printf("DB:\n");
    printf("--------------------\n");
    ElmOfDB * current = getHeadRule(db);
    while (current != NULL) {
        printf("Id of the rule: %ld\n", getIdOfRule(current));
        printRule(getRule(current));
        current = getNextRule(current);
        printf("--------------------\n");
    }
}

Bool cmpMyStruct(void* self, void* other) {
    return strcmp(((my_struct*)self)->name, ((my_struct*)other)->name) == 0;
}

int main(){
    Bool (*cmp)(void*, void*) = cmpMyStruct;
    FactList my_fact_list = createFactList(cmp, my_struct_delete);

    my_struct* my_struct1 = my_struct_new();
    my_struct_set_name(my_struct1, "Il est midi");
    my_struct_set_description(my_struct1, "Midi correspond à 12h00");

    my_struct* my_struct2 = my_struct_new();
    my_struct_set_name(my_struct2, "Il fait beau");
    my_struct_set_description(my_struct2, "Il y a suffisamment de soleil pour se promener");

    my_struct* my_struct3 = my_struct_new();
    my_struct_set_name(my_struct3, "Je vais me promener");
    my_struct_set_description(my_struct3, "Sortir de chez soi pour se balader");

    my_struct* my_struct4 = my_struct_new();
    my_struct_set_name(my_struct4, "Je dois rentrer chez moi");
    my_struct_set_description(my_struct4, "Je dois rentrer chez moi avant 13h00");

    my_fact_list = addFact(my_fact_list, my_struct1);
    my_fact_list = addFact(my_fact_list, my_struct2);
    my_fact_list = addFact(my_fact_list, my_struct3);
    my_fact_list = addFact(my_fact_list, my_struct4);

    DB my_db = createEmptyDB(my_fact_list);

    Rule my_rule1 = createEmptyRule(my_fact_list);
    my_rule1 = addPremise(my_rule1, my_struct1);
    my_rule1 = addPremise(my_rule1, my_struct2);
    my_rule1 = setConclusion(my_rule1, my_struct3);

    Rule my_rule2 = createEmptyRule(my_fact_list);
    my_rule2 = addPremise(my_rule2, my_struct3);
    my_rule2 = setConclusion(my_rule2, my_struct4);

    my_db = addRuleToDB(my_db, my_rule1);
    my_db = addRuleToDB(my_db, my_rule2);


    char user_input = '\0';
    char trash = '\0';
    char* user_char = NULL;
    long id;
    my_struct * user_my_struct = NULL;
    Rule user_rule = NULL;
    FactList garbage = createFactList(cmp,my_struct_delete);
    FactList user_fact_list = NULL;
    FactList factToTest = createFactList(cmp,my_struct_delete);
    FactList result = createFactList(cmp,my_struct_delete);
    DB copy = NULL;

    while (user_input != 'q') {
        printf("What do you want to do ?\n");
        printf("1. Print the list of facts\n");
        printf("2. Print the DB\n");
        printf("3. Modified the fact list\n");
        printf("4. Modified a Rule\n");
        printf("5. Modified the DB\n");
        printf("6. Run the expert system\n");
        printf("q. Quit\n");

        printf("Your choice: ");
        scanf(" %c", &user_input);
        printf("\n");

        switch (user_input) {
            case '1':
                printFactList(my_fact_list);
                printf("\nPRESS ANY KEY TO CONTINUE\n");
                scanf(" %c", &trash);
                break;
            case '2':
                printDB(my_db);
                printf("\nPRESS ANY KEY TO CONTINUE\n");
                scanf(" %c", &trash);
                break;
            case '3':
                while (user_input!='5') {
                    printf("What do you want to do ?\n");
                    printf("1. Add a fact\n");
                    printf("2. Remove a fact\n");
                    printf("3. Remove all facts\n");
                    printf("4. Print the fact list\n");
                    printf("5. Quit\n");

                    printf("Your choice: ");
                    scanf(" %c", &user_input);
                    printf("\n");

                    switch (user_input) {
                        case '1':
                            user_my_struct = my_struct_new();
                            user_my_struct->name = malloc(sizeof(char)*100);
                            user_my_struct->description = malloc(sizeof(char)*100);
                            printf("Enter the name of the fact: ");
                            scanf("%s", user_my_struct->name);
                            printf("\n");
                            printf("Enter the description of the fact: ");
                            scanf("%s", user_my_struct->description);
                            printf("\n");
                            my_fact_list = addFact(my_fact_list, user_my_struct);
                            break;
                        case '2':
                            printFactList(my_fact_list);
                            printf("Enter the id of the fact you want to remove: ");
                            scanf("%ld", &id);
                            printf("\n");
                            my_fact_list = removeAFactById(my_fact_list, id);
                            break;
                        case '3':
                            printf("Are you sure you want to remove all facts ? (y/n): ");
                            scanf(" %c", &user_input);
                            printf("\n");
                            if (isEmptyDB(my_db) && user_input == 'y') {
                                my_fact_list = removeAllFacts(my_fact_list);
                                printf("All facts have been removed\n");
                            } else{
                                printf("The DB is not empty, you can't remove all facts\n");
                            }
                            printf("\nPRESS ANY KEY TO CONTINUE\n");
                            scanf(" %c", &trash);
                            printf("\n");
                            break;
                        case '4':
                            printFactList(my_fact_list);
                            break;
                        default:
                            break;
                    }
                }
                break;
            case '4':
                printDB(my_db);
                printf("Enter the id of the rule you want to modify: ");
                scanf("%ld", &id);
                printf("\n");
                user_rule = getRuleByIDd(my_db, id);
                while (user_rule == NULL) {
                    printf("The id you entered is not valid, please enter a valid id: ");
                    scanf("%ld", &id);
                    printf("\n");
                    user_rule = getRuleByIDd(my_db, id);
                }
                while (user_input!='6' && user_rule!=NULL) {
                    printf("What do you want to do ?\n");
                    printf("1. Add a premise\n");
                    printf("2. Remove a premise\n");
                    printf("3. Set the conclusion\n");
                    printf("4. Remove the conclusion\n");
                    printf("5. Print the rule\n");
                    printf("6. Quit\n");

                    printf("Your choice: ");
                    scanf(" %c", &user_input);
                    printf("\n");

                    switch (user_input) {
                        case '1':
                            printFactList(my_fact_list);
                            printf("Enter the id of the fact you want to use as premise: ");
                            scanf("%ld", &id);
                            printf("\n");
                            user_rule = addPremise(user_rule, getFactById(my_fact_list, id));
                            break;
                        case '2':
                            printPremise(getHeadOfPremise(user_rule));
                            printf("Enter the id of the fact you want to remove: ");
                            scanf("%ld", &id);
                            printf("\n");
                            garbage = addFact(garbage, getFactById(my_fact_list, id));
                            user_rule = removeFromPremiseById(user_rule, id);
                            break;
                        case '3':
                            printFactList(my_fact_list);
                            printf("Enter the id of the fact you want to use as conclusion: ");
                            scanf("%ld", &id);
                            printf("\n");
                            user_rule = setConclusion(user_rule, getFactById(my_fact_list, id));
                            break;
                        case '4':
                            user_rule = removeConclusion(user_rule);
                            break;
                        case '5':
                            printRule(user_rule);
                            printf("\nPRESS ANY KEY TO CONTINUE\n");
                            scanf(" %c", &trash);
                            printf("\n");
                            break;
                        default:
                            break;
                    }
                }
                break;
            case '5':
                while (user_input!='5') {
                    printf("What do you want to do ?\n");
                    printf("1. Add a rule\n");
                    printf("2. Remove a rule\n");
                    printf("3. Remove all rules\n");
                    printf("4. Print the DB\n");
                    printf("5. Quit\n");

                    printf("Your choice: ");
                    scanf(" %c", &user_input);
                    printf("\n");

                    switch (user_input) {
                        case '1':
                            printFactList(my_fact_list);
                            printf("Enter the id of the fact you want to use as conclusion: ");
                            scanf("%ld", &id);
                            printf("\n");
                            user_fact_list = getFactById(my_fact_list, id);
                            while (user_fact_list == NULL) {
                                printf("The id you entered is not valid, please enter a valid id: ");
                                scanf("%ld", &id);
                                printf("\n");
                                user_fact_list = getFactById(my_fact_list, id);
                            }
                            user_rule = createEmptyRule(my_fact_list);
                            user_rule = setConclusion(user_rule, getFactById(my_fact_list, id));

                            printFactList(my_fact_list);
                            printf("Enter the id of the fact you want to use as premise (-1 to stop): ");
                            scanf("%ld", &id);
                            printf("\n");
                            while (id != -1) {
                                user_rule = addPremise(user_rule, getFactById(my_fact_list, id));
                                printFactList(my_fact_list);
                                printf("Enter the id of the fact you want to use as premise (-1 to stop): ");
                                scanf("%ld", &id);
                                printf("\n");
                            }
                            if (!isPremiseEmpty(user_rule)) {
                                my_db = addRuleToDB(my_db, user_rule);
                            } else {
                                printf("The rule you entered is not valid\n");
                                freeRule(user_rule);
                            }
                            break;
                        case '2':
                            printDB(my_db);
                            printf("Enter the id of the fact you want to remove: ");
                            scanf("%ld", &id);
                            printf("\n");
                            my_db = removeARuleById(my_db, id);
                            break;
                        case '3':
                            printf("Are you sure you want to remove all rules ? (y/n): ");
                            scanf(" %c", &user_input);
                            printf("\n");
                            if (user_input == 'y') {
                                my_db = removeAllRules(my_db);
                                printf("All rules have been removed\n");
                            } else {
                                printf("The rules have not been removed\n");
                            }
                            printf("\nPRESS ANY KEY TO CONTINUE\n");
                            scanf(" %c", &trash);
                            printf("\n");
                            break;
                        case '4':
                            printDB(my_db);
                            break;
                        default:
                            break;
                    }
                }
                break;
            case '6':
                printFactList(my_fact_list);
                printf("Enter the id of the fact you want to test (-1 to stop): ");
                scanf("%ld", &id);
                printf("\n");
                while (id != -1){
                    factToTest = addFact(factToTest, getFactById(my_fact_list, id));
                    printFactList(my_fact_list);
                    printf("Enter the id of the fact you want to test (-1 to stop): ");
                    scanf("%ld", &id);
                    printf("\n");
                }
                copy = copyOfDB(my_db);
                expertSystem(factToTest,result,my_db);
                printf("The result is:\n");
                printFactList(result);
                freeDB(my_db);
                my_db = copy;
                removeAllFacts(result);
                removeAllFacts(factToTest);
                printf("\nPRESS ANY KEY TO CONTINUE\n");
                scanf(" %c", &trash);
                printf("\n");
                break;
            default:
                break;
        }
    }
    freeDB(my_db);
    freeDB(copy);
    freeFactList(factToTest);
    freeFactList(result);
    freeFactList(my_fact_list);
    freeFactList(garbage);
    return 0;
}