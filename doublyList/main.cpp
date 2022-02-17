#include "DLinkNode.h"
#include "cstdio"

void Switch(int *a,int *b){
    int *c;
    c = a;
    a = b;
    b = c;
}

//int main(){
//    link *L;
//    ElemType set[] = {1,1,2,1,3,1};
//    H_CreateDListLink(L,set,6);
//    DispDListLink(L);
//    T_CreateDListLink(L,set,6);
//    DispDListLink(L);
//    return  0;
//    int a = 1,b = 2;
//    int *p,*q;
//    p = &a;
//    q = &b;
//    Switch(p,q);
//    printf("a = %d\tb = %d",*p,*q);
//}