#include <stdio.h>
#include <stdlib.h>

#define GRAPHSIZE 1024
#define INFINITY 200000

typedef struct {
	int u, v, w;
} Edge;

/**
* Nodes will indexed with 0, 1, 2, ... n-1
**/
int n; /* the number of nodes */
int e; /* the number of edges */
Edge edges[GRAPHSIZE];
int d[GRAPHSIZE]; /* d[i] is the minimum distance from node s to node i */
int prev[GRAPHSIZE]; /*prev[i] is the node that comes right before i in the shortest path from the source to i*/


void printPath(int dest) {
	if (prev[dest] != -1)
		printPath(prev[dest]);
	printf("%d ", dest);
}

void printDist(int source) {
	int i;

	printf("Distances from %d to:\n", source);

	for (i = 0; i < n; ++i)
		printf("%d\t", i);
	printf("\n");

	for (i = 0; i < n; ++i)
		printf("%d\t", d[i]);

	printf("\n\n");
}

void bellman_ford(int s) {
	int i, j;

	for (i = 0; i < n; ++i) {
		d[i] = INFINITY;
		prev[i] = -1;
	}

	d[s] = 0;

	for (i = 0; i < n - 1; ++i)
		for (j = 0; j < e; ++j) {
			if (d[edges[j].u] + edges[j].w < d[edges[j].v]) {
				d[edges[j].v] = d[edges[j].u] + edges[j].w;
				prev[edges[j].v] = edges[j].u;
			}
		}
}


int main(int argc, char *argv[]) {
	int i, j;
	int w;
    int source;
	FILE *fin = fopen("bellman-ford.txt", "r");
	if(fin == NULL) {
        printf("bellman-ford.txt file cannot be open\n");
        exit(1);
	}
	fscanf(fin, "%d", &n);
	e = 0;

	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j) {
			fscanf(fin, "%d", &w);
			if (w != 0) {
				edges[e].u = i;
				edges[e].v = j;
				edges[e].w = w;
				++e;
			}
		}
	//print each edge of the graph
	for(i = 0; i < e; i++)	 {
        printf("Edge: %d-%d:%d\n", edges[i].u, edges[i].v, edges[i].w);
	}
	fclose(fin);

    printf("Enter source node:");
    scanf("%d", &source);
    while(source > n || source < 0) {
        printf("Enter source node:");
        scanf("%d", &source);
    }

	bellman_ford(source);

	printDist(source);

    printf("\n");

	for (i = 0; i < n; ++i) {
		printf("Path to %d: ", i);
		printPath(i);
		printf("\n");
	}

	return 0;
}
