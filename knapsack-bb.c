#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct Node {
	int level;
	int value;
	int weight;
	float bound;
};

struct Item {
	int weight;
	int value;
};

void insertOrd(List L, struct Node* v) {
    float current_bound, current_data_bound;
    Iterator it;
    struct Node* current_data;
    if(isEmpty(L))
        insert(L, NULL, v);
    else {
        it = first(L);
		current_bound = v->bound;
		current_data = get(L,it);
        current_data_bound = current_data->bound;

        while( current_bound <= current_data_bound && it != NULL )  {
            current_data = get(L,it);
            current_data_bound = current_data->bound;

            it = next(L, it);
        }
        insert(L, it, v);
    }
}

float bound(struct Node u, struct Item arr[], int W, int n){
   int j, k;
   int total_weight;
   float result;

   if (u.weight >= W)
         result = 0;
   else {
         result = u.value;
         j = u.level + 1;
         total_weight = u.weight;
         while (j < n && total_weight + arr[j].weight <= W){
            total_weight = total_weight + arr[j].weight;
            result = result + arr[j].value;
            j++;
         }
         k = j;
         if (k < n)
            result = result + (W - total_weight) * arr[k].value / arr[k].weight;
   }
   return result;
}

int knapsack(int n, struct Item arr[], int W) {
  List L;
  int maxvalue;
  struct Node *u, *v;
  L = newList();
  v = malloc( sizeof(struct Node));
  v->level = -1;
  v->value = 0;
  v->weight = 0;
  v->bound = bound(*v, arr, W, n); // nodul v va fi radacina arborelui
  maxvalue = 0;
  insertOrd2(L, v);
  while (! isEmpty(L)){
     v = (struct Node *)removeElem(L, first(L));  //extrag nodul cu cel mai mare bound
     if (v->bound > maxvalue) { // verific daca este nod promitator
        u = malloc(sizeof(struct Node));
        u->level = v->level + 1;  // nodul u va fi nodul copil care include
                                // urmatorul obiect
        u->weight = v->weight + arr[u->level].weight;
        u->value = v->value + arr[u->level].value;
        if (u->weight <= W && u->value > maxvalue)
           maxvalue = u->value;
        u->bound = bound(*u, arr, W, n);
        if (u->bound > maxvalue)
           insertOrd(L, u);

        // nodul u va fi nodul copil care NU include
        // urmatorul obiect
        u = malloc(sizeof(struct Node));
        u->level = v->level + 1;
        u->weight = v->weight;
        u->value = v->value;

        u->bound = bound(*u, arr, W, n);
        if (u->bound > maxvalue)
           insertOrd(L, u);
     }
  }
  return maxvalue;
}


int main() {
//	int W = 10; // Weight of knapsack
	int W = 16;
//	struct Item arr[] = {{2, 40}, {3, 50}, {2, 100}, {5, 95}, {3, 30}};
	struct Item arr[] = {{2, 40}, {5, 30}, {10, 50}, {5, 10}};

	int n = sizeof(arr) / sizeof(arr[0]);

	printf("Valoarea maxima a obiectelor care pot fi incarcate in rucsac este: %d\n", knapsack(n, arr, W));

	return 0;
}
