//
//  main.cpp
//  CirleQueue
//
//  Created by robin on 15/4/12.
//  Copyright (c) 2015年 robin. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
typedef int QElemType;
typedef int Status;
#define INFEASIBLE -1
#define OVERFLOW -2
#define  MACQSIZE 100

typedef struct{
    QElemType *base;
    QElemType front;
    QElemType rear;
} SqQueue;

Status InitQueue (SqQueue &Q){

    Q.base=(QElemType *)malloc(MACQSIZE*sizeof(QElemType));
    if(!Q.base) exit(OVERFLOW);
    Q.front=Q.rear=0;
    return OK;
    

}
int QueueLength(SqQueue Q){
    return (Q.rear-Q.front+MACQSIZE)%MACQSIZE;
}
Status EnQueue(SqQueue &Q,QElemType e){
    if((Q.rear+1)%MACQSIZE==Q.front) return ERROR;
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MACQSIZE;
    return OK;
}
Status DeQueue(SqQueue &Q,QElemType &e){
    if(Q.front==Q.rear) return ERROR;
    e=Q.base[Q.front];
    Q.front=(Q.front+1)%MACQSIZE;
    printf("%d",e);
    return OK;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    SqQueue Q;
    InitQueue(Q);
    int e;
    scanf("%d",&e);
    EnQueue(Q, e);
    DeQueue(Q,e);
    
}
