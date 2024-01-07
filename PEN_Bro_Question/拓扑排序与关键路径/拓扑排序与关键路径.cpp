#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX_NUM 20

// ��  ��ڵ�
typedef struct ArcNode {  //arc �� 
    int adjvex; // �ڵ�λ�� //adjvex �ڽӵ���
    struct ArcNode* nextarc; // ��һ������ָ��
    int parenvex;
    int weight; // Ȩֵ�����ڹؼ�·��
    char work[20];
  
} ArcNode;

// ����  ��ڵ�
typedef struct VNode {       //vertex ���� 
    char data; // ������Ϣ
    ArcNode* firstarc; // ָ���һ�������ö���Ļ�
} VNode, AdjList[MAX_VERTEX_NUM];//Adjacency List�ڽӱ�

// �ڽӱ�
typedef struct {
    AdjList vertices;//һ������ 
    int vexnum, arcnum; // ͼ�ĵ�ǰ�������ͻ���
} ALGraph;

// ���������������ջ
typedef struct {
    int* data;
    int top; // ջ��ָ��
} Stack;

// ����AOE����
void CreateAOENetwork(ALGraph* G) {
    printf("���붥�����ͱ���:\n");
    scanf("%d %d", &(G->vexnum), &(G->arcnum));

    // ��ʼ������
    for (int i = 0; i < G->vexnum; ++i) {
        printf("�����%d���������Ϣ:\n", i + 1);
        scanf(" %c", &(G->vertices[i].data)); // ע��%cǰ�Ŀո���������ǰ��Ļس�
        G->vertices[i].firstarc = NULL;
    }//���ڽӱ�ĵ�һ��ȫ�����������

    // ��ȡ����Ϣ
    for (int i = 0; i < G->arcnum; ++i) {
        char start, end;
        int weight;
        char workxia[20] = { '\0' };
        printf("����a%d���ߵĻ����:\n", i + 1);
        scanf(" %s", workxia);
        printf("����a%d���ߵ���㡢�յ��Ȩ��:\n", i + 1);
        scanf(" %c %c %d", &start, &end, &weight);

        // ���������յ����������֪����û��������
        int u = -1, v = -1;
        for (int j = 0; j < G->vexnum; ++j) {
            if (G->vertices[j].data == start) u = j;
            if (G->vertices[j].data == end) v = j;
        }

        if (u == -1 || v == -1) {
            printf("��������Ҳ�������\n");
            i--; // ��������������
            continue;
        }

        // ������  ��ڵ�
        ArcNode* arc = (ArcNode*)malloc(sizeof(ArcNode));
        arc->parenvex = u;
        arc->adjvex = v;     //adjvex ��һ���ڵ� 
        strcpy(arc->work, workxia);
        arc->weight = weight;
        // ����ڵ�
        arc->nextarc = G->vertices[u].firstarc;
        G->vertices[u].firstarc = arc;//�����ж���һ���Ķ�����һ����
    }
}


//����ʵ�ֳ���ջ����
// ��ʼ��ջ
void InitStack(Stack* S, int maxSize) {
    S->data = (int*)malloc(sizeof(int) * maxSize);
    S->top = -1;
}

// ��ջ����
void Push(Stack* S, int item) {
    S->data[++S->top] = item;
}

// ��ջ����
int Pop(Stack* S) {
    if (S->top == -1) return -1; // ջ��
    return S->data[S->top--];
}

