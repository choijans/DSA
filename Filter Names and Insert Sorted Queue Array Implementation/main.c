#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "queue.h"

void main(){
    NQueue n1;
    initNQueue(&n1);
    
    enqueue(&n1, createName("Jansen", "Choi"));
    enqueue(&n1, createName("Jio", "Choi"));
    enqueue(&n1, createName("Josh", "Lui"));
    enqueue(&n1, createName("JL", "Codilla"));
    displayQueue(n1);
    
    printf("\n-----FILTER NAMES FUNCTION\n");
    Name *nameArray = filterNames(&n1, "Choi");
    displayQueue(n1);
    displayNames(nameArray);
    
    NQueue n2; 
    initNQueue(&n2);
    printf("\n-----INSERT SORTED FUNCTION\n");
    insertSorted(&n2, createName("Jansen", "Lui"));
    insertSorted(&n2, createName("Jio", "Choi"));
    insertSorted(&n2, createName("Josh", "Delgado"));
    insertSorted(&n2, createName("Test", "Ai"));
    displayQueue(n2);
}