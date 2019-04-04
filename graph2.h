#ifndef _GRAPH2_H
#define _GRAPH2_H

struct adjListNode { 
    int dest; 
    struct adjListNode* next; 
}; 

typedef struct adjListNode Node;

// Lista de adiacenta
struct adjList { 
    Node *head;  
}; 

typedef struct adjList List;
  
// graful : V este numarul de noduri, array este un tablou cu liste de adiacenta 
struct graph { 
    int V; 
    List* array; 
}; 

typedef struct graph Graph;
  
// Creaza un nod nou  
Node* newAdjListNode(int dest); 
  
// Creaza un graf cu V noduri 
Graph* createGraph(int V); 
  
// Adauga un arc la graf 
void addEdge(Graph* graph, int src, int dest);
  
// Afiseaza graful
void printGraph(Graph* graph); 
  
#endif
