#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right; 
} NodeType, *NodePtr, *BST;

typedef struct qNode {
    NodePtr elem;
    struct qNode *link;
} *qNodePtr;

typedef struct {
    qNodePtr head;
    qNodePtr tail;
} Queue;

void initBST(BST *bst);
bool insertBST(BST *bst, int data);
void deleteBST(BST *bst, int data);
void inorder(BST bst);
void preorder(BST bst);
void postorder(BST bst);
void bfs(BST bst);

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
    
    printf("[BFS]:\n");
    bfs(tree);
    
    return 0;
}

void initBST(BST *bst){
    *bst = NULL;
}

bool insertBST(BST *bst, int data){
    NodePtr *trav = bst;
    
    while(*trav != NULL && (*trav)->data != data){
        trav = ((*trav)->data > data) ? &(*trav)->left : &(*trav)->right;
    }
    
    if(*trav == NULL){
        *trav = calloc(1, sizeof(NodeType));
        if(*trav != NULL){
            (*trav)->data = data;
            return true; 
        }
    } else {
        return false;
    }
}

void deleteBST(BST *bst, int data){
    NodePtr *trav, *trav2, temp;
    trav = bst;
    
    while(*trav != NULL && (*trav)->data != data){
        trav = (*trav)->data > data ? &(*trav)->left : &(*trav)->right;
    }
    
    if(*trav != NULL){
        if((*trav)->left == NULL){
            temp = *trav;
            *trav = temp->right;
        } else if((*trav)->right == NULL){
            temp = *trav;
            *trav = temp->left;
        } else {
            for(trav2 = &(*trav)->right; (*trav2)->left != NULL; trav2 = &(*trav2)->left) {}
            temp = *trav2;
            *trav2 = temp->left;
            (*trav)->data = temp->data;
        }
        free(temp);
    }
}

//LNR
void inorder(BST bst){
    if(bst != NULL){
        inorder(bst->left);
        printf("%d ", bst->data);
        inorder(bst->right);
    }
}

//NLR
void preorder(BST bst){
    if(bst != NULL){
        printf("%d ", bst->data);
        preorder(bst->left);
        preorder(bst->right);
    }
}

//LRN
void postorder(BST bst){
    if(bst != NULL){
        postorder(bst->left);
        postorder(bst->right);
        printf("%d ", bst->data);
    }
}

void bfs(BST bst){
    Queue q; 
    
    qNodePtr temp = malloc(sizeof(struct qNode));
    temp->elem = bst;
    
    q.head = temp;
    q.tail = temp;
    
    while(q.head != NULL){
        printf("%d ", q.head->elem->data);
        //enqueue
        if(q.head->elem->left != NULL){
           temp = malloc(sizeof(struct qNode));
           temp->elem = q.head->elem->left;
           if(q.head == NULL){
               q.head = temp;
           } else {
               q.tail->link = temp;
           }
           q.tail = temp;
        } 
        if(q.head->elem->right != NULL){
            temp = malloc(sizeof(struct qNode));
            temp->elem = q.head->elem->right;
            if(q.head == NULL){
                q.head = temp;
            } else {
                q.tail->link = temp;
            }
            q.tail = temp; 
        }
        qNodePtr toDel = q.head;
        q.head = q.head->link; 
        free(toDel);
    }
}
