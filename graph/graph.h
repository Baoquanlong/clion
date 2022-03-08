//
// Created by baoquanlong on 2022/3/6.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H
#define MAXV  30
#define INF 32767


#include "stdio.h"
#include "malloc.h"



typedef int  InfoType ;

typedef struct ANode{
    int adjvex;             //Node's order
    struct ANode* nextVex;          //pointer lead to next edge.
    int weight;
}ArcNode;

typedef struct Vnode{
    InfoType    info ;
    ArcNode * firstNode;            //Pointing to the first ArcNode of the link
}VNode;


typedef struct {
    VNode adjlist[MAXV];
    int n,e;                    //number of vertex:n,  number of edge: e
}AdjGraph;


void CreateAdj(AdjGraph* &G, int A[MAXV][MAXV], int n,int e);







#endif //GRAPH_GRAPH_H
