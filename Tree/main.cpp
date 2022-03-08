//#define MaxSize 20
//#include "cstdio"
//typedef char ElemType;
//typedef struct {
//    ElemType data;
//    int parent;
//}PTree[MaxSize];
//
//void InitParentTree(PTree T){
//    int i = 0;
//    while (i<MaxSize){
//        (T+i)->data = '\0';
//        (T+i)->parent = -1;
//        i++;
//    }
//}
//
//void InstructTree(PTree T) {
//    int i = 0;
//    for (i ; i<7; i++){
//        printf("Please enter the %dth node's data and parent\n",i+1);
//        scanf("%s %d", &(T[i].data),&(T[i].parent));
//    }
//
//}
//
//void DisplayTree(PTree T){
//    for (int i = 0 ;i< 7 ; i++) {
//        printf("%c %d \n", T[i].data,T[i].parent);
//    }
//}
//
//
#include "test.h"
int main(){
    PTree T;
    InitParentTree(T);
    InstructTree(T);
    DisplayTree(T);
    return 0;


}