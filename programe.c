#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void sort(int* a, int n) {
    int i,j,tmp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
                if (a[j] > a[i]) {
                    tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                }
            }
        }
}

int main() {
    int T, N, i;
    int noPrograms = 0;
    int currentTime = 0;
    int A[MAX];
    printf("T=");
    scanf("%d", &T);
    printf("N=");
    scanf("%d", &N);
    for(i = 0; i< N; ++i) {
        printf("A[%d]=", i);
        scanf("%d", &A[i]);
    }
    sort(A, N);
    for(i = 0; i< N; ++i) {
        currentTime += A[i];
        if(currentTime > T)
            break;
        noPrograms++;
    }
    printf("NoPrograms=%d\n", noPrograms);
    return 0;
}