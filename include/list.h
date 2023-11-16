//
// Created by matth on 16/11/2023.
//

#ifndef LO21_LIST_H
#define LO21_LIST_H

typedef struct elemRules{
    char *value;
    struct elem *next;
} ElemRules;

typedef ElemRules *RulesList;

typedef struct elemListRules{
    RulesList value;
    char *conclude;
    struct elemListRules *next;
} ElemRulesList;

typedef ElemRules *ListOfRules;

#endif //LO21_LIST_H
