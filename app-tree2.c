#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"

BTree insertTree(BTree root, int* key) {
    BTree node1, node2, node3;
    BTree res;
    node1 = createNode((void*)key, (BTree) NULL, (BTree)NULL, (BTree)NULL, 0);
    if(root == NULL)
        res = node1;
    else {
        node2 = root;
        while(node2 != NULL) {
            if(*(int*)key < *(int*)getKey(node2)) {
                node3 = node2;
                node2 = getLeftTree(node2);
            }
            else {
                node3 = node2;
                node2 = getRightTree(node2);
            }
        }
        if(*(int*)key < *(int*)getKey(node3)) {
            setLeftTree(node3, node1);
        }
        else {
            setRightTree(node3, node1);
        }
        res = root;
    }
    return res;
}


void breadthFirst(BTree root, void (*Visit)()){
    Queue q = newQueue2();
    BTree p;
    enq(q, root);
    while(!isEmptyQueue(q)){
        p = deq(q);
        Visit(getKey(p));
        if(getLeftTree(p))
            enq(q, getLeftTree(p));
        if(getRightTree(p))
            enq(q, getRightTree(p));
    }
}


int main()
{
    printf("Hello binary tree!\n");
    int *x = (int*) malloc(11 * sizeof(int));
    x[0] = 90;
    x[1] = 50;
    x[2] = 150;
    x[3] = 20;
    x[4] = 75;
    x[5] = 95;
    x[6] = 175;
    x[7] = 5;
    x[8] = 25;
    x[9] = 66;
    x[10] = 80;

    BTree root = insertTree(newTree(), &x[0]);
    insertTree(root, &x[1]);
    insertTree(root, &x[2]);
    insertTree(root, &x[3]);
    insertTree(root, &x[4]);
    insertTree(root, &x[5]);
    insertTree(root, &x[6]);
    insertTree(root, &x[7]);
    insertTree(root, &x[8]);
    insertTree(root, &x[9]);
    insertTree(root, &x[10]);

    printf("\n Preordine :\n");
    preorder(root, visit);
    printf("\n Postordine :\n");
    postorder(root, visit);
    printf("\n Inordine :\n");
    inorder(root, visit);
    printf("\n In latime :\n");
    breadthFirst(root, visit);
    return 0;
}

