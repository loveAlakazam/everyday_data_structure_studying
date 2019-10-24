//��������� �̿��� �׷��� �߻����� Ÿ���� �ӱ���
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 50 //�׷��� ���� �ִ밳�� 50��
typedef struct
{
    int n; //������ ����
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;


//�׷��� �ʱ�ȭ: �������
void graph_init(GraphType* g)
{
    int row, col; //��������� ��� ��
    g->n=0; //�׷����� ������ ������ 0���� �Ѵ�.

    //�� �����鰣�� ������ 0�����Ѵ�(����Ǿ����� ����)���� �ʱ�ȭ
    for(int r=0; r<MAX_VERTICES; r++){
        for(int c=0; c<MAX_VERTICES; c++)
            g->adj_mat[r][c]=0;
    }
}

//���� ���Կ���
void insert_vertex(GraphType *g, int v)
{
    //������ ������ ������ MAX_VERTICES���� ũ�ٸ�-> �����޽����� ����ϰ� ����
    if( (g->n)+1 > MAX_VERTICES){
        fprintf(stderr, "�׷��� �������� �ʰ�");
        exit(1);
    }

    g->n++;//�������� �߰�
}

//���� ���Կ���
void insert_edge(GraphType *g, int start, int end)
{
    //start: ��������   (��������<�׷��� ��������)
    //end: ��������     (��������<�׷��� ��������)
    if(start>= g->n || end>= g->n)
    {//����
        fprintf(stderr,"�׷��� ���� ��ȣ ����");
        exit(1);
    }

    //����׷���
    g->adj_mat[start][end]=1;
    g->adj_mat[end][start]=1;
}

int main(void)
{
    GraphType G; //�׷��� ����..

    //�׷����� �ʱ�ȭ�Ѵ�.
    graph_init(&G);

    //������ �߰��Ѵ�.
    for(int i=1;i<=10;i++)
        insert_vertex(&G,i);

    //���� �߰��Ѵ�.
    insert_edge(&G, 1,2);
    insert_edge(&G, 1,3);
    insert_edge(&G, 1,9);
    insert_edge(&G, 2,4);
    insert_edge(&G, 3,6);
    insert_edge(&G, 7,8);
    insert_edge(&G, 9,6);
    insert_edge(&G, 6,4);

    printf("���� ��������: %d��\n", G.n);
    printf("������ �׷����� �������(adjacency matrix)\n");
    for(int r=0; r<G.n; r++){
        for(int c=0; c<G.n; c++)
            printf("%5d", G.adj_mat[r][c]);
        printf("\n");
    }
}
