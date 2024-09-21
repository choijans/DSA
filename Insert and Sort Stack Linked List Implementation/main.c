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
    // displayStack1(s);
    
    // printf("\n-----INSERT SORTED 2 FUNCTION-----\n");
    // insertSorted2(&s, createPerson("Z", 19, 'M'));
    // insertSorted2(&s, createPerson("N", 20, 'F'));
    // insertSorted2(&s, createPerson("T", 21, 'M'));
    // displayStack1(s);
    
    // printf("-----PUSH FUNCTION TO TEST SORT STACK-----\n");
    // push(&s, createPerson("G", 12, 'F'));
    // push(&s, createPerson("A", 11, 'M'));
    // push(&s, createPerson("C", 10, 'F'));
    // displayStack1(s);
    
    printf("\n-----PUSH FUNCTION TO TEST SORT STACK-----\n");
    push(&s, createPerson("Z", 19, 'M'));
    push(&s, createPerson("N", 20, 'F'));
    push(&s, createPerson("T", 21, 'M'));
    displayStack2(s);
    
    printf("\n-----SORT STACK 1 FUNCTION-----\n");
    sortStack2(&s, false);
    displayStack2(s);
}
