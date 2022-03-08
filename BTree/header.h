//
// Created by baoquanlong on 2022/2/27.
//

#ifndef BTREE_HEADER_H
#define BTREE_HEADER_H
#include <cstdio>
#include <malloc.h>
#define MaxSize 20
typedef char ElemType;
typedef struct BTNode{
    ElemType data;
    BTNode * lChild;
    BTNode * rChild;
}BINode;


//Queue
typedef struct {
    BTNode* data[MaxSize];
    int front;
    int rear;           // queue's front and rear
}Queue;

//HuffmanTree
typedef struct {
    char data;
    double weight;
    int parent;
    int lChild;
    int rChild;
}HTNode;



void InitQu(Queue *&qu);
void EnQueue(Queue *&qu, BTNode* b);
BTNode* DeQueue(Queue *&qu);


#endif //BTREE_HEADER_H
