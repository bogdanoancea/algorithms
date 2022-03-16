#include "list.h"
#include <stdio.h>

int egal_int(void* a, void* b) {
    int* c = (int*)a;
    int* d = (int*)b;
    return *c == *d;
}

int main(int argc, const char * argv[]) {

    List L;
    int x1, x2, x3, x4;
    L = newList();
    x1 = 5;
    x2 = 6;
    x3 = 7;
    x4 = 8;

    // inserez 4 elemente in varful listei
    Iterator i = first(L);
    insert(L, i, &x1);

    i = first(L);
    insert(L, i, &x2);

    i = first(L);
    insert(L, i, &x3);

    i = first(L);
    insert(L, i, &x4);

    printf("Lista de la cap la coada\n");
    //parcurg lista de la cap la coada si afisez elementele ei
    for(i = first(L); i != NULL; i = next(L, i)) {
        int* data = (int* )get(L, i);
        printf("Elementul listei: %d\n", *data);
    }

    printf("Lista de la coada la cap\n");
    //parcurg lista de la coada la cap si afisez elementele ei
    for(i = last(L); i != NULL; i = prev(L, i)) {
        int* data = (int* ) get(L, i);
        printf("Elementul listei: %d\n", *data);
    }

    //inserez un nou element dupa primul element din varful listei
    int x5 = 9;
    i = first(L);
    i = next(L, i);
    insert(L, i, &x5);


    printf("Lista de la cap la coada\n");
    // afisez din nou lista
    for(i = first(L); i != NULL; i = next(L, i)) {
        int* data = (int* )get(L, i);
        printf("Elementul listei: %d\n", *data);
    }

    //sterg penultimul element din lista
    i = last(L);
    i = prev(L, i);
    removeElem(L, i);

    printf("Lista de la cap la coada\n");
    for(i = first(L); i != NULL; i = next(L, i)) {//
        int* data = (int* ) get(L, i);
        printf("Elementul listei: %d\n", *data);
    }


    //cauta elementul cu valoarea 4 in lista
    int x = 4;
    if(find(L, &x, egal_int))
        printf("Elementul cu valoarea %d se afla in lista\n", x);
    else
        printf("Elementul cu valoarea %d nu se afla in lista\n", x);

    int y = 5;
    if(find(L, &y, egal_int))
        printf("Elementul cu valoarea %d se afla in lista\n", y);
    else
        printf("Elementul cu valoarea %d nu se afla in lista\n", y);

    return 0;
}
