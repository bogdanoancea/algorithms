#include "list.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int equal(void* a, void* b) {
    if(*(int*)a ==*(int*)b)
        return 1;
    else
        return 0;
}


int main() {
    List L = newList2(5);
    int* elemente = (int*)malloc(5 * sizeof(int));
    elemente[0]=1;
    elemente[1]=3;
    elemente[2]=5;
    elemente[3]=7;
    elemente[4]=9;
    insert(L,0, &elemente[0]);
    printf("Dimensiunea listei : %d\n", size(L));
    Iterator p = first(L);
    insert(L, p, &elemente[1]);
    insert(L, p, &elemente[2]);
    insert(L, p, &elemente[3]);
    insert(L, p, &elemente[4]);
    printf("Dimensiunea listei : %d\n", size(L));
    Iterator pos = find(L, &elemente[2], &equal);
    if(pos != last(L))
        printf("Am gasit in lista elementul: %d\n", elemente[2]);

    printf("Elementele listei sunt:\n");
    Iterator el;
    for(el = first(L); el!=last_test(L); el = next(L,el)) {
        printf("%d\n", *(int*)get(L,el));
    }
    return 0;
}