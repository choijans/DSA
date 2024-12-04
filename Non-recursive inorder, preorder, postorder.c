#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *left;
    struct node *right;
} *tree;

tree createNode(int value);
int* inorderTraversal(tree root, int* returnSize);
int* preorderTraversal(tree root, int* returnSize);
int* postorderTraversal(tree root, int* returnSize);

void main(){
    tree root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(8);
    root->left->right->left = createNode(6);
    root->left->right->right = createNode(7);
    root->right->right->left = createNode(9);
    int size1, size2, size3;
    
    int *result1 = inorderTraversal(root, &size1);
    
    for (int i = 0; i < size1; i++) {
        printf("%d ", result1[i]);
    }
    printf("\n");
    
    int *result2 = preorderTraversal(root, &size2);
    
    for (int i = 0; i < size2; i++) {
        printf("%d ", result2[i]);
    }
    printf("\n");
    
    int *result3 = postorderTraversal(root, &size3);
    
    for (int i = 0; i < size3; i++) {
        printf("%d ", result3[i]);
    }
    printf("\n");
}

tree createNode(int value) {
    tree newNode = malloc(sizeof(struct node));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int* inorderTraversal(tree root, int* returnSize){
    int *arr = malloc(sizeof(int) * 20);
    *returnSize = 0;

    tree stack[20];
    int top = -1;
    tree current = root;
    
    while(current != NULL || top != -1){
        while(current != NULL){
            stack[++top] = current;
            current = current->left; 
        }
        
        current = stack[top--];
        arr[(*returnSize)++] = current->val;
        current = current->right; 
        
    }
    return arr;
}

int* preorderTraversal(tree root, int* returnSize) {
    int *arr = malloc(sizeof(int) * 20);  
    *returnSize = 0;                    
    
    if (root == NULL) return arr;       
    
    tree stack[20];
    int top = -1;
    
    stack[++top] = root; 
    while (top >= 0) {
        tree currentNode = stack[top--];  
        arr[(*returnSize)++] = currentNode->val; 
        
        if (currentNode->right != NULL) {
            stack[++top] = currentNode->right;
        }
        if (currentNode->left != NULL) {
            stack[++top] = currentNode->left;
        }
    }
    
    return arr; 
}

int* postorderTraversal(tree root, int* returnSize){
    int *arr = malloc(sizeof(int) * 20);
    *returnSize = 0;
    
    if (root == NULL) return arr;
    
    tree stack[20];
    int top = -1;
    tree lastVisited = NULL, current = root;
    
    while(current != NULL || top != -1){
        while(current != NULL){
            stack[++top] = current;
            current = current->left; 
        }
    
        tree peekNode = stack[top];
        if(peekNode->right != NULL && lastVisited != peekNode->right){
            current = peekNode->right;
        } else {
            arr[(*returnSize)++] = peekNode->val; 
            lastVisited = stack[top--];  
        }
    }
    return arr;
}