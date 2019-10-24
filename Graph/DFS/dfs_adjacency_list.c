#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 50

//그래프 노드
typedef struct{
    int vertex;
    struct GraphNode * link;
}GraphNode;

//인접리스트 형태 그래프 정의
typedef struct{
    int n;//정점개수
    GraphNode * adj_list[MAX_VERTICES]; //인접리스트
}GraphType;

//그래프 초기화
void init_graph(GraphType * g)
{
    //정점개수 0개
    g->n=0;

    //인접리스트의 원소들을 아무런 노드를 가리키지 않는다.ㅏ
    for(int i=0; i<MAX_VERTICES; i++)
        g->adj_list[i]=NULL;
}

//그래프 정점 추가
void insert_vertex(GraphType *g, int v)
{
    if(g->n+1 >MAX_VERTICES){
        fprintf(stderr,"정점 개수 초과");exit(1);
    }
    g->n++;
}

//그래프 간선 추가
void insert_edge(GraphType *g, int u, int v)
{
    if(u>=g->n || v>=g->n){
        fprintf(stderr,"정점 오류");
        exit(1);
    }

    //1. u와 v연결
    //노드 생성
    GraphNode * node1=(GraphNode*)malloc(sizeof(GraphNode));
    node1->vertex=v;
    node1->link=g->adj_list[u];
    g->adj_list[u]=node1;

    //2. v와 u연결
    GraphNode * node2=(GraphNode*)malloc(sizeof(GraphNode));
    node2->vertex=u;
    node2->link=g->adj_list[v];
    g->adj_list[v]=node2;
}

void print_graph(GraphType *g)
{
    GraphNode * p;
    for(int u=0; u<g->n; u++)
    {

        p=g->adj_list[u];
        printf("%d ", u);
        while(p){
            printf("-> %d", p->vertex);
            p=p->link;
        }
        printf("\n");
    }
}


//인접리스트에서 dfs 탐색
void dfs_list(GraphType * g, int v, int *visited)
{
    //정점 v는 방문했다.
    visited[v]=1;
    printf("%d ", v);

    //정점 v의 인접노드 탐색
    //w는 v와 연결된 노드를 가리키는 포인터
    for(GraphNode * w=g->adj_list[v]; w ; w=w->link) //w가 NULL이 아니라면
    {
        if(visited[w->vertex]!=1)//w가 가리키는 노드가 방문하지 않았다면
            dfs_list(g, w->vertex, visited);
    }
}

int main(void)
{
    // 인접리스트 그래프 정의
    GraphType G;

    // 인접리스트 그래프 초기화
    init_graph(&G);

    //그래프 정점 추가
    for(int i=0; i<6; i++)
        insert_vertex(&G,i);

    //간선 추가
    insert_edge(&G,0,1);
    insert_edge(&G,0,2);
    insert_edge(&G,0,3);
    insert_edge(&G,0,5);
    insert_edge(&G,1,2);
    insert_edge(&G,2,4);
    insert_edge(&G,3,5);
    insert_edge(&G,4,5);

    //그래프 출력
    print_graph(&G);
    printf("\n");

    //DFS탐색
    int visited[MAX_VERTICES]; //방문리스트..
    dfs_list(&G, 5, visited);
}
