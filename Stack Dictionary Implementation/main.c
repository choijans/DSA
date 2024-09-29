#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"

void main(){
    Stack stack;
    initStack(&stack);
    
    push(&stack, createProduct(1001, "Notebook", 1, 50.00));
    push(&stack, createProduct(1002, "Eraser", 2, 10.00));
    push(&stack, createProduct(1003, "Pen", 3, 15.00));
    
    displayStack(stack);
    
    ProdDict dict;
    initDict(&dict);
    
    convertStack(&dict, stack);
    //Add same product, increment product quantity
    addProduct(&dict, createProduct(1003, "Pen", 1, 15.00));
    removeProduct(&dict, createProduct(1003, "Pen", 1, 15.00));
    visualizeDict(dict);
    
    Product p = getProduct(dict, createProduct(1001, "Notebook", 1, 50.00));
    printf("\nProduct ID: %d\nProduct Name: %s\nProduct Quantity: %d", p.prodID, p.prodName, p.prodQty);
}