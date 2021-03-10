#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct produs {
    int cod;
    double cantitate;
    double pret;
};


int main() {
    struct produs p1, p2, p3;
    double valoare_totala = 0;

    p1.cod = 1;
    p1.cantitate = 10;
    p1.pret = 12.5;

    p2.cod = 2;
    p2.cantitate = 5.5;
    p2.pret = 10;

    p3.cod = 3;
    p3.cantitate = 5;
    p3.pret = 2.5;

    List lista_produse = newList();
    insert(lista_produse, NULL, &p1);
    Iterator p = first(lista_produse);
    insert(lista_produse, p, &p2);
    insert(lista_produse, p, &p3);

    Iterator l;
    for(l = first(lista_produse); l != NULL; l = next(lista_produse, l)) {
        valoare_totala += (*(struct produs*)get(lista_produse, l)).pret * (*(struct produs*)get(lista_produse, l)).cantitate;
    }
    printf("Valoarea totala a produselor din stoc este : %f\n",valoare_totala);

    return 0;
}
