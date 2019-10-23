#include<stdio.h>
#include<stdlib.h>

typedef int element;

//큐노드 구조체 정의
typedef struct{
    element data;
    struct QueueNode * link;
}QueueNode;

//큐 구조체 정의
typedef struct{
    QueueNode *front;
    QueueNode *rear;
}QueueType;

//큐 초기화
void init_queue(QueueType * q)
{
    q->front=NULL;
    q->rear=NULL;
}

//큐노드 삽입
void insert_queue_node(QueueType *q, element e)
{
    //큐노드 생성
    QueueNode * new_node=(QueueNode*)malloc(sizeof(QueueNode));
    //큐노드 초기화
    new_node->data=e;
    new_node->link=NULL;

    //큐노드 삽입(rear 부분에서 삽입한다)
    if(q->rear==NULL){//큐가 비어있다면
        q->front=new_node;
    }
    else{//큐가 비어있지 않다면
        q->rear->link=new_node;
    }
    q->rear=new_node;
}

//큐노드 삭제
element delete_queue_node(QueueType *q)
{
    //큐가 비어있다면 -> 에러문을 보낸다.
    if(q->front==NULL && q->rear==NULL){
        fprintf(stderr, "큐가 비어있습니다.");
        exit(1);
    }

    //front 부분에서 삭제한다. (먼저들어온 노드삭제)
    QueueNode *removed=q->front;
    element pop_val =removed->data;

    if(q->rear==q->front){//큐에 노드 1개만 있는경우
        q->rear=NULL;
    }
    q->front=q->front->link;
    return pop_val;
}

void print_queue(QueueType * q)
{
    QueueNode * i;
    for(i=q->front; i; i=i->link){
        if(i==q->rear){
            printf("%d\n", i->data);
        }
        else
            printf("%d->", i->data);
    }
}

int main(void)
{
    //큐정의
    QueueType Q;

    //큐초기화
    init_queue(&Q);

    //큐에 노드 삽입
    for(int i=1;i<=10; i++){
        insert_queue_node(&Q, i);
        print_queue(&Q);
        printf("\n");
    }


    //큐에 노드 삭제
    for(int i=0;i<5; i++){
        printf("pop(): %d\n",delete_queue_node(&Q));
        print_queue(&Q);
        printf("\n");
    }

    return 0;
}
