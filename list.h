#ifndef _LIST_H
#define _LIST_H

#define LINKED_LIST
//#define ARRAY

struct node; //definirea este ascunsa in implementare
struct list;

typedef struct list *List;       //pointer opac

#ifdef LINKED_LIST
typedef struct node *Iterator;   //implementarea cu liste inlantuite
#else
typedef int Iterator;   //implementarea cu liste inlantuite
#endif


typedef int (*PFC)(void*, void*);    //pointer la functie

// initializare lista vida (constructor)
List newList(void);

// initializare lista cu capacitatea cap (impementarea cu tablouri)
List newList2(int cap);

void deleteList(List L); // sterge lista (destructor)

int isEmpty(List L); // test lista vida

int size(List L);    // lungime lista

// intoarce adresa elementului din pozitia p
void *get(List L, Iterator p);

//functie ajutatoare, verifica daca p este in interiorul listei
int verifPoz(List L, Iterator p);

// modifica elementul din pozitia p
void change(List L, Iterator p, void *x);

// intoarce pozitia elementului in lista L, NULL daca nu este
Iterator find(List L, void *x, PFC equal);

// sterge elementul din pozitia p
void *removeElem(List L, Iterator p);

// insereaza un element inainte de pozitia p
void insert(List L, Iterator p, void *x);

// intoarce pozitia primului element din lista
Iterator first(List L);

// intoarce pozitia ultimului element din lista
Iterator last(List L);


// intoarce pozitia urmatoare pozitiei p
Iterator next(List L, Iterator p);

// intoarce pozitia dinaintea pozitiei p
Iterator prev(List L, Iterator p);

//schimba capacitatea - doar la implementarea cu tablouri
void changeDim(List L);
#endif 
