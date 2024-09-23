#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int elem;
    struct node *next;
    struct node *prev;
} nodeType, *nodePtr;

void initList(nodePtr *dList);
nodePtr createNode(int elem);
bool isEmpty(nodePtr dList);
void displayList(nodePtr dList);
bool insertFront(nodePtr *dList, int elem);
bool insertLast(nodePtr *dList, int elem);
bool deleteFront(nodePtr *dList);
bool deleteLast(nodePtr *dList);
int countList(nodePtr dList);

void main(){
    nodePtr dList;  
    initList(&dList);
    
    insertFront(&dList, 1);
    insertFront(&dList, 2);
    insertFront(&dList, 3);
    insertFront(&dList, 4);
    // insertLast(&dList, 10);
    deleteLast(&dList);
    displayList(dList);

}

void initList(nodePtr *dList){
    *dList = NULL;
}

nodePtr createNode(int elem){
    nodePtr temp = malloc(sizeof(nodeType));
    temp->elem = elem;
    temp->next = NULL;
    temp->prev = NULL;
    return temp; 
}

bool isEmpty(nodePtr dList){
    return (dList == NULL) ? 1 : 0; // Can be shortened to just "return dList == NULL;"
}

void displayList(nodePtr dList){
    nodePtr trav = dList;
    printf("DATA\n");
    while(trav != NULL){
        printf("%d ", trav->elem);
        trav = trav->next;
    }
    printf("\n}\n");
}

bool insertFront(nodePtr *dList, int elem){
    nodePtr newNode = createNode(elem);
    
    if(newNode == NULL){
        return false; 
    }
    
    newNode->next = *dList;
    *dList = newNode;
    return true;
    
    // ALTERNATIVE CODE
    // if(newNode!=NULL){
    //     newNode->next = *dList;
    //     *dList = newNode;
    //     return true;
    // }
    // return false;
}

bool insertLast(nodePtr *dList, int elem){
    nodePtr newNode = createNode(elem);
    
    if(newNode == NULL){
        return false;
    }
    
    nodePtr trav = *dList;
    while(trav->next != NULL){
        trav = trav->next; 
    }
    
    newNode->prev = trav;
    trav->next = newNode;
    return true;
    
    // ALTERNATIVE CODE
    // if(newNode!=NULL){
    //     nodePtr trav = *dList;
    //     while(trav->next != NULL){
    //         trav = trav->next; 
    //     }
        
    //     newNode->prev = trav;
    //     trav->next = newNode;
    //     return true;
    // }
    // return false;
}

bool deleteFront(nodePtr *dList){
    if(isEmpty(*dList)){
       return false; 
    }
    
    nodePtr temp = *dList;
    *dList = temp->next;
    (*dList)->prev = NULL;
    free(temp);
    return true;
}

bool deleteLast(nodePtr *dList){
    if(isEmpty(*dList)){
        return false;
    }
    
    if ((*dList)->next == NULL) {
        free(*dList);
        *dList = NULL;
        return true;
    }
    
    nodePtr *trav = dList;
    while((*trav)->next->next != NULL){
        trav= &(*trav)->next;
    }
        
    nodePtr temp = (*trav)->next;
    (*trav)->next = temp->next;
    free(temp);
    return true;
}

int countList(nodePtr dList){
    int count = 0;
    nodePtr trav = dList;
    while(trav != NULL){
        count++;
        trav = trav->link;
    }
    return count;
}