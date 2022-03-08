#include "header.h"

//求树的高度的递归算法

int getHeight(TSonNode *T){
    int h = 0;
    int maxh = 0;
    if ( T == nullptr){
        return 0;
    } else{
        for (int i = 0;i<MaxSons;i++){
            TSonNode *p;
            p = T->sons[i];
            if (p != nullptr){
                h = getHeight(p);
                if (h>maxh ){
                    maxh = h;
                }
            }
        }

    }
    return (maxh + 1);

}


