#include <stdio.h>
#include <stdlib.h>
#define MAX 9
#define V -1
#define U -2

typedef struct node {
    int elem;
    struct node *link;
} nodeType, *nodePtr;

typedef nodePtr Graph[MAX];

typedef struct {
    int elem[MAX];
    int front, back;
} Queue;

void initializeGraph(Graph g);
void initializeMark(int mark[]);
void addEdge(Graph g, int src, int dest);
void bfs(Graph g, int vertex, int marked[]);
void dfs(Graph g, int vertex, int marked[]);

void main(){
    Graph g;
    initializeGraph(g);
    
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 5);
    addEdge(g, 3, 6);
    addEdge(g, 4, 7);
    addEdge(g, 5, 4);
    addEdge(g, 7, 6);
    addEdge(g, 7, 8);
    
    //FOR BFS
    int marked1[MAX];
    initializeMark(marked1);
    
    //FOR DFS
    int marked2[MAX];
    initializeMark(marked2);
    
    printf("Depth First Search: ");
    bfs(g, 0, marked1);
    
    printf("Depth First Search: ");
    dfs(g, 0, marked2);
}

void initializeGraph(Graph g){
    for(int i = 0; i < MAX; ++i){
        g[i] = NULL;
    }
}

void initializeMark(int mark[]){
    for (int i = 0; i < MAX; i++) {
        mark[i] = U;  
    }
}

void addEdge(Graph g, int src, int dest){
    nodePtr newNode = malloc(sizeof(struct node));
    newNode->elem = dest;
    newNode->link = g[src];
    g[src] = newNode;
}

void bfs(Graph g, int vertex, int marked[]){
    Queue q;
    nodePtr trav;
    int curr;
    
    q.front = 0;
    q.back = 0;
    q.elem[q.back] = vertex; 
    
    while((q.back + 1) % MAX != q.front){
        curr = q.elem[q.front];
        q.front = (q.front + 1) % MAX;
        printf("%d ", curr);
        
        for(trav = g[curr]; trav != NULL; trav = trav->link){
            if(marked[trav->elem] == U){
                marked[trav->elem] = V; 
                q.back = (q.back + 1) % MAX;
                q.elem[q.back] = trav->elem;
            }
        }
    }
    printf("\n");
}

void dfs(Graph g, int vertex, int marked[]){
    nodePtr trav; 
    marked[vertex] = V;
    printf("%d ", vertex);
    
    for(trav = g[vertex]; trav != NULL; trav = trav->link){
        if(marked[trav->elem] == U){
            dfs(g, trav->elem, marked);
        }
    }
}