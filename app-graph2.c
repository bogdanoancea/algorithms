#include "graph2.h"

int main() { 
    int V = 5; 
    Graph* graph = createGraph(V); 
    addEdge(graph, 0, 1); 
    addEdge(graph, 0, 4); 
    addEdge(graph, 1, 2); 
    addEdge(graph, 1, 3); 
    addEdge(graph, 1, 4); 
    addEdge(graph, 2, 3); 
    addEdge(graph, 3, 4); 
  
    // afiseaza graful 
    printGraph(graph); 
  
    return 0; 
} 

