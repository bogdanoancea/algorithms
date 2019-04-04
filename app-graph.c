#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

#define INSERT_VERTEX 1
#define REMOVE_VERTEX 2
#define INSERT_ARC 3
#define REMOVE_ARC 4
#define VERTEX_ADJACENCY 5
#define PRINT_GRAPH 6
#define EXIT 0

void menu() {
  
  printf("[1] Inserati un nod\n");
  printf("[2] Stergeti un nod\n");
  printf("[3] Inserati un arc\n");
  printf("[4] Stergeti un arc\n");
  printf("[5] Obtineti nodurile adiacente\n");
  printf("[6] Tipariti graful\n");
  printf("[0] Exit\n");
  printf("Optiunea dvs:");
}

int main(int argc, char* argv[]) {
  Graph* g = (Graph*) malloc(sizeof(Graph));
  g->vertex_count = 0;
  g->arcs = NULL;
  int* adjacency;
  int option, v, src, dest;

  do {
    menu();
    scanf("%d", &option);
    switch (option) {
      case INSERT_VERTEX:
        printf("Cate noduri doriti sa introduceti? ");
        scanf("%d", &v);
        insertVertex(g, v);
        break;
      case REMOVE_VERTEX:
        printf("Care nod doriti sa il stergeti? ");
        scanf("%d", &v);
        removeVertex(g, v);
        break;
      case INSERT_ARC:
        printf("Primul nod: ");
        scanf("%d", &src);
        printf("Al doilea nod: ");
        scanf("%d", &dest);
        insertArc(g, src, dest, 1);
        break;
      case REMOVE_ARC:
        printf("Primul nod: ");
        scanf("%d", &src);
        printf("Al doilea nod: ");
        scanf("%d", &dest);
        removeArc(g, src, dest);
        break;
      case VERTEX_ADJACENCY:
        printf("Pentru care nod doriti sa verificati adiacenta?");
        scanf("%d", &v);
        adjacency = getAdjacentVertices(g, v);
        printAdjacency(adjacency);
        free(adjacency);
        break;
      case PRINT_GRAPH: 
        printGraph(g);
        break;
    }
  } while (option != EXIT);

  return 0;
}
