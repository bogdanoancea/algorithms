#include "list.h"
#include <assert.h>
#include <stdlib.h>


struct node {
    void   *data;
    struct node *next;
    struct node *prev;
};

struct list {
    struct    node *first;
    struct    node *last;
    int       dimension;
};
typedef struct node *Iterator;   //implementarea cu liste inlantuite


List newList(){
    List L = (List)malloc(sizeof(struct list));
    L->dimension = 0;
    L->first = NULL;
    L->last = NULL;
    return L;
}

Iterator first(List L){
    assert(L);
    return L->first;
}

Iterator last(List L){
    assert(L);
    return L->last;
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
    assert(L && !isEmpty(L) && verifPoz(L,p));
    return p->prev;
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
	Iterator q = p;	//alt iterator pentru a sterge nodul
	p = next(L, p);	//actualizare iterator
	void* x = q->data;
	q->data = NULL;
	if(q->prev)	//izolarea nodului de sters
		q->prev->next = q->next;
	else
 		L->first = q->next;
	if(q->next)
		q->next->prev = q->prev;
	else
		L->last = q->prev;
	free(q);
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
	    if(p->prev){
	        nou->prev = p->prev;
	        p->prev->next = nou;
	        p->prev = nou;
	    }
	    else {
	        nou->prev = NULL;
	        L->first = nou;
	    }
	        p->prev = nou;
	}
	else {
	    nou->next = NULL;
	    nou->prev = L->last;
	    if(L->last){
	        L->last->next = nou;
	        L->last = nou;
	    }
	    else
	        L->last = L->first = nou;
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