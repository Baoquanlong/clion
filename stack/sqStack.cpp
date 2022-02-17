//
// Created by 17502 on 2022/1/28.
//

#include "sqStack.h"
#include "malloc.h"
#include "cstdio"


void InitStack(stack *&s) {
    s = (stack *) malloc(sizeof(stack));
    s->top = -1;
}


void DestroyStack(stack *&s) {
    free(s);
}


bool IsEmptyStack(stack *s) {
    return (s->top == -1);
}


void Push(stack *&s, ElemType e) {
    if (s->top < MaxSize - 1) {
        s->top++;
        s->data[s->top] = e;
    } else {
        printf("StackOverFlow Error\n");
    }
}


ElemType Pop(stack *&s) {
    if (s->top>-1){
        s->top--;
        return s->data[s->top+1];
    } else{
        printf("No more data\n");
    }
}



//取栈顶元素
bool GetTop(stack *&s, ElemType &e){
    if (IsEmptyStack(s)){
        return false;
    } else{
        e = s->data[s->top];
        return true;
    }
}


