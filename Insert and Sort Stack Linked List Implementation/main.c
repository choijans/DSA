#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"

void main(){
    Stack s;
    initStack(&s);
    
    // printf("-----INSERT SORTED 1 FUNCTION-----\n");
    // insertSorted1(&s, createPerson("G", 12, 'F'));
    // insertSorted1(&s, createPerson("A", 11, 'M'));
    // insertSorted1(&s, createPerson("C", 10, 'F'));
    // displayStack(s);
    
    // printf("\n-----INSERT SORTED 2 FUNCTION-----\n");
    // insertSorted2(&s, createPerson("Z", 19, 'M'));
    // insertSorted2(&s, createPerson("N", 20, 'F'));
    // insertSorted2(&s, createPerson("T", 21, 'M'));
    // displayStack(s);
    
    printf("-----INSERT SORTED 1 FUNCTION-----\n");
    push(&s, createPerson("G", 12, 'F'));
    push(&s, createPerson("A", 11, 'M'));
    push(&s, createPerson("C", 10, 'F'));
    displayStack(s);
    
    printf("\n-----INSERT SORTED 2 FUNCTION-----\n");
    push(&s, createPerson("Z", 19, 'M'));
    push(&s, createPerson("N", 20, 'F'));
    push(&s, createPerson("T", 21, 'M'));
    displayStack(s);
    
    printf("\n-----SORT STACK FUNCTION-----\n");
    sortStack(&s, false);
    displayStack(s);
}