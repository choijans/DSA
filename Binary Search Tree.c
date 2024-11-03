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
void deleteBST(BST *bst, int data);
void initBST(BST *bst);
void displayBST(BST *bst);
void preorder(BST b);
void inorder(BST b);
void bfs(BST b);

int main(){
    BST tree;
    initBST(&tree);
    
    insertBST(&tree, 10);
    insertBST(&tree, 5);
    insertBST(&tree, 12);
    insertBST(&tree, 1);
    insertBST(&tree, 9);
    insertBST(&tree, 16);
    insertBST(&tree, 8);
    insertBST(&tree, 11);
    insertBST(&tree, 13);
    insertBST(&tree, 14);
    
    inorder(tree);
    printf("\n");
    
    deleteBST(&tree, 14);
    inorder(tree);
    printf("\n");
    
    deleteBST(&tree, 16);
    inorder(tree);
    printf("\n");
    
    deleteBST(&tree, 5);
    inorder(tree);
    printf("\n");
    
    return 0;
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

void deleteBST(BST *bst, int data){
    NodePtr *trav = bst, temp;
    NodePtr *trav2;

    
    while(*trav != NULL && (*trav)->data != data){
        trav = ((*trav)->data > data) ? &(*trav)->left : &(*trav)->right;
    }
    
    //successor (main difference in the part where it looks for a parent with 2 childs)
    // if(*trav != NULL){
    //     if((*trav)->left == NULL){
    //         temp = *trav; 
    //         *trav = temp->right; 
    //     } else if((*trav)->right == NULL){
    //         temp = *trav; 
    //         *trav = temp->left; 
    //     } else {
    //         for(trav2 = &(*trav)->right; (*trav2)->left != NULL; trav2 = &(*trav2)->left){}
    //         temp = *trav2; 
    //         *trav2 = temp->right; 
    //         (*trav)->data = temp->data; 
    //     }
    //     free(temp);
    // }
    
    //predecessor
    if(*trav != NULL){
        if((*trav)->left == NULL){
            temp = *trav; 
            *trav = temp->right; 
        } else if((*trav)->right == NULL){
            temp = *trav; 
            *trav = temp->left; 
        } else {
            for(trav2 = &(*trav)->left; (*trav2)->right != NULL; trav2 = &(*trav2)->right){}
            temp = *trav2; 
            *trav2 = temp->left; 
            (*trav)->data = temp->data; 
        }
        free(temp);
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
