#include "graph2.h"
#include <stdio.h>
#include <stdlib.h>


Node* newAdjListNode(int dest)  { 
    Node* newNode = (Node*) malloc(sizeof(Node)); 
    newNode->dest = dest; 
    newNode->next = NULL; 
    return newNode; 
} 
  
//creaza un graf cu V noduri
Graph* createGraph(int V) { 
    Graph* graph = (Graph*) malloc(sizeof(Graph)); 
    graph->V = V; 
  
    // creaza un tablou cu listele de adiacenta. Dimensiunea tabloului este V
    graph->array = (List*) malloc(V * sizeof(List)); 
  
    // listele de adiacenta sunt initializate, head = NULL
    int i; 
    for (i = 0; i < V; ++i) 
        graph->array[i].head = NULL; 

    return graph; 
} 
  
// adauga un arc 
void addEdge(Graph* graph, int src, int dest)  {
	// adauga un arc de la src la dest. Un nod nou este de asemenea adaugat la lista de adiacenta a lui src
    Node* newNode = newAdjListNode(dest); 
    newNode->next = graph->array[src].head; 
    graph->array[src].head = newNode; 
  
    // adaug un arc de la dest la src (graful este neorientat)
    newNode = newAdjListNode(src); 
    newNode->next = graph->array[dest].head; 
    graph->array[dest].head = newNode; 
} 
  
// afiseaza graful
void printGraph(Graph* graph) { 
    int v; 
    for (v = 0; v < graph->V; ++v) { 
        Node* p = graph->array[v].head; 
        printf("\n Lista de adiacenta a nodului %d\n", v); 
        while (p) { 
            printf("-> %d", p->dest); 
            p = p->next; 
        } 
        printf("\n"); 
    } 
} 
