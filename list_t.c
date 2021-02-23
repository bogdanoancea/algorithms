#include "list.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct list {
	int dim;	//dimensiune efectiva
	int cap;		//capacitate (dimensiune alocata)                      
    void **data;      //tablou pointeri la date
};


List newList2(int cap) {
    List L = (List)malloc(sizeof(struct list)); 
    L->dim = 0;  
    L->cap = cap;
    L->data = (void**)malloc(L->cap * sizeof(void*)); 
    return L;
}

int size(List L) { 
    assert(L);
    return L->dim;
}


int isEmpty(List L) { 
    assert(L);
    return L->dim==0;
}

int verifPoz(List L, Iterator p){ 
    assert(L);
    if(isEmpty(L)) 
	return 1;
    if(p < 1 || p > L->dim) 
	return 0;
    
    return 1;
}

Iterator first(List L) {
    assert(L ); 
    return 1;
}
Iterator last(List L){ 
    assert(L);
    return L->dim;
}
Iterator next(List L, Iterator p){ 
    assert(L && !isEmpty(L));
    return p+1;
}

Iterator prev(List L, Iterator p){ 
  assert(L && !isEmpty(L));
  return p-1;
}

void *get(List L, Iterator p) {
  assert(L && !isEmpty(L) && verifPoz(L, p)); 
  return L->data[p-1];
}

void change(List L, Iterator p, void *x) { 
  assert(L && !isEmpty(L) && verifPoz(L,p)); 
  L->data[p-1] = x;
}


Iterator find(List L, void *x, PFC equal) { 
    Iterator p;
    assert(L); 
    if(isEmpty(L))
       return last(L);
    for(p=first(L); p!=last(L); p=next(L,p)) 
        if(get(L, p) == x) 
            return p;
    return last(L);
}

void *removeElem(List L, Iterator p) { 
    void *rez=NULL;
    int i;
    assert(L && !isEmpty(L) && verifPoz(L,p)); 
    rez = L->data[p-1];
    for(i=p-1; i<L->dim-1; i++) 
        L->data[i] =L->data[i+1];
        L->dim--; 
    return rez;
}

void insert(List L, Iterator p, void *x){ 
  assert(L && verifPoz(L, p));
  int i; 
  if(isEmpty(L)){
     L->data[0] = x;
  }
  else { 
    if(L->dim == L->cap) 
      changeDim(L);
    for(i=L->dim; i>=p; i--)
      L->data[i]=L->data[i-1]; 
    L->data[p-1] = x;
  }
  L->dim++;
}

void changeDim(List L){ 
  List L1;
  L1 = newList2(2*(L)->cap); 
  L1->dim = (L)->dim;
  memcpy(L1->data, (L)->data, (L)->cap); 
  deleteList(L);
L = L1;
}


void deleteList(List L) {
    free(L->data);
    free(L);
}

