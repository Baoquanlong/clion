//
// Created by baoquanlong on 2022/2/27.
//

#ifndef TREE_TEST_H
#define TREE_TEST_H
#define MaxSize 20
#include "cstdio"
typedef char ElemType;
typedef struct {
    ElemType data;
    int parent;
}PTree[MaxSize];



void InitParentTree(PTree T);

void InstructTree(PTree T);

void DisplayTree(PTree T);
#endif //TREE_TEST_H
