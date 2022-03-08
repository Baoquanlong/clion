//
// Created by baoquanlong on 2022/2/27.
//

#include "header.h"
#include "malloc.h"

//binary tree's basic operations



//1. Create a binary tree by strings with brackets.
//like: A(B(D,E ), C(,F))

//we need to deal with four kinds characters, '(' , ')' , ',' and others.
//use stack to create tree.
//if ch is others, push is in stack, if next ch is not '(', which means the head of stack
//do not have child.
//if ch is '(', which means the head of stack have a lChild, let k = 1 stand it ,and
//if ch == ',', which means we get a rChild, let k = 2 stand it.

void CreateBTree(BINode *b, char str[]){
    int i = 0;
    int k = 0;
    BINode *Node[MaxSize];
    BINode *p;
    int top = -1;
    b = nullptr;
    char ch;
    ch = str[i];

    while (ch != '\0'){
        switch (ch) {
            case '(': top++;Node[top] = p;k = 1;break;
            case ')': top--;break;
            case ',': k = 2;break;
            default:p = (BINode*) malloc(sizeof (BINode));
            p->lChild = nullptr;
            p->rChild = nullptr;
            p->data = ch;
            if (b == nullptr){
                b = p;
            } else{
                switch (k) {
                    case 1: Node[top]->lChild = p;break;
                    case 2: Node[top]->rChild = p;break;
                }
            }
        }
        i++;
        ch = str[i];
    }


}


//Destroy a btree
void DestroyBTree(BTNode *&T){
    if (T != nullptr){
        DestroyBTree(T->lChild);
        DestroyBTree(T->rChild);
        free(T);
    }
}


//FindBTNode()

BTNode* FindBTNode(BTNode* b,ElemType data){
    BTNode *p;
    if (b== nullptr){
        return nullptr;
    } else if (b->data == data) {
        return b;
    } else{
        p = FindBTNode(b->lChild,data);
        if (p != nullptr){
            return p;
        } else{
            return FindBTNode(b->rChild,data);
        }
    }
}


//Find lChildNode(p) and RChildNode(p)


//BTNode* LChildNode(BTNode* b, ElemType data){
//    BTNode * res = FindBTNode(b,data);
//    return res->lChild;
//}
//BTNode* RChildNode(BTNode* b, ElemType data){
//    BTNode * res = FindBTNode(b,data);
//    return res->rChild;
//}

BTNode* LChildNode(BTNode* p ){
    return p->lChild;
}
BTNode* RChildNode(BTNode* p ){
    return p->rChild;
}

//get BTHeight;
int GetHeight(BTNode* b){
    if (b == nullptr){
        return 0;
    }
    int lh = 0;
    int rh = 0;
    int maxh = 0;
    if( b!= nullptr){
        lh = GetHeight(b->lChild);
        rh = GetHeight(b->rChild);
        maxh = lh>rh?lh:rh;
    }
    return maxh+1;
}


//displayBinary Tree()
//the procession is :for not null tree b,output data of b, if it has left child or right head,
//out put a '(' ,then recursive processing the left child tree; if exits a right child, output a
//',',then processing the right child tree recursively, at last, output a ')'.

void DispBTree(BTNode* b){
    if (b == nullptr){
        return;
    } else{
        printf("%c",b->data);
        if(b->lChild!= nullptr || b->rChild!= nullptr){
            printf("(");
            DispBTree(b->lChild);
            if (b->rChild!= nullptr){
                printf(",");
            }
            DispBTree(b->rChild);
            printf(")");
        }
    }
}




//Traversal of the BTree


//preorder traversal

void PreOrder(BTNode* b){
    if (b == nullptr){
        return;
    } else{
        printf("%c",b->data);
        PreOrder(b->lChild);
        PreOrder(b->rChild);
    }
}

//postorder traversal
void PostOrder(BTNode* b){
    if (b!= nullptr){
        PostOrder(b->lChild);
        PostOrder(b->rChild);
        printf("%c",b->data);
    }
}


//Inorder traversal
void InOrder(BTNode* b){
    if (b!= nullptr){
        InOrder(b->lChild);
        printf("%c",b->data);
        InOrder(b->rChild);
    }
}

//levelOrder
//using SqQueue.
//void LevelOrder(BTNode* b){
//    Queue sq;
//    //Init sq;
//    sq.front = -1;
//    sq.rear = -1;
//    BTNode* p;
//    if (b == nullptr){
//        return;
//    } else{
//        p = b;
//        sq.front++;
//        sq.data[sq.front] = p;
//        if (p->lChild || p->rChild != nullptr){
//            printf("%c",p->data);
//            sq.rear++;
//            LevelOrder(p->rChild);
//            LevelOrder(p->rChild);
//        }
//    }
//}

//enQueue by rear index, deQueue by front index.
void InitQu(Queue *&qu){
    qu->rear = -1;
    qu->front = -1;
}
void EnQueue(Queue *&qu, BTNode* b){
    qu->rear++;
    qu->data[qu->rear] = b;
}
BTNode* DeQueue(Queue *&qu){
    qu->front++;
    return qu->data[qu->front];
}
//levelOrder

bool QuEmpty(Queue *qu){
    return (qu->rear == qu->front);
}

void LevelOrder(BTNode *b){
    Queue *qu;
    InitQu(qu);
    EnQueue(qu,b);
    while (!QuEmpty(qu)){
        BTNode* p = DeQueue(qu);
        printf("%c",p->data);
        if(p->lChild != nullptr){
            EnQueue(qu,p->lChild);
        }
        if (p->rChild != nullptr){
            EnQueue(qu,p->rChild);
        }
    }
}


//n  is the number of tree's node.
BTNode* CreateBT1(char *pre,char* in,int n){
    BTNode* b;
    char *p;
    if (n<=0){
        return nullptr;
    }
    b = (BTNode*) malloc(sizeof (BTNode));
    b->data = *pre;
    //p is using for record the position of the root of the tree in string in.
    for (p = in;p<in+n;p++) {
        if ( *p == *pre) {
            break;
        }
    }
    int k; // k is recording the posion of root in string in.
    k = p-in;
    b->lChild = CreateBT1(pre+1,in,k);
    b->rChild = CreateBT1(pre+k+1,p+1,n-k-1);
    return b;
}


BTNode* CreateBT2(char* post, char* in, int n){
    BTNode* b;              //The created tree's root node
    int k=0;                  //k is used for mark the place of the root node's place in string in
    char r;                 //r is used for keep the data of root node
    char *p;
    if (n<=0){
        return nullptr;
    }
    r = *(post+n-1);
    b = (BTNode*) malloc(sizeof (BTNode));

    for (p = in;p<in+n;p++){
        if (*p == r){
            break;
        }
    }
    k = p-in;
    b->lChild = CreateBT2(post,in,k);                   //Recursive construct lchild

    b->rChild = CreateBT2(post+k,p+1,n-k-1);        //Recursive  construct rchild
    return b;
}










