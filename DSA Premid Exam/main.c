#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Data.h"
#include "Stack.h"

bool addProductBaseOnExpiry(Inventory *i, Product p){
    NodePtr newNode = createNode(p);
    if(newNode == NULL || i->currQty + p.prodQty > 100){
        return false;
    }
    
    Inventory newTemp;
    initInventory(&newTemp);
    
    while(i->top != NULL && compareDays(i->top->prod.expiry, p.expiry) < 0){
        NodePtr temp1 = i->top;
        i->top = temp1->link;
        temp1->link = newTemp.top;
        newTemp.top = temp1;
    }
    
    newNode->link = i->top;
    i->top = newNode;
    i->currQty += p.prodQty;
    
    while(newTemp.top != NULL){
        NodePtr temp1 = newTemp.top;
        newTemp.top = temp1->link;
        temp1->link = i->top;
        i->top = temp1;
    }
    return true;
}

int main() {
    ProductList myProd;
    int numCount, selection;

    printf("Enter sequence or selection: (1-6): ");
    scanf("%d", &selection);
    printf("Enter the number of data: ");
    scanf("%d", &numCount);

    createAndPopulate(&myProd, selection, numCount);

    Inventory myInventory;
    initInventory(&myInventory);

    printf("\nORIGINAL PRODUCT:\n");
    for(int i = 0; i < myProd.count; ++i) {
        displayProduct(myProd.prods[i]);
        printf("\n");
    }

    for(int i = 0; i < myProd.count; ++i) {
        printf("\n[%d.] Adding %s (%d): %s\n", i+1, myProd.prods[i].prodName, myProd.prods[i].prodQty, addProductBaseOnExpiry(&myInventory, myProd.prods[i])? "Success":"Fail");
        visualize(myInventory);
    }

    printf("\nUSING ADD PRODUCT:\n");
    visualize(myInventory);


    return 0;
}