#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 50

//그래프 정의
typedef struct
{
    int n; //정점의 개수
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

//그래프 초기화
void init_graph(GraphType *g)
{
    g->n=0; //정점개수 0으로 초기화
    //간선 0으로 초기화
    for(int r=0; r<MAX_VERTICES; r++)
        for(int c=0; c<MAX_VERTICES; c++)
            g->adj_mat[r][c]=0;
}

//정점추가
void insert_vertex(GraphType *g, int v)
{
    if(g->n +1 >MAX_VERTICES){
        fprintf(stderr, "정점개수 초과");
        exit(1);
    }
    g->n++;
}

//간선 추가
void insert_edge(GraphType *g, int start, int end)
{
    if(start>=g->n || end>=g->n){
        fprintf(stderr,"정점 오류");
        exit(1);
    }
    g->adj_mat[start][end]=1;
    g->adj_mat[end][start]=1;
}

void print_matrix(GraphType *g)
{
    for(int r=0;r<g->n; r++)
    {
        for(int c=0; c<g->n; c++)
            printf("%5d", g->adj_mat[r][c]);
        printf("\n");
    }
}

//인접행렬로 표현된 깊이 우선탐색
void dfs_mat(GraphType * g, int v, int *visited)
{
    visited[v]=1; //정점 v를 방문했다.
    printf("%d ",v);//인접정점
    for(int w=0; w<g->n; w++)//인접정점 탐색
    {
        if( g->adj_mat[v][w] && !visited[w])//정점 w를 아직 방문하지 않았다.
            dfs_mat(g,w, visited); //정점w에서 DFS새로 시작..
    }
}

int main(void)
{
    //인접행렬 그래프 정의
    GraphType G;

    //그래프 초기화
    init_graph(&G);

    //정점 추가 (5개 추가)
    for(int i=0; i<6; i++)
        insert_vertex(&G, i);
    insert_edge(&G,0,1);
    insert_edge(&G,0,2);
    insert_edge(&G,0,3);
    insert_edge(&G,0,5);
    insert_edge(&G,1,2);
    insert_edge(&G,2,4);
    insert_edge(&G,3,5);
    insert_edge(&G,4,5);

    printf("\n인접배열 출력\n");
    print_matrix(&G);

    printf("\nDFS 탐색 결과\n");
    int visited[MAX_VERTICES];
    dfs_mat(&G,5, visited);
    return 0;
}
