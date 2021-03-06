#include <stdlib.h>
#include <stdio.h>
#include "queue.h"


void insertQueue(Queue Q) {
	int* x = (int*)malloc(sizeof(int));
	printf("Dati valoarea pe care doriti sa o introduceti:");
	scanf("%d", x);
	enq(Q, x);
}

void extractQueue(Queue Q) {
	int *x;
	x = deq(Q);
	printf("Elementul sters din coada este: %d \n", *x);
}

int main() {
	int optiune = 0;
	Queue Q = newQueue2();
	while (optiune != 7) {
		printf("1. Inserati un element in coada. \n");
		printf("2. Extrageti un element din coada. \n");
		printf("3. Afisati toate elementele cozii. \n");
        printf("4. Afisati elementul din varful cozii. \n");
        printf("5. Afisati elementul de la sfarsitul cozii. \n");
        printf("6. Afisati dimensiunea cozii cozii. \n");
		printf("7. Parasiti programul. \n");
		printf("Introduceti optiunea dorita:");
		scanf("%d", &optiune);
		if (optiune == 1)
			insertQueue(Q);
		else if (optiune == 2)
			extractQueue(Q);
		else if (optiune == 3)
			display(Q);
		else if (optiune == 4)
            printf("Elementul din varful cozii este %d:\n", *(int*)front(Q));
        else if (optiune == 5)
           printf("Elementul de la sfarsitul cozii este %d:\n", *(int*)back(Q));
        else if (optiune == 6)
           printf("Dimensiunea cozii este %d:\n", sizeQueue(Q));
        else if(optiune == 7)
			break;
	}
	deleteQueue(Q);
    return 0;
}
