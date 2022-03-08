//
// Created by baoquanlong on 2022/2/27.
//

#ifndef CHILDTREE_HEADER_H
#define CHILDTREE_HEADER_H
#include <cstdio>
#define MaxSons 3
typedef char ElemType;
typedef struct node{
    ElemType data;
    struct node * sons[MaxSons];
}TSonNode;

int getHeight(TSonNode *T);


#endif //CHILDTREE_HEADER_H
