//
// Created by baoquanlong on 2022/2/27.
//
#include "test.h"

void InitParentTree(PTree T){
    int i = 0;
    while (i<MaxSize){
        (T+i)->data = '\0';
        (T+i)->parent = -1;
        i++;
    }
}

void InstructTree(PTree T) {
    int i = 0;
    for (i ; i<7; i++){
        printf("Please enter the %dth node's data and parent\n",i+1);
        scanf("%s %d", &(T[i].data),&(T[i].parent));
    }

}

void DisplayTree(PTree T){
    for (int i = 0 ;i< 7 ; i++) {
        printf("%c %d \n", T[i].data,T[i].parent);
    }
}
