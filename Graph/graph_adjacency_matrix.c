//인접행렬을 이용한 그래프 추상데이터 타입으 ㅣ구현
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 50 //그래프 정점 최대개수 50개
typedef struct
{
    int n; //정점의 개수
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;


//그래프 초기화: 인접행렬
void graph_init(GraphType* g)
{
    int row, col; //인접행렬의 행과 열
    g->n=0; //그래프의 정점의 개수는 0으로 한다.

    //각 정점들간의 연결을 0으로한다(연결되어있지 않음)으로 초기화
    for(int r=0; r<MAX_VERTICES; r++){
        for(int c=0; c<MAX_VERTICES; c++)
            g->adj_mat[r][c]=0;
    }
}

//정점 삽입연산
void insert_vertex(GraphType *g, int v)
{
    //삽입후 정점의 개수가 MAX_VERTICES보다 크다면-> 에러메시지를 출력하고 종료
    if( (g->n)+1 > MAX_VERTICES){
        fprintf(stderr, "그래프 정점개수 초과");
        exit(1);
    }

    g->n++;//정점개수 추가
}

//간선 삽입연산
void insert_edge(GraphType *g, int start, int end)
{
    //start: 시작정점   (시작정점<그래프 정점개수)
    //end: 도착정점     (도착정점<그래프 정점개수)
    if(start>= g->n || end>= g->n)
    {//에러
        fprintf(stderr,"그래프 정점 번호 오류");
        exit(1);
    }

    //무향그래프
    g->adj_mat[start][end]=1;
    g->adj_mat[end][start]=1;
}

int main(void)
{
    GraphType G; //그래프 정의..

    //그래프를 초기화한다.
    graph_init(&G);

    //정점을 추가한다.
    for(int i=1;i<=10;i++)
        insert_vertex(&G,i);

    //간선 추가한다.
    insert_edge(&G, 1,2);
    insert_edge(&G, 1,3);
    insert_edge(&G, 1,9);
    insert_edge(&G, 2,4);
    insert_edge(&G, 3,6);
    insert_edge(&G, 7,8);
    insert_edge(&G, 9,6);
    insert_edge(&G, 6,4);

    printf("현재 정점개수: %d개\n", G.n);
    printf("무방향 그래프의 인접행렬(adjacency matrix)\n");
    for(int r=0; r<G.n; r++){
        for(int c=0; c<G.n; c++)
            printf("%5d", G.adj_mat[r][c]);
        printf("\n");
    }
}
