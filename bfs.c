#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int vertexCount;
    struct Node* adjacencyList[MAX_NODES];
};

struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertexCount) {
    struct Graph* newGraph = (struct Graph*)malloc(sizeof(struct Graph));
    newGraph->vertexCount = vertexCount;
    for (int i = 0; i < vertexCount; i++) {
        newGraph->adjacencyList[i] = NULL;
    }
    return newGraph;
}

void addEdge(struct Graph* graph, int startVertex, int endVertex) {
    struct Node* newNode = createNode(endVertex);
    newNode->next = graph->adjacencyList[startVertex];
    graph->adjacencyList[startVertex] = newNode;
    newNode = createNode(startVertex);
    newNode->next = graph->adjacencyList[endVertex];
    graph->adjacencyList[endVertex] = newNode;
}

int detectCycle(struct Graph* graph, int currentVertex, int visited[]) {
    int parent[MAX_NODES];
    for (int i = 0; i < graph->vertexCount; i++) {
        visited[i] = 0;
        parent[i] = -1;
    }
    int queue[MAX_NODES];
    int front = 0, rear = 0;
    queue[rear++] = currentVertex;
    visited[currentVertex] = 1;
    while (front < rear) {
        int u = queue[front++];
        struct Node* temp = graph->adjacencyList[u];
        while (temp != NULL) {
            int v = temp->vertex;
            if (!visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
                parent[v] = u;
            } else if (parent[u] != v) {
                return 1;
            }
            temp = temp->next;
        }
    }
    return 0;
}

int containsCycle(struct Graph* graph) {
    int visited[MAX_NODES] = {0};
    for (int i = 0; i < graph->vertexCount; i++) {
        if (!visited[i]) {
            if (detectCycle(graph, i, visited))
                return 1;
        }
    }
    return 0;
}

int main() {
    int vertexCount, edgeCount;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &vertexCount, &edgeCount);
    struct Graph* graph = createGraph(vertexCount);
    printf("Enter the edges:\n");
    for (int i = 0; i < edgeCount; i++) {
        int source, destination;
        scanf("%d %d", &source, &destination);
        addEdge(graph, source, destination);
    }
    if (containsCycle(graph))
        printf("Graph contains a cycle.\n");
    else
        printf("Graph doesn't contain a cycle.\n");
    return 0;
}
