#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} NodeType, *NodePtr, *BST;

bool insertBST(BST *bst, int data);
void initBST(BST *bst);
void displayBST(BST *bst);
void preorder(BST b);
void inorder(BST b);
void bfs(BST b);

void main(){
    BST tree;
    initBST(&tree);
    
    insertBST(&tree, 10);
    insertBST(&tree, 5);
    insertBST(&tree, 12);
    insertBST(&tree, 1);
    insertBST(&tree, 9);
    insertBST(&tree, 16);
    insertBST(&tree, 16);
    
    inorder(tree);
}

bool insertBST(BST *bst, int data){
    NodePtr *trav = bst;
    
    while(*trav != NULL && (*trav)->data != data){
        trav = ((*trav)->data > data) ? &(*trav)->left : &(*trav)->right;
        //shortcut ternary
        // if((*trav)->data > data){
        //     trav = &(*trav)->left;
        // } else if((*trav)->data < data){
        //     trav = &(*trav)->right;
        // }
    }

    if(*trav == NULL){
        *trav = calloc(1, sizeof(NodeType));
        (*trav)->data = data;
        return true;
    } else {
        return false; 
    }
}

void initBST(BST *bst){
    *bst = NULL;
}

void preorder(BST b){
    if(b != NULL){
        printf("%d ", b->data);
        preorder(b->left);
        preorder(b->right);
    }
}

void inorder(BST b){
    if(b != NULL){
        inorder(b->left);
        printf("%d ", b->data);
        inorder(b->right);
    }
}

void bfs(BST b){
    
}