#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 50

//�׷��� ����(���)
typedef struct
{
    int vertex;//����
    struct GraphNode *link; //����Ǿ��ִ� ����..
}GraphNode;

//�׷��� ����
typedef struct
{
    int n; //������ ����

    //������ adj_list�� ���ҵ��� GraphNode�� ����Ų��..
    GraphNode *adj_list[MAX_VERTICES]; //�׷��� ���� ����Ʈ: GraphNode ������ �迭

}GraphType;

//�׷��� �ʱ�ȭ
void graph_init(GraphType *g)
{
    //������ ���� 0��
    g->n=0;

    //��������Ʈ�� ��������
    for(int v=0; v<MAX_VERTICES; v++)
        g->adj_list[v]=NULL;//�ƹ��͵� ����Ű�� �����ɷ� �ʱ�ȭ
}

//���� ���� ����
void insert_vertex(GraphType *g, int v)
{
    //���� �����ߴµ� MAX_VERTICES�� �Ѵ´ٸ� -> �����޽��� ����ϰ� ����
    if( (g->n)+1 > MAX_VERTICES){
        fprintf(stderr, "�������� �ʰ�");exit(1);
    }
    g->n++; //��������(n) ī��Ʈ
}

//���� ���� ����: v�� u�� ��������Ʈ�� �����Ѵ�..
void insert_edge(GraphType *g, int u, int v)
{
    //������: u (u< g->n)  **g->n�� �׷��� ����� ����..
    //u�� �������: v (v< g->n)
    if( u>=(g->n) || v>=(g->n)){
        fprintf(stderr, "�׷��� ���� ��ȣ ����");
        exit(1);
    }

    //��� ����..
    //�׷��� ���(����)�� ����Ű�� ������ ����.. node�� GraphNode ����ü�� ������..
    GraphNode * node=(GraphNode *)malloc(sizeof(GraphNode));
    //��� �ʱ�ȭ
    node->vertex=v;
    node->link = g->adj_list[u];
    g->adj_list[u]=node;

    //������..
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
        printf("���� %d", u);
        while(now){
            printf("-> %d", now->vertex);
            now=now->link;
        }
        printf("\n");
    }
}


int main(void)
{
    //��������Ʈ �׷����� ����
    GraphType G;

    //��������Ʈ �׷��� �ʱ�ȭ
    graph_init(&G);

    //����5���� �����Ѵ�.
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
