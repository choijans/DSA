#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"

#define MAX 10

//STACK FUNCTIONS
Product createProduct(int prodID, char prodName[], int prodQty, float prodPrice){
    Product p;
    p.prodID = prodID;
    strcpy(p.prodName, prodName);
    p.prodQty = prodQty;
    p.prodPrice = prodPrice;
    return p;
}

NodePtr createNode(Product p){
    NodePtr temp = malloc(sizeof(struct node));
    temp->link = NULL;
    temp->prod = p;
    return temp;
}

void initStack(Stack *s){
    *s = NULL;
}

bool isEmpty(Stack s){
    return s == NULL;
}

bool push(Stack *s, Product p){
    NodePtr temp = createNode(p);
    
    if(temp == NULL){
        return false;
    }
    
    temp->link = *s;
    *s = temp;
    return true; 
}

bool pop(Stack *s){
    if(!isEmpty(*s)){
        NodePtr temp = *s;
        *s = temp->link;
        free(temp);
        return true;
    }
    return false;
}

Product peek(Stack s){
    if(!isEmpty(s)){
        return s->prod; 
    }
}

void displayStack(Stack s){
    Stack temp;
    initStack(&temp);
    
    printf("-----PRODUCTS-----\n");
    
    while(!isEmpty(s)){
        Product p = peek(s);
        printf("Product ID: %d\n ", p.prodID);
        printf("Product Name: %s\n ", p.prodName);
        printf("Product Quantity: %d\n ", p.prodQty);
        printf("Product Price: %.2f\n", p.prodPrice);
        push(&temp, p);
        pop(&s);
        printf("------------------\n");
    }
    
    while(!isEmpty(temp)){
        push(&s, peek(temp));
        pop(&temp);
    }
}

//DICTIONARY FUNCTIONS
bool convertStack(ProdDict *dict, Stack stack){
    Stack temp;
    initStack(&temp);
    
    while(!isEmpty(stack)){
        addProduct(dict, peek(stack));
        push(&temp, peek(stack));
        pop(&stack);
    }
    
    while(!isEmpty(temp)){
        push(&stack, peek(temp));
        pop(&temp);
    }
}

int getHash(Product p){
    int sum = p.prodID;
    for(int i = 0; i < 3 && p.prodName[i] != '\0'; ++i){
        sum += p.prodName[i];
    }
    
    return sum % MAX;
}

Product getProduct(ProdDict dict, Product p){
    int key = getHash(p);
    Product dummy = {0, "XXXX", 0, 0};
    NodePtr trav = dict.data[key];
    for(; trav != NULL && trav->prod.prodID != p.prodID; trav = trav->link){}
    if(trav != NULL){
        return trav->prod;
    } else {
        return dummy;
    }
}

bool addProduct(ProdDict *dict, Product p){
    NodePtr newNode = createNode(p);
    int key = getHash(p);
    
    if(newNode == NULL){
        return false;
    }
    
    if(dict->count >= (dict->max * 0.7)){
        resizeDictionary(dict);
    }
    
    NodePtr *trav = &(dict->data[key]);
    for(; *trav != NULL && newNode->prod.prodID > (*trav)->prod.prodID; trav = &(*trav)->link){}
    if(*trav != NULL && newNode->prod.prodID == (*trav)->prod.prodID){
        (*trav)->prod.prodQty++;
        dict->count++;
        return true;
    } else {
        newNode->link = *trav;
        *trav = newNode;
    }
    dict->count++;
    return true;
}

bool removeProduct(ProdDict *dict, Product p){
    int key = getHash(p);
    
    NodePtr *trav = &(dict->data[key]);
    for(; *trav != NULL && p.prodID != (*trav)->prod.prodID; trav = &(*trav)->link){}
    if(*trav != NULL){
        if((*trav)->prod.prodQty > 1){
            (*trav)->prod.prodQty--;
            return true;
        } else {
            NodePtr temp = *trav;
            *trav = temp->link;
            free(temp);
            return true;
        }
    }
    return false; 
}

void initDict(ProdDict *dict){
    dict->count = 0;
    dict->max = MAX;
    dict->data = malloc(sizeof(NodePtr) * MAX);
}

void visualizeDict(ProdDict dict){
    NodePtr trav; 
    printf("-----DICTIONARY-----\n");
    for(int i = 0; i < dict.max; ++i){
        printf("[%d]: ", i);
        if(dict.data[i] == NULL){
            printf("List is Empty\n");
        } else {
            NodePtr trav; 
            for(trav = dict.data[i]; trav != NULL; trav = trav->link){
                printf("[");
                printf("%d, %s, %d", trav->prod.prodID, trav->prod.prodName, trav->prod.prodQty);
                printf("]");
            }
            printf("\n");
        }
    }
}

void resizeDictionary(ProdDict *dict){
    ProdDict temp;
    
    temp.data = malloc(sizeof(NodePtr) * (dict->max * 2));
    temp.count = 0;
    temp.max = (dict->max) * 2; 
    
    int hash;
    
    for(int i = 0; i < dict->max; ++i){
        NodePtr curr = dict->data[i];
        while(curr != NULL){
            addProduct(&temp, curr->prod);
            curr = curr->link;
        }
    }
    free(dict->data);
    dict->data = temp.data;
    dict->max = temp.max;
}
