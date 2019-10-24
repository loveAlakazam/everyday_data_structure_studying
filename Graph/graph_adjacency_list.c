#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 50

//그래프 정점(노드)
typedef struct
{
    int vertex;//정점
    struct GraphNode *link; //연결되어있는 정점..
}GraphNode;

//그래프 정의
typedef struct
{
    int n; //정점의 개수

    //각각의 adj_list의 원소들은 GraphNode를 가리킨다..
    GraphNode *adj_list[MAX_VERTICES]; //그래프 인접 리스트: GraphNode 포인터 배열

}GraphType;

//그래프 초기화
void graph_init(GraphType *g)
{
    //정점의 개수 0개
    g->n=0;

    //인접리스트의 시작점도
    for(int v=0; v<MAX_VERTICES; v++)
        g->adj_list[v]=NULL;//아무것도 가리키지 않은걸로 초기화
}

//정점 삽입 연산
void insert_vertex(GraphType *g, int v)
{
    //정점 삽입했는데 MAX_VERTICES를 넘는다면 -> 에러메시지 출력하고 종료
    if( (g->n)+1 > MAX_VERTICES){
        fprintf(stderr, "정점개수 초과");exit(1);
    }
    g->n++; //정점개수(n) 카운트
}

//간선 삽입 연산: v를 u의 인접리스트에 삽입한다..
void insert_edge(GraphType *g, int u, int v)
{
    //시작점: u (u< g->n)  **g->n은 그래프 노드의 개수..
    //u와 연결된점: v (v< g->n)
    if( u>=(g->n) || v>=(g->n)){
        fprintf(stderr, "그래프 정점 번호 오류");
        exit(1);
    }

    //노드 생성..
    //그래프 노드(정점)을 가리키는 포인터 생성.. node는 GraphNode 구조체의 포인터..
    GraphNode * node=(GraphNode *)malloc(sizeof(GraphNode));
    //노드 초기화
    node->vertex=v;
    node->link = g->adj_list[u];
    g->adj_list[u]=node;

    //무방향..
    GraphNode* node_reverse=(GraphNode *)malloc(sizeof(GraphNode));
    node_reverse->vertex=u;
    node_reverse->link = g->adj_list[v];
    g->adj_list[v]=node_reverse;

}

void print_graph(GraphType *g)
{
    GraphNode * now;
    for(int u=0; u<g->n; u++)
    {
        now=g->adj_list[u];
        printf("정점 %d", u);
        while(now){
            printf("-> %d", now->vertex);
            now=now->link;
        }
        printf("\n");
    }
}


int main(void)
{
    //인접리스트 그래프를 정의
    GraphType G;

    //인접리스트 그래프 초기화
    graph_init(&G);

    //정점5개을 삽입한다.
    for(int i=0;i<5; i++){
        insert_vertex(&G, i);
    }

    insert_edge(&G,0,4);
    insert_edge(&G,1,3);
    insert_edge(&G,3,2);
    insert_edge(&G,0,3);
    print_graph(&G);

    return 0;
}
