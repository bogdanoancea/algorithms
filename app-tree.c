#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

BTree insert (BTree root, int* key) {
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

    BTree root = insert(new(), &x[0]);
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

    printf("Arborele afisat in preordine:\n");
    preorder(root, Visit);

    printf("Arborele afisat in postordine:\n");
    postorder(root, Visit);

    printf("Arbore afisat in inordine:\n");
    inorder(root, Visit);
    return 0;
}
