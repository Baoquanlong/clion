//
// Created by baoquanlong on 2022/3/6.
//

#include "graph.h"


void CreateAdj(AdjGraph *&G, int A[MAXV][MAXV], int n, int e) {
    int i, j;
    ArcNode *p;
    G = (AdjGraph *) malloc(sizeof(AdjGraph));
    for (i = 0; i < n; i++) {
        G->adjlist[i].firstNode = nullptr;
    }
    for (i = 0; i < n; i++) {
        for (j = n - 1; j >= 0; j--) {
            if (A[i][j] != 0 && A[i][j] != INF) {
                p = (ArcNode *) malloc(sizeof(ArcNode));
                p->adjvex = j;
                p->weight = A[i][j];
                p->nextVex = G->adjlist[i].firstNode;               //头插法
                G->adjlist[i].firstNode = p;
            }
        }
    }
    G->n = n;
    G->e = e;

}




//display

void DispAdj(AdjGraph *G) {
    int i;
    ArcNode *p;
    for (i = 0; i < G->n; i++) {
        p = G->adjlist[i].firstNode;
        while (p != nullptr) {
            printf(" the order is : %d, the weight is :%d", p->adjvex, p->weight);
            p = p->nextVex;
        }
        printf("^\n");
    }
}


//DestroyAdj

//先释放其他节点，最后释放头节点

//void DestroyAdj(AdjGraph* &G){
//    int i;
//    ArcNode *pre,*p;
//    for ( i = 0; i<G->n; i++){
//        pre = G->adjlist[i].firstNode;
//        if (pre == nullptr){
//            continue;
//        } else if (pre->nextVex != nullptr){
//            pre = pre->nextVex;
//            while (pre->nextVex != nullptr){
//                p = pre->nextVex;
//                free(pre);
//                pre = p;
//            }
//
//            free(G->adjlist[i].firstNode);
//        }
//    }
//
//    free(G);
//}


void DestroyAdj(AdjGraph *&G) {
    int i;
    ArcNode *pre, *p;
    for (i = 0; i < G->n; i++) {
        pre = G->adjlist[i].firstNode;
        if (pre != nullptr) {
            p = pre->nextVex;
            while (p != nullptr) {
                pre = p;
                free(pre);
                p = pre->nextVex;
            }
            free(pre);
        }
    }
    free(G);
}


//Depth first search
void DFS(AdjGraph *G, int v) {           //v is the initialized order of the vertex
    int visited[MAXV] = {0};
    printf("%d\n",v);               //visit v first;
    visited[v] = 1;

    ArcNode *p;
    p = G->adjlist[v].firstNode;            //visit v's first neighbor vertex
    while (p != nullptr){
        if (visited[p->adjvex] != 1){
            DFS(G,p->adjvex);
        }
        p = p->nextVex;
    }
}

