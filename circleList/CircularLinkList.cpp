#include "cstdio"
#include "malloc.h"
#include "CircularLinkList.h"

void CreateCLinkList(Node *&L,ElemType set[], int n){
    Node *s,*r;
    L = (Node* ) malloc(sizeof (Node));
    L->next = nullptr;
    r = L;
    int i=0;
    while (i<n){
        s = (Node *) malloc(sizeof (Node));
        s->data = set[i];
        r->next = s;
        r = s;
        i++;
    }
    r->next = L;
}


void DisplayLinkList(Node *L){
    Node *p;
    p = L;
    int i =1;
    while (p->next != nullptr && p->next !=L){
        p = p->next;
        printf("%dth data is :%d\n",i,p->data);
        i++;
    }
}