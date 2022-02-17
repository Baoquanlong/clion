#ifndef CIRCLELIST_CIRCULARLINKLIST_H
#define CIRCLELIST_CIRCULARLINKLIST_H

typedef int ElemType;
typedef struct ClinkList{
    ElemType data;
    struct ClinkList* next;
}Node;


void CreateCLinkList(Node *&L,ElemType set[], int n);
void DisplayLinkList(Node *L);

#endif //CIRCLELIST_CIRCULARLINKLIST_H
