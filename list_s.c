#include "list.h"
#include <assert.h>
#include <stdlib.h>


struct node {
    void   *data;
    struct node *next;
};

struct list {
    struct    node *first;
    int       dimension;
};


List newList(){
    List L = (List)malloc(sizeof(struct list));
    L->dimension = 0;
    L->first = NULL;
    return L;
}

Iterator first(List L){
    assert(L);
    return L->first;
}

Iterator last(List L){
//not implemented for singly linked lists
    return NULL;
}

int verifPoz(List L, Iterator p) {
    Iterator poz = L->first;
    if(p == NULL)
        return 1;
    while(poz != NULL){
        if(poz == p)
            return 1;
        poz = poz->next;
    }
    return 0;
}

Iterator next(List L, Iterator p){
    assert(L && !isEmpty(L) && verifPoz(L,p));
    return p->next;
}

Iterator prev(List L, Iterator p){
    //not impplemented for simly linked lists
    return NULL;
}

void* get(List L, Iterator p){
    assert(L && !isEmpty(L) && verifPoz(L,p));
    return p->data;
}

void change(List L, Iterator p, void *x){
    assert(L && !isEmpty(L) && verifPoz(L,p));
    p->data = x;
}

Iterator find(List L, void *x, PFC equal ){
	Iterator p;
	for(p = first(L); p != NULL; p = next(L, p))
	if((*equal)(get(L, p), x))
		return p;
	return NULL;
}

void *removeElem(List L, Iterator p){
	assert(L && !isEmpty(L) && verifPoz(L,p));
	Iterator f = first(L);
    void* x;
    if( p == f) { //sters primul nod
        L->first = f->next;
        x = f->data;
        free(f);
    }

    // Cauta nodul precedent al nodului care trebuie sters
    f = first(L);
    while(f->next != p )
    	f = next(L, f);
    struct node *next = f->next->next;

    x = f->next->data;
    free(f->next);
    f->next = next;

	L->dimension--;

    return x;
}

void insert(List L, Iterator p, void *x) {
	Iterator nou;
	if(!verifPoz(L, p))
	    return;/*pozitia p nu exista*/
	nou=(Iterator)malloc(sizeof(struct node));
	nou->data = x;

    if(p){
	    nou->next = p;
	    if(p == first(L)){
	        L->first = nou;
	    }
	    else {
	    	Iterator f = first(L);
	    	while(f->next != p )
	    		f = next(L, f);
	    	f->next = nou;
	    }
	}
	else {
	    nou->next = NULL;
        L->first = nou;
	}
	L->dimension++;
}

void deleteList(List L) {
	Iterator crt, prc;
	crt = L->first;
	while(crt != NULL){
		prc = crt;
		crt = crt->next;
		free(prc);
	}
	free(L);
}


int isEmpty(List L) {
    return L->dimension == 0;
}

int size(List L) {
    return L->dimension;
}

void changeDim(List L) {}
