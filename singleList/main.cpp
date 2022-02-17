#include <cstdio>
//#include "unionSet.h"
//#include "sqlist.h"
#include "malloc.h"
#include "LinkNode.h"

int main() {
//    list* L;
//    ElemType set[] = {1,2,3,3,1,4,2};
//    CreateList(L);
//    InitList(L,set);
//    DispList(L);
//    int location;
//    location = LocateElem(L,3);
//    printf("e is in the %dth location\n",location);
////    printf("%d\n",L->length);
////    DestroyList(L);
//    listInsert(L,101,3);
//    DispList(L);
//    ElemType e;
//    e = listDelete(L,3);
//    printf("e is : %d\n",e);
//    DispList(L);

//    int setA[MaxSize] = {1,2,3,4,1,11,1,199};
//    int setB[MaxSize] = {2,2,5,6,7,20,3999,10};
//    int setC[MaxSize] = {0};
//    //求A并B
//    list* LA;
//    list* LB;
//    list* LC;
//    CreateList(LA);
//    CreateList(LB);
//    CreateList(LC);
//    InitList(LA,setA);
//    InitList(LB,setB);
//    InitList(LC,setC);
//    unionSet(LA,LB,LC);
//    DispList(LC);
//
//    Node *L;
//    InitLinkList(L);
//    InsertNode(L,1,1);
////    for (L;L->next != NULL;L = L->next){
////        printf("%d\n", L->data);
////    }
//    printf("%d\n",L->data);
//    return 0;


//// 使用头插法创造一个Linklist
    ElemType set[4] = {1, 2, 3, 4};
//    Node *L;
//    H_createLinkList(L,set,4);
//    DispLinklist(L);
//    DestroyLinkList(L);
//// 使用尾插法创造Linklist
    Node *Link;
    T_createLinkList(Link, set, 4);
    DispLinklist(Link);
    int length;
    length = listLength(Link);
    printf("%d\n",length);
//    DestroyLinkList(Link);
    Bool is = isEmptyLinkList(Link);
    printf("%s\n",(is ? "True":"False" ));
    locateElem(Link, 5);
    ElemType e = 13;
    int loc = 1;
    InsertNode(Link,e,loc);
    DispLinklist(Link);
    DeleteNode(Link,1);
    DispLinklist(Link);

    return 0;


}
