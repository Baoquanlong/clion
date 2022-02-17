#ifndef DOUBLYLIST_DLINKNODE_H
#define DOUBLYLIST_DLINKNODE_H


typedef int ElemType;
//DLinkNode的数据类型：
typedef struct DLinkNode{
    ElemType data;
    struct DLinkNode *prior;
    struct DLinkNode *next;
}link;

/**
 * 头插法创建一个双链表
 * @param L
 * @param set
 * @param n
 */
void H_CreateDListLink(link* &L, ElemType set[],int n);

/**
 * 尾插法创建一个双链表
 * @param L
 * @param set
 * @param n
 */
void T_CreateDListLink(link *&L,ElemType set[], int n);

/**
 * 创建一个空的双链表
 * @param L
 */
void InitDListLink(link *&L);

/**
 * 插入一个结点
 * @param L
 * @param e
 * @param loc
 */
void InsertNode(link *&L, ElemType e,int loc);

/**
 * 删除一个结点
 * @param L
 * @param loc
 * @param e
 */
void DeleteNode(link *&L, int loc, ElemType e);

void DispDListLink(link* L);




#endif //DOUBLYLIST_DLINKNODE_H
