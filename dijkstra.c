#include <stdio.h>
#include <limits.h>

#define GRAPHSIZE 2048
#define INFINITY INT_MAX
#define MAX(a, b) ((a > b) ? (a) : (b))

int e; /* The number of nonzero edges in the graph */
int n; /* The number of nodes in the graph */
long dist[GRAPHSIZE][GRAPHSIZE]; /* dist[i][j] is the distance between node i and j; or 0 if there is no direct connection */
long d[GRAPHSIZE]; /* d[i] is the length of the shortest path between the source (s) and node i */
int prev[GRAPHSIZE]; /* prev[i] is the node that comes right before i in the shortest path from the source to i*/

void printD() {
	int i;

	printf("Distances:\n");
	for (i = 1; i <= n; ++i)
		printf("%10d", i);
	printf("\n");
	for (i = 1; i <= n; ++i) {
		printf("%10ld", d[i]);
	}
	printf("\n");
}

/*
 * Prints the shortest path from the source to dest.
 *
 * dijkstra(int) MUST be run at least once BEFORE
 * this is called
 */
void printPath(int dest) {
	if (prev[dest] != -1)
		printPath(prev[dest]);
	printf("%d ", dest);
}

void dijkstra(int s) {
	int i, k, mini;
	int visited[GRAPHSIZE];

	for (i = 1; i <= n; ++i) {
		d[i] = INFINITY;
		prev[i] = -1; /* no path has yet been found to i */
		visited[i] = 0; /* the i-th element has not yet been visited */
	}

	d[s] = 0;

	for (k = 1; k <= n; ++k) {
		mini = -1;
		for (i = 1; i <= n; ++i)
			if (!visited[i] && ((mini == -1) || (d[i] < d[mini])))
				mini = i;

		visited[mini] = 1;

		for (i = 1; i <= n; ++i)
			if (dist[mini][i])
				if (d[mini] + dist[mini][i] < d[i]) {
					d[i] = d[mini] + dist[mini][i];
					prev[i] = mini;
				}
	}
}

int main(int argc, char *argv[]) {
	int i, j;
	int u, v, w;

	FILE *fin = fopen("dijkstra.txt", "r");
	fscanf(fin, "%d", &e);
	for (i = 0; i < e; ++i)
		for (j = 0; j < e; ++j)
			dist[i][j] = 0;
	n = -1;
	for (i = 0; i < e; ++i) {
		fscanf(fin, "%d%d%d", &u, &v, &w);
		dist[u][v] = w;
		n = MAX(u, MAX(v, n));
	}
	fclose(fin);

	dijkstra(1);

	printD();

	printf("\n");
	for (i = 1; i <= n; ++i) {
		printf("Path to %d: ", i);
		printPath(i);
		printf("\n");
	}

	return 0;
}