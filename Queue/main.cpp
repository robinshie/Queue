//
//  main.cpp
//  Queue
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
typedef struct QNode {
    QElemType date;
    struct QNode *next;

} QNode,*QueuePtr;
typedef struct {
    QueuePtr front;
    QueuePtr rear;

}LinkQueue;

Status InitQueue(LinkQueue &Q)
{
    Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
    if(!Q.front) exit(OVERFLOW);
    Q.front->next=NULL;
    return OK;

}
Status DestoryQueue(LinkQueue &Q){

    while (Q.front) {
        Q.rear=Q.front->next;
        free(Q.front);
        Q.front=Q.rear;
    }
    return OK;

}
Status EnQueue(LinkQueue &Q,QElemType e){
    QueuePtr p;
    p=(QueuePtr)malloc(sizeof(QNode));
    if(!p) exit(OVERFLOW);
    p->date = e;p->next=NULL;
    Q.rear->next=p;
    Q.rear=p;
    return OK;
}

Status DeQueue(LinkQueue &Q,QElemType &e){
    QueuePtr p;
    if(Q.front==Q.rear) return ERROR;
    p=Q.front->next;
    e=p->date;
    Q.front->next=p->next;
    
    if (Q.rear==p) Q.rear=Q.front;
    printf("%d\n",e);
    free(p);
    
    
    return OK;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    LinkQueue Q;
    int e;
    scanf("%d",&e);
    
    InitQueue(Q);
    EnQueue(Q, e);
    DeQueue(Q,e);
}
