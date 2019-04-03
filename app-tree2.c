#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"

BTree insert (BTree root, int* key) {
    BTree node1, node2, node3;
    BTree res;
    //node1 = (BTree) malloc(sizeof(btree));
    node1 = BTree_CreateNode((void*)key, (BTree) NULL, (BTree)NULL, (BTree)NULL, 0);
    //BTree_SetKey(node1, key);
    //BTree_SetLT(node1, NULL);
    //BTree_SetRT(node1, NULL);
    if(root == NULL)
        res = node1;
    else {
        node2 = root;
        while(node2 != NULL) {
            if(*(int*)key < *(int*)BTree_GetKey(node2)) {
                    //printf("1. am trecut odata");
                node3 = node2;
                node2 = BTree_GetLT(node2);
            }
            else {
                //printf("2. am trecut odata");
                node3 = node2;
                node2 = BTree_GetRT(node2);
            }
        }
        if(*(int*)key < *(int*)BTree_GetKey(node3)) {
            BTree_SetLT(node3, node1);
        }
        else {
            BTree_SetRT(node3, node1);
        }
        res = root;
    }
    return res;
}


void BreadthFirst(BTree root, void (*Visit)()){
    Queue q = Q_New();
    BTree p;
    Enq(q, root);
    while(!Q_Empty(q)){
        p = Deq(q);
        Visit(BTree_GetKey(p));
        if(BTree_GetLT(p))
            Enq(q, BTree_GetLT(p));
        if(BTree_GetRT(p))
            Enq(q, BTree_GetRT(p));
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

    BTree root = insert(BTree_New(), &x[0]);
    insert(root, &x[1]);
    insert(root, &x[2]);
    insert(root, &x[3]);
    insert(root, &x[4]);
    insert(root, &x[5]);
    insert(root, &x[6]);
    insert(root, &x[7]);
    insert(root, &x[8]);
    insert(root, &x[9]);
    insert(root, &x[10]);

    printf("\n Preordine :\n");
    PreOrder(root, Visit);
    printf("\n Postordine :\n");
    PostOrder(root, Visit);
    printf("\n Inordine :\n");
    InOrder(root, Visit);
    printf("\n In latime :\n");
    BreadthFirst(root, Visit);
    return 0;
}