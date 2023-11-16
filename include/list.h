//
// Created by matth on 16/11/2023.
//

#ifndef LO21_LIST_H
#define LO21_LIST_H

typedef struct elem{
    int value;
    struct elem *next;
    struct elem *prev;
} ElemList;

typedef ElemList *List;

#endif //LO21_LIST_H
