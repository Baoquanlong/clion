//
// Created by 17502 on 2022/1/24.
//
#include <cstdio>
#include <malloc.h>
#include "DLinkNode.h"


void H_CreateDListLink(link *&L, ElemType set[], int n) {
    L = (link *) malloc(sizeof(link));                  //创建头指针
    L->next = nullptr;
    L->prior = nullptr;

    link *p;
    int i = 0;

    while (i < n) {
        p = (link *) malloc(sizeof(link));
        p->data = set[i];
        p->next = L->next;
        if(L->next != nullptr){
            L->next->prior = p;
        }
        p->prior = L;
        L->next = p;
        i++;
    }
}


void T_CreateDListLink(link *&L, ElemType set[], int n) {
    link *s, *r;
    L = (link *) malloc(sizeof(link));
    r = L;
    r->next = nullptr;
    int i = 0;
    while (i < n) {
        s = (link *) malloc(sizeof(link));
        s->data = set[i];
        s->prior = r;
        r->next = s;
        r = s;
        i++;
    }
    r->next = nullptr;
}


void InitDListLink(link *&L) {
    L = (link *) malloc(sizeof(link));
    L->data = 0;
    L->next = nullptr;
    L->prior = nullptr;
}


void InsertNode(link *&L, ElemType e, int loc) {
    link *s, *p;
    p = L;
    int i = 0;
    while (i<loc-1){
        i++;
        p = p->next;
    }
    s = (link*) malloc(sizeof (link));
    s->data = e;
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
}



void DeleteNode(link *&L, int loc, ElemType  &e){
    link *p;
    p = L;
    int i = 0;
    while (i<loc){
        i++;
        p = p->next;
    }
    link *l;
    e = l->data;
    l = p;
    p->prior->next = p->next;
    p->next->prior = l->prior;
    free(l);

}



void DispDListLink(link* L){
    if (L->next == nullptr){
        printf("Empty list");
        return ;
    }
    link *p = L->next;
    int i = 0;
    while (p->next != nullptr){
        i++;
        printf("%dth data is : %d\n",i,p->data);
        p = p->next;
    }
    i++;
    printf("%dth data is : %d\n",i,p->data);
}

