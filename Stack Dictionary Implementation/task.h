#ifndef TASK_H
#define TASK_H

#define MAX 10
#include <stdbool.h>

typedef struct {
    int prodID;
    char prodName[16];
    int prodQty;
    float prodPrice; 
} Product;

typedef struct node{
    Product prod;
    struct node *link;
} NodeType, *NodePtr, *Stack;

typedef struct {
    NodePtr *data; 
    int count; 
    int max; 
} ProdDict;

//STACK FUNCTIONS
Product createProduct(int prodID, char prodName[], int prodQty, float prodPrice);
NodePtr createNode(Product p);
void initStack(Stack *s);
bool isEmpty(Stack s);
bool push(Stack *s, Product p);
bool pop(Stack *s);
Product peek(Stack s);
void displayStack(Stack s);

//DICTiONARY FUNCTIONS
bool convertStack(ProdDict *dict, Stack stack);
int getHash(Product p);
Product getProduct(ProdDict dict, Product p);
bool addProduct(ProdDict *dict, Product p);
bool removeProduct(ProdDict *dict, Product p);
void initDict(ProdDict *dict);
void visualizeDict(ProdDict dict);
void resizeDictionary(ProdDict *dict);

#endif