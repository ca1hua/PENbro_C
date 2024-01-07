#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX_NUM 20

// 边  表节点
typedef struct ArcNode {  //arc 弧 
    int adjvex; // 节点位置 //adjvex 邻接点域
    struct ArcNode* nextarc; // 下一条弧的指针
    int parenvex;
    int weight; // 权值，用于关键路径
    char work[20];
  
} ArcNode;

// 顶点  表节点
typedef struct VNode {       //vertex 顶点 
    char data; // 顶点信息
    ArcNode* firstarc; // 指向第一条依附该顶点的弧
} VNode, AdjList[MAX_VERTEX_NUM];//Adjacency List邻接表

// 邻接表
typedef struct {
    AdjList vertices;//一串顶点 
    int vexnum, arcnum; // 图的当前顶点数和弧数
} ALGraph;

// 存放拓扑排序结果的栈
typedef struct {
    int* data;
    int top; // 栈顶指针
} Stack;

// 创建AOE网络
void CreateAOENetwork(ALGraph* G) {
    printf("输入顶点数和边数:\n");
    scanf("%d %d", &(G->vexnum), &(G->arcnum));

    // 初始化顶点
    for (int i = 0; i < G->vexnum; ++i) {
        printf("输入第%d个顶点的信息:\n", i + 1);
        scanf(" %c", &(G->vertices[i].data)); // 注意%c前的空格，用于吸收前面的回车
        G->vertices[i].firstarc = NULL;
    }//把邻接表的第一个全部都定义好了

    // 读取边信息
    for (int i = 0; i < G->arcnum; ++i) {
        char start, end;
        int weight;
        char workxia[20] = { '\0' };
        printf("输入a%d条边的活动名称:\n", i + 1);
        scanf(" %s", workxia);
        printf("输入a%d条边的起点、终点和权重:\n", i + 1);
        scanf(" %c %c %d", &start, &end, &weight);

        // 查找起点和终点的索引，即知道有没有这条边
        int u = -1, v = -1;
        for (int j = 0; j < G->vexnum; ++j) {
            if (G->vertices[j].data == start) u = j;
            if (G->vertices[j].data == end) v = j;
        }

        if (u == -1 || v == -1) {
            printf("输入错误，找不到顶点\n");
            i--; // 重新输入这条边
            continue;
        }

        // 创建边  表节点
        ArcNode* arc = (ArcNode*)malloc(sizeof(ArcNode));
        arc->parenvex = u;
        arc->adjvex = v;     //adjvex 下一个节点 
        strcpy(arc->work, workxia);
        arc->weight = weight;
        // 插入节点
        arc->nextarc = G->vertices[u].firstarc;
        G->vertices[u].firstarc = arc;//把所有顶点一样的都串在一起了
    }
}


//下面实现常规栈操作
// 初始化栈
void InitStack(Stack* S, int maxSize) {
    S->data = (int*)malloc(sizeof(int) * maxSize);
    S->top = -1;
}

// 入栈操作
void Push(Stack* S, int item) {
    S->data[++S->top] = item;
}

// 出栈操作
int Pop(Stack* S) {
    if (S->top == -1) return -1; // 栈空
    return S->data[S->top--];
}

// 拓扑排序
int TopologicalSort(ALGraph G, Stack* T) {
    int count = 0;
    int vexNum = G.vexnum;
    int* inDegree = (int*)calloc(vexNum, sizeof(int));
    Stack S;//中间人 
    InitStack(&S, vexNum);

    // 计算每个顶点的入度
    for (int i = 0; i < vexNum; ++i) {
        ArcNode* p = G.vertices[i].firstarc;
        while (p) {
            ++inDegree[p->adjvex];
            p = p->nextarc;
        }
    }//指到的就有度

    // 入度为0的顶点入栈
    int flag = 0;
    for (int i = 0; i < vexNum; ++i) {
        if (inDegree[i] == 0) {
            Push(&S, i);
            flag++;
        }
    }

    // 初始化栈T
    InitStack(T, vexNum);
    int wanquan[20] = {0};
    while (S.top != -1) {
        //int u;
        //压进去多少，我要弹出来多少
        for (int i = 0; i < flag; i++)
        {
            wanquan[i] = Pop(&S);
            Push(T, wanquan[i]); // 将顶点加入拓扑序列//wanquan实现全部完成减度
            ++count;

        }
        int n = flag;
        flag = 0;
        // 遍历u的所有邻接点v，对每个v的入度减1
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
        return 0; // 存在环
    }
    return 1; // 成功完成拓扑排序
}

// 关键路径算法
void CriticalPath(ALGraph G) {
    Stack T;
    InitStack(&T, G.vexnum);
    if (!TopologicalSort(G, &T)) {
        printf("图中有环，不存在关键路径\n");
        return;
    }

    int vexNum = G.vexnum;
    int* ve = (int*)calloc(vexNum, sizeof(int)); // 最早开始时间
    int* vl = (int*)calloc(vexNum, sizeof(int));// 最迟开始时间

    for (int i = 0; i < vexNum; ++i) {
        vl[i] = INT_MAX;
    }

    // 计算ve
    for (int i = 0; i < vexNum; ++i) {
        int u = T.data[i];
        for (ArcNode* p = G.vertices[u].firstarc; p; p = p->nextarc) {
            int v = p->adjvex;
            if (ve[u] + p->weight > ve[v]) {
                ve[v] = ve[u] + p->weight;//对于每个顶点u，检查从u出发的所有弧(u,v)，并更新顶点v的最早开始时间为max(ve[v], ve[u] + weight)
            }
        }
    }

    // 初始化vl为ve的最大值
    vl[vexNum - 1] = ve[vexNum - 1];

    // 计算vl
    for (int i = vexNum - 1; i >= 0; --i) {
        int u = T.data[i];
        for (ArcNode* p = G.vertices[u].firstarc; p; p = p->nextarc) {
            int v = p->adjvex;
            if (vl[v] - p->weight < vl[u]) {
                vl[u] = vl[v] - p->weight;//对于每个顶点u，检查从u出发的所有弧(u,v)，并更新顶点u的最迟开始时间为min(vl[u], vl[v] - weight)
            }
        }
    }
    printf("关键路径：");
    printf("\n");
    // 寻找关键路径上的活动
    int i = 0;
    for (int u = 0; u < vexNum; ++u) {
        for (ArcNode* p = G.vertices[u].firstarc; p; p = p->nextarc) {
            int v = p->adjvex;
            int e = ve[u];
            int l = vl[v] - p->weight;
            // 如果e == l，则该活动是关键活动

            if (e == l) {
                //  printf("%c->%c ", G.vertices[u].data, G.vertices[v].data);
                printf("%s  ", p->work);
            }
        }
    }

//
    printf("\n关键路径长度：%d\n", ve[vexNum - 1]);

    free(ve);//释放 
    free(vl);
}
int main() {
    ALGraph G;
   
    CreateAOENetwork(&G); // 创建AOE网络

    CriticalPath(G); // 寻找关键路径
    
    return 0;
}
