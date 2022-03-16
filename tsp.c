#include <stdio.h>
#include <stdlib.h>



// Function to find the minimum cost path for all the paths
void findMinRoute(int tsp[4][4], int n, int start)
{
    int sum = 0;
    int counter = 0;
    int i, j = 0;
    int min = INT_MAX;
    int visitedRouteList[n];
    int route[n];

    for(i = 0; i < n; i++) {
        visitedRouteList[i] = 0;
        route[i] = 0;
    }
    i = start;
    visitedRouteList[i] = 1;
    while(i < n && j < n) {
        if(counter >= n - 1)
                break;

        if (j != i && (visitedRouteList[j] == 0))
        {
                if (tsp[i][j] < min)
                {
                    min = tsp[i][j];
                    route[counter] = j;
                }
        }
        j++;

        if(j == n) {
            sum +=min;
            min = INT_MAX;
            visitedRouteList[route[counter]]=1;
            j = 0;
            i = route[counter];
            counter++;
        }
    }

    //back to the starting point
    i = route[counter-1];
    j = start;
    sum += tsp[i][j];
    route[counter] = j;

    //print route
    printf("\n");
    printf("%d ", start);
    for(i = 0; i<n; i++)
        printf("%d ", route[i]);

    printf("\n");
    printf("%d ", sum);
}

// Driver Code
int main()
{
    // Input Matrix
    int tsp[4][4] = { { -1, 10, 15, 20 },
                    { 10, -1, 35, 25 },
                    { 15, 35, -1, 30 },
                    { 20, 25, 30, -1 } };

    // Function Call
    findMinRoute(tsp, 4, 0);
}
