#ifndef _list_h
#define _list_h

struct node; //definirea este ascunsa in implementare
struct list;

typedef struct list *List;       //pointer opac
typedef struct node *Iterator;   //implementarea cu liste inlantuite


typedef int (*PFC)(void*, void*);    //pointer la functie


// initializare lista vida (constructor)
List newList(void);

void deleteList(List L); // sterge lista (destructor)

int isEmptyList(List L); // test lista vida

int sizeList(List L);    // lungime lista

// intoarce adresa elementului din pozitia p
void *get(List L, Iterator p);

int verifPoz(List L, Iterator p);

// modifica elementul din pozitia p
void change(List L, Iterator p, void *x);

// intoarce pozitia elementului in lista L, NULL daca nu este
Iterator find(List L, void *x, PFC equal);

// sterge elementul din pozitia p
void *removeElem(List L, Iterator p);

// insereaza un element inainte de pozitia p
void insertList(List L, Iterator p, void *x);

// intoarce pozitia primului element din lista
Iterator first(List L);

// intoarce pozitia ultimului element din lista
Iterator last(List L);


// intoarce pozitia urmatoare pozitiei p
Iterator next(List L, Iterator p);

// intoarce pozitia dinaintea pozitiei p
Iterator prev(List L, Iterator p);


#endif /* _list_h */
