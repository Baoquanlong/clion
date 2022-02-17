#include "stdio.h"
#include "malloc.h"
#include "sqlist.h"
//CreateList()
void CreateList(list* &L){
    L = (list*)(malloc(sizeof(list)));
    L->length = 0;
}
//InitList()
void InitList(list* &L, ElemType set[]){
   int i;
   for(i=0;i<MaxSize;i++){
       if(set[i]=='\0'){
           break;
       }
       else{
           L->list[i] = set[i];
           L->length++;
       }
   }
    for(i=L->length;i<MaxSize;i++){
        L->list[i] = '\0';
    }
}

//DispList()
void DispList(list* &L){
   int i;
   for (i=0;i<MaxSize;i++){
       if (L->list[i] != '\0'){
           printf("%dth data is : %d\n",i+1,L->list[i]);
       } else if (L->list[i]=='\0'){
           break;
       }
   }
}

//DestroyList()
Bool DestroyList(list* &L){
    free(L);
    return True;
}
//listEmpty()
Bool listEmpty(list* &L){
    Bool res = False;
    if(L->length == 0){
       res = True;
    }
    return res;
}
//listLenth()
int listLenth(list* L){
    return L->length;
}
//getElem()
ElemType getElem(list* L, int order){
    return L->list[order-1];
}


//LocateElem(list* L,elemtype e)
int LocateElem(list* L,ElemType e){
    int i = 0;
    for (i;i<L->length;i++){
       if (L->list[i] == e) {
           return i+1;
       }
    }
    return 0;
}
//listInsert()
void listInsert(list* &L, ElemType e, int loc){
    int i =0;
    for (i= L->length;i>=loc;i--){
        L->list[i] = L->list[i-1];
    }
    L->list[loc-1] = e;
    L->length++;
}

//listDelete()
ElemType listDelete(list* &L,int loc){
    ElemType ret = L->list[loc-1];
    int i = 0;
    for(i = loc;i<L->length;i++){
        L->list[loc-1] = L->list[loc];
    }
    L->length--;
    return ret;
}


//int main(){
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
//    return 0;
//}
