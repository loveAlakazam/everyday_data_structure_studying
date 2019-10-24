#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 50

//�׷��� ���
typedef struct{
    int vertex;
    struct GraphNode * link;
}GraphNode;

//��������Ʈ ���� �׷��� ����
typedef struct{
    int n;//��������
    GraphNode * adj_list[MAX_VERTICES]; //��������Ʈ
}GraphType;

//�׷��� �ʱ�ȭ
void init_graph(GraphType * g)
{
    //�������� 0��
    g->n=0;

    //��������Ʈ�� ���ҵ��� �ƹ��� ��带 ����Ű�� �ʴ´�.��
    for(int i=0; i<MAX_VERTICES; i++)
        g->adj_list[i]=NULL;
}

//�׷��� ���� �߰�
void insert_vertex(GraphType *g, int v)
{
    if(g->n+1 >MAX_VERTICES){
        fprintf(stderr,"���� ���� �ʰ�");exit(1);
    }
    g->n++;
}

//�׷��� ���� �߰�
void insert_edge(GraphType *g, int u, int v)
{
    if(u>=g->n || v>=g->n){
        fprintf(stderr,"���� ����");
        exit(1);
    }

    //1. u�� v����
    //��� ����
    GraphNode * node1=(GraphNode*)malloc(sizeof(GraphNode));
    node1->vertex=v;
    node1->link=g->adj_list[u];
    g->adj_list[u]=node1;

    //2. v�� u����
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


//��������Ʈ���� dfs Ž��
void dfs_list(GraphType * g, int v, int *visited)
{
    //���� v�� �湮�ߴ�.
    visited[v]=1;
    printf("%d ", v);

    //���� v�� ������� Ž��
    //w�� v�� ����� ��带 ����Ű�� ������
    for(GraphNode * w=g->adj_list[v]; w ; w=w->link) //w�� NULL�� �ƴ϶��
    {
        if(visited[w->vertex]!=1)//w�� ����Ű�� ��尡 �湮���� �ʾҴٸ�
            dfs_list(g, w->vertex, visited);
    }
}

int main(void)
{
    // ��������Ʈ �׷��� ����
    GraphType G;

    // ��������Ʈ �׷��� �ʱ�ȭ
    init_graph(&G);

    //�׷��� ���� �߰�
    for(int i=0; i<6; i++)
        insert_vertex(&G,i);

    //���� �߰�
    insert_edge(&G,0,1);
    insert_edge(&G,0,2);
    insert_edge(&G,0,3);
    insert_edge(&G,0,5);
    insert_edge(&G,1,2);
    insert_edge(&G,2,4);
    insert_edge(&G,3,5);
    insert_edge(&G,4,5);

    //�׷��� ���
    print_graph(&G);
    printf("\n");

    //DFSŽ��
    int visited[MAX_VERTICES]; //�湮����Ʈ..
    dfs_list(&G, 5, visited);
}
