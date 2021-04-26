#include<stdio.h>
#include<stdlib.h>

int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

int compare(const void *a, const void *b) {
    int *p1 = (int*) a;
    int* p2 = (int*) b;
    return (*p1 - *p2);
}

int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40, 1, 12, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x, i;
    printf("Element:");
    scanf("%d", &x);

    qsort(arr, n, sizeof(int), compare);
    for(i = 0; i < n; i++) {
        printf("arr[%d]=%d\n", i, arr[i]);
    }
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? printf("Element is not present in array")
                   : printf("Element is present at index %d",
                            result);
    return 0;
}
