//
// Created by baoquanlong on 2022/3/5.
//


#include "HuffmanTree.h"

//Create a huffman tree

void CreateHTree(HTNode ht[],int n0){
    int i,k,lnode,rnode;        //lnode和rnode记录权重最小的两个节点的位置
    double min1,min2;           //找到权值最小的两个树
    for (i=0;i<2*n0-1;i++){                 //n0个叶子节点一共有2*n0-1个节点
        ht[i].parent = ht[i].lchild = ht[i].rchild = -1;     //初始化
    }
    for (i = n0;i<2*n0-2;i++) {
        min1 = min2 = 32767 ;
        lnode = rnode = -1 ;
        for (k = 0;k<i-1;k++){
            //找到最小的两个权值的位置
            if (ht[i].weight != -1){
                if (ht[i].weight < min1){               //min1->lnode, min2->rnode
                    min2 = min1; rnode = lnode;
                    min1 = ht[i].weight;
                    lnode = k;
                } else if (ht[i].weight <min2){
                    min2 = ht[i] .weight;
                    rnode = k;
                }
            }
            ht[i].weight = ht[lnode].weight + ht[rnode].weight;
            ht[lnode].parent = i;
            ht[rnode].parent = i;
            ht[i].lchild = lnode;
            ht[i].rchild = rnode;
        }
    }

}





// HuffmanCode
void CreateHFCode(HTNode ht[], HCode hcd[], int n0){
    int i,f,c;
    HCode hc;
    for (i = 0;i<n0;i++){
        hc.start = n0;
        c = i;      //c为当前位置的节点
        f = ht[i].parent;
        while (f!=-1){
            if (ht[f].lchild == c){
                hc.cd[hc.start--] = '0';
            } else{
                hc.cd[hc.start--] = '1';
            }
            c = f;
            f = ht[f].parent;
        }
        hc.start++;
        hcd[i] = hc;
    }
}

