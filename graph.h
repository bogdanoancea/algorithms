#ifndef _GRAPH_H
#define _GRAPH_H

struct graph{
  int vertex_count;
  int** arcs; // 0 represents the lack of adjacency
};

typedef struct graph Graph;

void initGraph(Graph* g, int v);

void deleteGraph(Graph* g);

int insertArc(Graph* g, int src, int dest, int weight);

int removeArc(Graph* g, int src, int dest);

int isArc(Graph* g, int src, int dest);

int* getAdjacentVertices(Graph* g, int src);

void insertVertex(Graph* g, int v);

int removeVertex(Graph* g, int v);

void printGraph(Graph* g);

void printAdjacency(int* a);

#endif
