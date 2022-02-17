#include "cstdio"
#include "LinkNode.h"
#include "malloc.h"

/**
 * 头插法创建一个表
 * @param L
 * @param set
 */
void H_createLinkList(Node *&L, ElemType set[], int n) {
    L = (Node *) malloc(sizeof(Node));      //创建头结点headPtr;
    L->next = nullptr;
    Node *q;
    int i = 0;
    while (i < n) {
        q = (Node *) malloc(sizeof(Node));      //创建数据节点;
        q->data = set[i];
        q->next = L->next;
        L->next = q;
        i++;
    }
}

void T_createLinkList(Node *&L, ElemType set[], int n) {
    Node *s, *r;                    //声明尾结点和s节点, s节点是数据节点；
    L = (Node *) malloc(sizeof(Node));
    L->next = nullptr;
    r = L;                          //尾结点指向 L;
    int i;
    while (i < n) {
        s = (Node *) malloc(sizeof(Node));             //创建数据节点
        s->data = set[i];
        r->next = s;
        r = s;
        i++;
    }
    r->next = nullptr;
}

/**
 * 建立一个空表
 * @param L
 */
void InitLinkList(Node *&L) {
    L = (Node *) malloc(sizeof(Node));
    L->next = nullptr;
}

void DestroyLinkList(Node *&L) {
    Node *p, *q;
    p = L;
    while (L != nullptr) {
        q = p->next;
        free(p);
        p = q;
    }
}

Bool isEmptyLinkList(Node *L) {
    int length = 0;
    Node *p = L;
    while (p != nullptr) {
        length++;
        p = p->next;
    }
    return length == 0 ? True : False;
}

int listLength(Node *L) {
    int length = 0;
    Node *p;
    p = L->next;
    while (p != nullptr) {
        length++;
        p = p->next;

    }
    return length;
}

void DispLinklist(Node *L) {
    int i = 0;
    Node *p = L->next;
    while (p != nullptr) {
        i++;
        printf("%dth node's data is : %d \n", i, p->data);
        p = p->next;
    }
}

void getElem(Node *L, int i, ElemType &e) {
    int j = 0;
    Node *p = L;
    while (j < i) {
        p = p->next;
        j++;
    }
    e = p->data;
}


int locateElem(Node *L, ElemType e) {
    Node *p = L->next;
    int loc = 1;
    while (p != nullptr){
        if(p->data == e){
            return loc;
        }else{
            p = p->next;
            loc++;
        }
    }
    return -1;

}

void InsertNode(Node *&L, ElemType e, int loc) {
    //先遍历一遍L,求出他的length
    int j = 0;
    Node *s = L->next;
    while(s!= nullptr){
        j++;
        s = s->next;
    }
    if(loc<=0 || loc >j){
        printf("Not in the range");
        return;
    }


    int i = 0;
    Node *p = L;
    while (i < loc - 1) {
        i++;
        p = p->next;
    }
    Node *q;
    q = (Node *) malloc(sizeof(Node));
    q->data = e;
    q->next = p->next;
    p->next = q;
}


Node *DeleteNode(Node *&L, int loc) {
    int j = 0;
    Node *s = L->next;
    while(s!= nullptr){
        j++;
        s = s->next;
    }
    if(loc<=0 || loc >j){
        printf("Not in the range");
        return nullptr;
    }
    Node *p, *q;
    Node *e;
    int i = 0;
    p = L;
    while (i < loc - 1) {
        i++;
        p = p->next;
    }
    q = p->next;
    e = (Node *) malloc(sizeof(Node));
    e->data = q->data;
    e->next = q->next;
    p->next = p->next->next;
    free(q);
    return e;
}

