#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void initGraph(Graph* g, int n) {
  int i, j;
  g->vertex_count = n;

  g->arcs = (int**) malloc(n * sizeof(int*));
  for (i = 0 ; i < g->vertex_count ; i++)
    g->arcs[i] = (int*) malloc(n * sizeof(int));

  for (i = 0 ; i < n ; i++)
    for (j = 0 ; j < n ; j++)
      g->arcs[i][j] = 0;
}

void deleteGraph(Graph* g) {
  free(g);
}

int insertArc(Graph* g, int src, int dest, int weight) {
  if (src >= 0 && src < g->vertex_count && dest >= 0 && dest < g->vertex_count && g->arcs[src][dest] == 0) {
    g->arcs[src][dest] = weight;
    g->arcs[dest][src] = weight;
    return 0;
  }
  return -1;
}

int removeArc(Graph* g, int src, int dest) {
  int weight = -1;
  if (src >= 0 && src < g->vertex_count && dest >= 0 && dest < g->vertex_count && g->arcs[src][dest] > 0) {
    weight = g->arcs[src][dest];
    g->arcs[src][dest] = 0;
    g->arcs[dest][src] = 0;
  }
  return weight;
}

int isArc(Graph* g, int src, int dest) {
  return g->arcs[src][dest] > 0;
}

int* getAdjacentVertices(Graph* g, int v) {
  int* adjacency = (int*) malloc(sizeof(int));
  adjacency[0] = 0; // prima pozitie memoreaza dimensiunea tabloului
  
  int i;
  for (i = 0 ; i < g->vertex_count ; i++) {
    if (g->arcs[i][v] > 0) {
      adjacency[0]++;
      adjacency = (int*) realloc(adjacency, adjacency[0] * sizeof(int));
      adjacency[adjacency[0]] = i;
    }
  }
  return adjacency;
}

void insertVertex(Graph* g, int v) {
  if (g->arcs == NULL) {
    initGraph(g, v); 
  }
  else {
    int i, j;
    g->vertex_count += v;
    g->arcs = (int**) realloc(g->arcs, g->vertex_count * sizeof(int*));
    
    for (i = 0 ; i < g->vertex_count - v ; i++)
      g->arcs[i] = (int*) realloc(g->arcs[i], g->vertex_count * sizeof(int)); // realloc the part of the matrix which were used before

    for ( ; i < g->vertex_count ; i++) 
      g->arcs[i] = (int*) malloc(g->vertex_count * sizeof(int)); // alloc the new part of the matrix

    for (i = 0 ; i < g->vertex_count ; i++) {
      for (j = g->vertex_count - v ; j < g->vertex_count ; j++) {
        g->arcs[i][j] = 0;
        g->arcs[j][i] = 0;
      }
    }
  }
}

int removeVertex(Graph* g, int v) {
  int i, j;

  for (i = 0 ; i < g->vertex_count ; i++)
    for (j = v ; j < g->vertex_count - 1 ; j++) {
      g->arcs[i][j] = g->arcs[i][j + 1];
    }

  for (i = v ; i < g->vertex_count - 1 ; i++)
    for (j = 0 ; j < g->vertex_count ; j++)
      g->arcs[i][j] = g->arcs[i + 1][j];


  g->vertex_count--;

  g->arcs = (int**) realloc(g->arcs, g->vertex_count * sizeof(int*));

  for (i = 0 ; i < g->vertex_count ; i++)
    g->arcs[i] = (int*) realloc(g->arcs[i], g->vertex_count * sizeof(int));
}

void printGraph(Graph* g) {
  int i, j;

  for (i = 0 ; i < g->vertex_count ; i++) {
    for (j = 0 ; j < g->vertex_count ; j++) {
      printf("[%d]", g->arcs[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void printAdjacency(int* a) {
  int i;

  for (i = 1 ; i <= a[0] ; i++)
    printf("[%d]", a[i]);

  printf("\n");
}
