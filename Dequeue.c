#include<stdio.h>
#include<stdlib.h>
typedef int element;

//덱노드 구성..
typedef struct{
    element data;
    struct DeqNode *left;
    struct DeqNode *right;
}DeqNode;

//덱 정의
typedef struct{
    DeqNode * front;
    DeqNode * rear;
}DeqType;

//덱 초기화
void init_deq(DeqType *dq)
{
    dq->front=NULL;
    dq->rear=NULL;
}

//삽입연산- front단에서 삽입
void insert_front(DeqType * dq, element e)
{// (새로운노드)  [ front    rear]

    //노드 생성
    DeqNode * new_node=(DeqNode*)malloc(sizeof(DeqNode));
    new_node->data=e;
    new_node->left=NULL;
    new_node->right=dq->front;

    //노드 삽입
    if(dq->rear==NULL)//덱이 비어있을 때
        dq->rear=new_node;
    else //덱이 비어있지 않을 때
        dq->front->left=new_node;

    dq->front=new_node;
}

//삽입연산- rear단에서 삽입
void insert_rear(DeqType *dq, element e)
{// [front rear] (새로운노드)
    //노드 생성
    DeqNode * new_node=(DeqNode*)malloc(sizeof(DeqNode));
    new_node->data=e;
    new_node->left=dq->rear;
    new_node->right=NULL;

    //노드 삽입
    if(dq->front==NULL)//덱이 비어있을 때
        dq->front=new_node;
    else //덱이 비어있지 않을때
        dq->rear->right=new_node;

    dq->rear=new_node;
}

//삭제연산- front단에서 삭제
element delete_front(DeqType * dq)
{
    if(dq->front==NULL && dq->rear==NULL){
        fprintf(stderr,"비어있는 큐. 삭제불가능");
        exit(1);
    }

    DeqNode *removed=dq->front;
    element tmp = removed->data;

    dq->front= dq->front->right;
    if(dq->front==NULL){ dq->rear=NULL;}
    else{dq->front->left=NULL;}
    return tmp;
}

//삭제연산- rear단에서 삭제
element delete_rear(DeqType * dq)
{
    if(dq->front==NULL && dq->rear==NULL){
        fprintf(stderr,"비어있는 큐. 삭제불가능");
        exit(1);
    }

    DeqNode *removed=dq->rear;
    element tmp = removed->data;
    dq->rear= dq->rear->left;
    if(dq->front==NULL){dq->rear=NULL;}
    else{dq->rear->right=NULL;}
    return tmp;
}

void print_deq(DeqType * dq)
{
    DeqNode * i;
    for(i=dq->front; i; i=i->right){
        if(i==dq->rear)
            printf("%d\n", i->data);
        else
            printf(" %d->", i->data);
    }
    printf("\n");
}


int main(void)
{
    //덱정의
    DeqType DEQ;

    //덱초기화
    init_deq(&DEQ);

    //덱노드 삽입(front)
    for(int i=1; i<=10; i++){
        insert_front(&DEQ, i);
        print_deq(&DEQ);
    }
    //덱노드 삭제(front)
    for(int i=1; i<10; i++){
        delete_front(&DEQ);
        print_deq(&DEQ);
    }

    //덱노드 삽입(rear)
    for(int i=11; i<=20; i++){
        insert_rear(&DEQ, i);
        print_deq(&DEQ);
    }

    //덱노드 삭제(rear)
    for(int i=0; i<5; i++){
        delete_rear(&DEQ);
        print_deq(&DEQ);
    }
    return 0;
}