// ��������
int TopologicalSort(ALGraph G, Stack* T) {
    int count = 0;
    int vexNum = G.vexnum;
    int* inDegree = (int*)calloc(vexNum, sizeof(int));
    Stack S;//�м��� 
    InitStack(&S, vexNum);

    // ����ÿ����������
    for (int i = 0; i < vexNum; ++i) {
        ArcNode* p = G.vertices[i].firstarc;
        while (p) {
            ++inDegree[p->adjvex];
            p = p->nextarc;
        }
    }//ָ���ľ��ж�

    // ���Ϊ0�Ķ�����ջ
    int flag = 0;
    for (int i = 0; i < vexNum; ++i) {
        if (inDegree[i] == 0) {
            Push(&S, i);
            flag++;
        }
    }

    // ��ʼ��ջT
    InitStack(T, vexNum);
    int wanquan[20] = {0};
    while (S.top != -1) {
        //int u;
        //ѹ��ȥ���٣���Ҫ����������
        for (int i = 0; i < flag; i++)
        {
            wanquan[i] = Pop(&S);
            Push(T, wanquan[i]); // �����������������//wanquanʵ��ȫ����ɼ���
            ++count;

        }
        int n = flag;
        flag = 0;
        // ����u�������ڽӵ�v����ÿ��v����ȼ�1
        for (int j = 0; j < n; j++)
        {
            for (ArcNode* p = G.vertices[wanquan[j]].firstarc; p; p = p->nextarc) {
                int v = p->adjvex;
                if (--inDegree[v] == 0) {
                    Push(&S, v);
                    flag++;
                }
            }

        }   
    }

    free(inDegree);

    if (count < vexNum) {
        return 0; // ���ڻ�
    }
    return 1; // �ɹ������������
}

// �ؼ�·���㷨
void CriticalPath(ALGraph G) {
    Stack T;
    InitStack(&T, G.vexnum);
    if (!TopologicalSort(G, &T)) {
        printf("ͼ���л��������ڹؼ�·��\n");
        return;
    }

    int vexNum = G.vexnum;
    int* ve = (int*)calloc(vexNum, sizeof(int)); // ���翪ʼʱ��
    int* vl = (int*)calloc(vexNum, sizeof(int));// ��ٿ�ʼʱ��

    for (int i = 0; i < vexNum; ++i) {
        vl[i] = INT_MAX;
    }

    // ����ve
    for (int i = 0; i < vexNum; ++i) {
        int u = T.data[i];
        for (ArcNode* p = G.vertices[u].firstarc; p; p = p->nextarc) {
            int v = p->adjvex;
            if (ve[u] + p->weight > ve[v]) {
                ve[v] = ve[u] + p->weight;//����ÿ������u������u���������л�(u,v)�������¶���v�����翪ʼʱ��Ϊmax(ve[v], ve[u] + weight)
            }
        }
    }

    // ��ʼ��vlΪve�����ֵ
    vl[vexNum - 1] = ve[vexNum - 1];

    // ����vl
    for (int i = vexNum - 1; i >= 0; --i) {
        int u = T.data[i];
        for (ArcNode* p = G.vertices[u].firstarc; p; p = p->nextarc) {
            int v = p->adjvex;
            if (vl[v] - p->weight < vl[u]) {
                vl[u] = vl[v] - p->weight;//����ÿ������u������u���������л�(u,v)�������¶���u����ٿ�ʼʱ��Ϊmin(vl[u], vl[v] - weight)
            }
        }
    }
    printf("�ؼ�·����");
    printf("\n");
    // Ѱ�ҹؼ�·���ϵĻ
    int i = 0;
    for (int u = 0; u < vexNum; ++u) {
        for (ArcNode* p = G.vertices[u].firstarc; p; p = p->nextarc) {
            int v = p->adjvex;
            int e = ve[u];
            int l = vl[v] - p->weight;
            // ���e == l����û�ǹؼ��

            if (e == l) {
                //  printf("%c->%c ", G.vertices[u].data, G.vertices[v].data);
                printf("%s  ", p->work);
            }
        }
    }

//
    printf("\n�ؼ�·�����ȣ�%d\n", ve[vexNum - 1]);

    free(ve);//�ͷ� 
    free(vl);
}
int main() {
    ALGraph G;
   
    CreateAOENetwork(&G); // ����AOE����

    CriticalPath(G); // Ѱ�ҹؼ�·��
    
    return 0;
}
