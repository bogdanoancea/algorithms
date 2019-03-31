#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "tree.h"

struct btree{
    void	*key;
    struct btree *left;
    struct btree *right;
    struct btree *pred;
};


BTree new () {
    return NULL;
}

int isEmpty(BTree root) {
    return root==NULL;
}

int size(BTree root) {
	if(!root)
        return 0;
	return size(root->left) + size(root->right)+1;
}

void *getKey(BTree root){
	assert(root);
	return root->key;
}

void setKey(BTree root, void *key){
	assert(root);
	root->key = key;
}

int isLeaf(BTree root){
	assert(root);
	return (root->left==0 && root->right==0);
}

BTree root(BTree node){
	assert(node);
	while(node->pred)
		node = node->pred;
	return node;
}

BTree getPred(BTree node) {
	assert(node);
	return node->pred;
}

BTree getLeftTree(BTree node){
	assert(node);
	return node->left;
}

BTree getRightTree(BTree node){
	assert(node);
	return node->right;
}

void setLeftTree(BTree root, BTree left){
	assert(!isEmpty(root));
	root->left = left;
	if(left)
		left->pred = root;
}

void setRightTree(BTree root, BTree right) {
	assert(!isEmpty(root));
	root->right = right;
	if(right)
		right->pred = root;
}

void setPred(BTree root, BTree p, int dir) {
	assert(!isEmpty(root));
	root->pred = p;
	if(dir==-1)
		p->left = root;
	else
		if(dir==1)
			p->right = root;
}

BTree createNode(void *key, BTree left, BTree right, BTree pred, int dir) {
    BTree node = (BTree)malloc(sizeof(struct btree));
    node->key = key;
    node->left = left;
    node->right = right;
    node->pred = pred;
    if(pred)
    switch(dir){
        case -1: pred->left = node;
                       break;
        case 1:  pred->right = node;
                      break;
        case  0: ;
    }
    return node;
}

BTree createTree(BTree root, BTree left, BTree right){
    assert(root);
    setLeftTree(root, left);
    setRightTree(root, right);
    return root;
}


void preorder(BTree root, void (*Visit)(void*)){
    if(!isEmpty(root)){
        Visit(getKey(root));
        preorder(getLeftTree(root), Visit);
        preorder(getRightTree(root), Visit);
    }
}

void inorder(BTree root, void (*Visit)(void*)){
    if(!isEmpty(root)){
        inorder(getLeftTree(root), Visit);
        Visit(getKey(root));
        inorder(getRightTree(root), Visit);
    }
}

void postorder(BTree root, void (*Visit)(void*)){
    if(!isEmpty(root)){
        postorder(getLeftTree(root), Visit);
        postorder(getRightTree(root), Visit);
        Visit(getKey(root));
    }
}

void Visit(void *key) {
    printf("cheia %d ", *(int*)key);
}



