#include "cstdio"
typedef char ElemType;
typedef struct tnode {
    ElemType data;
    tnode * child;
    tnode * bro;
}TSBNode;



//求树的高度
int getHeight(TSBNode * T){
    int h = 0;
    int maxh = 0;
    if ( T = nullptr) {
        return 0;
    } else{
        TSBNode *p;
        p  = T->child;
        while (p != nullptr){
            if (T->child != nullptr){
                h = getHeight(p);
                if (h>maxh){
                    maxh = h;
                }
                p = p->bro;
            }

        }
    }
    return maxh+1;


}