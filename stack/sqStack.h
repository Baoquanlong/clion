//
// Created by 17502 on 2022/1/28.
//

#ifndef STACK_SQSTACK_H
#define STACK_SQSTACK_H
#define MaxSize 20
typedef int ElemType;

typedef struct sqStack{
    ElemType data[MaxSize];
    int top;
}stack;

void InitStack(stack *&s) ;

void DestroyStack(stack *&s) ;

bool IsEmptyStack(stack *s) ;

void Push(stack *&s, ElemType e) ;

ElemType Pop(stack *&s) ;

bool GetTop(stack *&s, ElemType &e);

#endif //STACK_SQSTACK_H
