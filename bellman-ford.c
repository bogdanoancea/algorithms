#include <stdio.h>
#include <limits.h>


#define GRAPHSIZE 1024
#define INFINITY INT_MAX

typedef struct {
	int u, v, w;
} Edge;

int n; /* the number of nodes */
int e; /* the number of edges */
Edge edges[GRAPHSIZE];
int d[GRAPHSIZE]; /* d[i] is the minimum distance from node s to node i */


void printDist() {
	int i;

	printf("Distances to:\n");

	for (i = 0; i < n; ++i)
		printf("%d\t", i + 1);
	printf("\n");

	for (i = 0; i < n; ++i)
		printf("%d\t", d[i]);

	printf("\n\n");
}

void bellman_ford(int s) {
	int i, j;

	for (i = 0; i < n; ++i)
		d[i] = INFINITY;

	d[s] = 0;

	for (i = 0; i < n - 1; ++i)
		for (j = 0; j < e; ++j)
			if (d[edges[j].u] + edges[j].w < d[edges[j].v])
				d[edges[j].v] = d[edges[j].u] + edges[j].w;
}

int main(int argc, char *argv[]) {
	int i, j;
	int w;

	FILE *fin = fopen("bellman-ford.txt", "r");
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
	fclose(fin);

	/* printDist(); */

	bellman_ford(0);

	printDist();

	return 0;
}