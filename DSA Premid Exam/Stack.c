#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Data.h"
#include "Stack.h"

void initInventory(Inventory *i) {
    i->top = NULL;
    i->currQty = 0;
}

bool isEmpty(Inventory i) {
    return !i.top;
}

bool push(Inventory *i, Product p) {
    NodePtr temp = malloc(sizeof(NodeType));

    if(temp) {
        temp->prod = p;
        temp->link = i->top;
        i->top = temp;
        i->currQty += p.prodQty;
        return true;
    }

    return false;
}

bool pop(Inventory *i) {
    NodePtr temp;

    if(!isEmpty(*i)) {
        temp = i->top;
        i->top = temp->link;
        i->currQty -= temp->prod.prodQty;
        free(temp);
        return true;
    }

    return false;
}

Product peek(Inventory i) {
    return i.top->prod;
}

void visualize(Inventory i) {
    while(i.top) {
        displayProduct(i.top->prod);
        printf("\n");
        i.top = i.top->link;
    }
    printf("Count: %d\n", i.currQty);
}

NodePtr createNode(Product p){
    NodePtr temp = malloc(sizeof(NodeType));
    temp->prod = p;
    temp->link = NULL;
    return temp;
}

int compareDays(Date d1, Date d2){
    if(d1.year != d2.year){
        return d1.year - d2.year;
    }
    if(d1.month != d2.month){
        return d1.month - d2.month;
    }
    return d1.day - d2.day;
}