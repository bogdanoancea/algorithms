#ifndef _TREE_H_
#define _TREE_H_


struct btree;

typedef struct btree *BTree;


/*
creeaza un arbore nou
*/
BTree new();

/* returneaza 1 daca arborele este gol, 0 altfel
*/
int	isEmpty(BTree t);

/*
determina numarul de noduri al arborelui t
*/
int	size(BTree t);

/*
returneaza radacina nodului t
*/
BTree root(BTree t);

/*
returneaza informatia (cheia) din nodul t
*/
void *getKey(BTree t);

/*
seteaza adresa cheii nodului a egală cu key
*/
void setKey(BTree node, void *key);

/*
retuneaza 1 dacă nodul node este frunza, 0 altfel
*/
int isLeaf(BTree node);

/*
retuneaza nodul predecessor (tata) al nodului node sau valoarea  NULL
*/
BTree getPred(BTree node);

/*
face nodul p tata al nodului node. Nodul predecesor p va avea nodul node subarbore stang sau drept,
dupa cum dir este -1 sau 1
*/
void setPred(BTree node, BTree p, int dir);

/*
returneaza radacina subarborelui stang a lui node

*/
BTree getLeftTree(BTree node);

/*
face left subarbore stang a lui node
*/
void setLeftTree(BTree node, BTree left);

/*
returneaza radacina subarborelui drept a lui node
*/
BTree getRightTree(BTree node);

/*
face right subarbore stang a lui node
*/
void setRightTree(BTree node, BTree right);

/*
creaza un nod cu cheia key, subarbori si parinte specificaţi;
nodul creat este subarbore stang sau drept a lui node dupa cum dir este -1 sau 1
*/
BTree createNode(void *key, BTree left, BTree right, BTree node, int dir);

/*
creaza un arbore dintr-un nod radacina si doi subarbori specificati
*/
BTree createTree(BTree root, BTree left, BTree right);

/*
returneaza inaltimea arborelui cu radacina root
*/
int	height(BTree root);

/*
returneaza adancimea nodului node
*/
int	depth(BTree node);

/*
viziteaza arborele cu radacina root in preordine
*/
void preorder(BTree root, void (*Visit)(void*));

/*
viziteaza arborele cu radacina root in inordine
*/
void inorder(BTree root, void (*Visit)(void*));

/*
viziteaza arborele cu radacina root in postordine
*/
void postorder(BTree root, void (*Visit)(void*));

void visit(void *key);

#endif // _TREE_H_
