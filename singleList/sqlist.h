//
// Created by 17502 on 2022/1/23.
//

#ifndef CPP_SQLIST_H
#define CPP_SQLIST_H


#define MaxSize 20
#define True 1
#define False 0

typedef int Bool;
typedef int ElemType;
typedef struct sqlist{
    ElemType list[MaxSize];
    int length;
}list;


void CreateList(list* &L);

void InitList(list* &L, ElemType set[]);

void DispList(list* &L);

Bool DestroyList(list* &L);

Bool listEmpty(list* &L);

int listLenth(list* L);

ElemType getElem(list* L, int order);

int LocateElem(list* L,ElemType e);

void listInsert(list* &L, ElemType e, int loc);

ElemType listDelete(list* &L,int loc);

#endif //CPP_SQLIST_H
