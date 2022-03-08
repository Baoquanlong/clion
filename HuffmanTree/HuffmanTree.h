//
// Created by baoquanlong on 2022/3/5.
//

#ifndef HUFFMANTREE_HUFFMANTREE_H
#define HUFFMANTREE_HUFFMANTREE_H
#include "stdio.h"
#define MaxSize 20

typedef struct {
    char data;          //节点值
    double weight;      //权重
    int parent;
    int lchild;
    int rchild;
}HTNode;



typedef struct {
    char cd[MaxSize];
    int start;             //表示cd[start...no]部分为huffman code
}HCode;

void CreateHTree(HTNode ht[],int n0) ;



void CreateHFCode(HTNode ht[], HCode hcd[], int n0);

#endif //HUFFMANTREE_HUFFMANTREE_H
