#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 50

//�׷��� ����
typedef struct
{
    int n; //������ ����
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

//�׷��� �ʱ�ȭ
void init_graph(GraphType *g)
{
    g->n=0; //�������� 0���� �ʱ�ȭ
    //���� 0���� �ʱ�ȭ
    for(int r=0; r<MAX_VERTICES; r++)
        for(int c=0; c<MAX_VERTICES; c++)
            g->adj_mat[r][c]=0;
}

//�����߰�
void insert_vertex(GraphType *g, int v)
{
    if(g->n +1 >MAX_VERTICES){
        fprintf(stderr, "�������� �ʰ�");
        exit(1);
    }
    g->n++;
}

//���� �߰�
void insert_edge(GraphType *g, int start, int end)
{
    if(start>=g->n || end>=g->n){
        fprintf(stderr,"���� ����");
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

//������ķ� ǥ���� ���� �켱Ž��
void dfs_mat(GraphType * g, int v, int *visited)
{
    visited[v]=1; //���� v�� �湮�ߴ�.
    printf("%d ",v);//��������
    for(int w=0; w<g->n; w++)//�������� Ž��
    {
        if( g->adj_mat[v][w] && !visited[w])//���� w�� ���� �湮���� �ʾҴ�.
            dfs_mat(g,w, visited); //����w���� DFS���� ����..
    }
}

int main(void)
{
    //������� �׷��� ����
    GraphType G;

    //�׷��� �ʱ�ȭ
    init_graph(&G);

    //���� �߰� (5�� �߰�)
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

    printf("\n�����迭 ���\n");
    print_matrix(&G);

    printf("\nDFS Ž�� ���\n");
    int visited[MAX_VERTICES];
    dfs_mat(&G,5, visited);
    return 0;
}
