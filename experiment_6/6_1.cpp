//
// Created by jimya on 2020/12/9.
//
#include <iostream>

using namespace std;
//队列相关操作
#define MAXSIZE 100
typedef struct {
    int data[MAXSIZE];
    int front, rear;
} SqQueue;

void InitQueue(SqQueue *&q) {
    q = new SqQueue;
    q->front = q->rear = -1;
}

void DestroyQueue(SqQueue *&q) {
    delete q;
}

bool QueueEmpty(SqQueue *q) {
    return (q->front == q->rear);
}

bool enQueue(SqQueue *&q, int e) {
    if ((q->rear + 1) % MAXSIZE == q->front)
        return false;
    q->rear = (q->rear + 1) % MAXSIZE;
    q->data[q->rear] = e;
    return true;
}

bool deQueue(SqQueue *&q, int &e) {
    if (q->front == q->rear)
        return false;
    q->front = (q->front + 1) % MAXSIZE;
    e = q->data[q->front];
    return true;
}

//带权图的邻接矩阵与邻接表的创建和输出运算 建立有向图的邻接矩阵 并输出
#define MAXV 6  //最大顶点数
#define MAX 6
typedef char InfoType;
#define INF 32767  //定义∞
typedef struct {
    int no;
    InfoType info;
} VertexType;
typedef struct {
    int edges[MAXV][MAXV];
    int n, e;
    VertexType vexs[MAXV];
} MatGraph;


typedef struct ANode {
    int adjvex;
    struct ANode *nextarc;
    int weight;
} ArcNode;

typedef struct Vnode {
    InfoType info;
    ArcNode *firstarc;
} VNode;
typedef struct {
    VNode adjlist[MAXV];
    int n, e;
} AdjGraph;


void CreateAdj(AdjGraph *&G, int A[MAXV][MAXV], int n, int e) {
    int i, j;
    ArcNode *p;
    G = new AdjGraph;
    for (i = 0; i < n; i++) {
        G->adjlist[i].firstarc = NULL;
    }
    for (i = 0; i < n; i++) {
        for (j = n - 1; j >= 0; j--) {
            if (A[i][j] != 0 && A[i][j] != INF) {
                p = new ArcNode;
                p->adjvex = j;
                p->weight = A[i][j];
                p->nextarc = G->adjlist[i].firstarc;
                G->adjlist[i].firstarc = p;
            }
        }
    }
    G->n = n;
    G->e = e;
}

void DisplayAdi(AdjGraph *G) {
    int i;
    ArcNode *p;
    for (i = 0; i < G->n; i++) {
        p = G->adjlist[i].firstarc;
        printf("%3d:", i);
        while (p != NULL) {
            printf("%3d[%d]->", p->adjvex, p->weight);
            p = p->nextarc;
        }
        printf("^\n");
    }
}
//建立有向图的邻接表 并输出

void DestroyAdj(AdjGraph *&G) {
    int i;
    ArcNode *pre, *p;
    for (i = 0; i < G->n; i++) {
        pre = G->adjlist[i].firstarc;
        if (pre != NULL) {
            p = pre->nextarc;
            while (p != NULL) {
                delete pre;
                pre = p;
                p = p->nextarc;
            }
            delete pre;
        }
    }
    delete G;
}


//深度优先遍历
int visited[MAX] = {0};

void DFS(AdjGraph *G, int v) {
    ArcNode *p;
    visited[v] = 1;
    printf("%d ", v);
    p = G->adjlist[v].firstarc;
    while (p != NULL) {
        if (visited[p->adjvex] == 0)
            DFS(G, p->adjvex);
        p = p->nextarc;
    }
}


//广度优先
void BFS(AdjGraph *G, int v) {
    int w, i;
    ArcNode *p;
    SqQueue *qu;
    InitQueue(qu);
    int visited[MAXV];
    for (i = 0; i < G->n; i++)
        visited[i] = 0;
    printf("%2d", v);
    visited[v] = 1;
    enQueue(qu, v);
    while (!QueueEmpty(qu)) {
        deQueue(qu, w);
        p = G->adjlist[w].firstarc;
        while (p != NULL) {
            if (visited[p->adjvex] == 0) {
                printf("%2d", p->adjvex);
                visited[p->adjvex] = 1;
                enQueue(qu, p->adjvex);
            }
            p = p->nextarc;
        }
    }
    printf("\n");
}


int main() {
    cout<<"Init Adjacency matrix"<<endl;
    int A[MAXV][MAXV] = {
            {0,   5,   INF, 7,   INF, INF},
            {INF, 0,   4,   INF, INF, INF},
            {8,   INF, 0,   INF, INF, 9},
            {INF, INF, 5,   0,   INF, 6},
            {INF, INF, INF, 5,   0,   INF},
            {3,   INF, INF, INF, 1,   0}};
    cout<<endl;
    cout<<"Display Adjacency matrix"<<endl;
    for (int i = 0; i < MAXV; i++) {
        for (int j = 0; j < MAXV; j++) {
            if(A[i][j]==INF) {
//                printf("%3c", '∞');
                cout<<"∞ ";
            }
            else
                printf("%d ", A[i][j]);
        }
        cout << endl;
    }
    cout<<endl;
    int n = 6;
    int e = 10;
    AdjGraph *G;
    cout<<"set adjacency list"<<endl;
    CreateAdj(G, A, n, e);
    cout<<endl;
    cout<<"Display adjacency list"<<endl;
    DisplayAdi(G);
    cout<<endl;
    cout<<"Depth first traversal"<<endl;
    DFS(G, 0);
    cout <<"\n"<<endl;

    cout<<"Breadth first traversal"<<endl;
    BFS(G, 0);
    cout<<endl;
    cout<<"Destroy adjacency list"<<endl;
    DestroyAdj(G);
    return 0;
}
