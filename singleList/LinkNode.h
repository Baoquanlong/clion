//
// Created by 17502 on 2022/1/23.
//

#ifndef CPP_LINKNODE_H
#define CPP_LINKNODE_H

#define True 1
#define False 0

typedef int Bool;
typedef int ElemType;
/**
 * LinkNode struct:
 * @param: struct LinkNode : *next;
 * @param: ElemType data;
 */
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} Node;


void H_createLinkList(Node *&L, ElemType set[], int n);

void T_createLinkList(Node *&L, ElemType set[], int n);

/**
 * InsertNode(Node *p, int loc)
 */
void InsertNode(Node *&L, ElemType e, int loc);

/**
 *
 * @param L the link which need to change;
 * @param loc the location of the node deleted;
 * @return Deleted node;
 */
Node* DeleteNode(Node *&L, int loc);

/**
 *
 * @param L
 */
void InitLinkList(Node *&L);

/**
 *
 * @param L the LinkList need to be destroyed;
 */
void DestroyLinkList(Node *&L);

Bool isEmptyLinkList(Node *L);

/**
 *
 * @param L
 * @return  the length of the list;
 */
int listLength(Node *L);

/**
 *
 * @param L
 */
void DispLinklist(Node *L);

/**
 * get the ith order in  the linklist ,and return the result by e;
 * @param L
 * @param i
 * @param e
 */
void getElem(Node *L, int i, ElemType e);

/**
 * find the location of e in linklist L ;
 * @param L
 * @param e
 */
int locateElem(Node *L, ElemType e);


#endif //CPP_LINKNODE_H
