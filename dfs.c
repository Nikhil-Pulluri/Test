#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Struct to represent a node in the adjacency list
struct Node {
  int vertex;  // Vertex represented by the node
  struct Node* next;  // Pointer to the next node in the adjacency list
};

// Struct to represent a graph as an adjacency list
struct Graph {
  int numVertices;  // Number of vertices in the graph
  struct Node* adjacencyList[MAX_VERTICES];  // Array of adjacency lists for each vertex
};

// Function to create a new node
struct Node* createNode(int vertex) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->vertex = vertex;
  newNode->next = NULL;
  return newNode;
}

// Function to initialize a graph with a given number of vertices
struct Graph* initializeGraph(int numVertices) {
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->numVertices = numVertices;

  // Initialize all adjacency lists to NULL
  for (int i = 0; i < numVertices; ++i) {
    graph->adjacencyList[i] = NULL;
  }

  return graph;
}

// Function to add an edge to the graph (directed)
void addEdge(struct Graph* graph, int source, int destination) {
  // Create a new node for the destination vertex
  struct Node* newNode = createNode(destination);

  // Add the node to the beginning of the source vertex's adjacency list
  newNode->next = graph->adjacencyList[source];
  graph->adjacencyList[source] = newNode;
}

// Function to perform a Depth-First Search (DFS) to detect cycles
int hasCycleUtil(struct Graph* graph, int vertex, int visited[], int recursionStack[]) {
  if (recursionStack[vertex]) {
    return 1;  // Cycle detected (vertex is in recursion stack)
  }

  if (visited[vertex]) {
    return 0;  // Vertex already visited (no cycle)
  }

  visited[vertex] = 1;  // Mark the current vertex as visited
  recursionStack[vertex] = 1;  // Push the vertex onto the recursion stack

  // Recur for all neighbors of the current vertex
  struct Node* adjacentNode = graph->adjacencyList[vertex];
  while (adjacentNode) {
    if (hasCycleUtil(graph, adjacentNode->vertex, visited, recursionStack)) {
      return 1;  // Cycle found in a sub-graph
    }
    adjacentNode = adjacentNode->next;
  }

  // Pop the vertex from the recursion stack when all its adjacent vertices are explored
  recursionStack[vertex] = 0;

  return 0;  // No cycle found
}

// Function to detect cycle in the graph (wrapper for hasCycleUtil)
int detectCycle(struct Graph* graph) {
  int visited[MAX_VERTICES] = {0}; // Array to keep track of visited vertices
  int recursionStack[MAX_VERTICES] = {0}; // Stack to keep track of vertices in the current DFS path

  // Perform DFS traversal from each unvisited vertex
  for (int i = 0; i < graph->numVertices; ++i) {
    if (!visited[i]) {
      if (hasCycleUtil(graph, i, visited, recursionStack)) {
        return 1;  // Cycle found
      }
    }
  }

  return 0;  // No cycle found
}

int main() {
  int numVertices, numEdges;
  printf("Enter the number of vertices and edges: ");
  scanf("%d %d", &numVertices, &numEdges);

  struct Graph* graph = initializeGraph(numVertices);

  printf("Enter the edges (source and destination): \n");
  for (int i = 0; i < numEdges; ++i) {
    int source, destination;
    scanf("%d %d", &source, &destination);
    addEdge(graph, source, destination);
  }

  if (detectCycle(graph)) {
    printf("Graph contains a cycle.\n");
  } else {
    printf("Graph does not contain a cycle.\n");
  }

  return 0;
}
