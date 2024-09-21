#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "myData.h"
#include "queue.h"

void main(){
    Queue q = createQueue();
    
    // visualize(q);
    // enqueue(&q, createStudent(23102442, createName("Jansen", "Choi"), "BSIT", 'm'));
    // enqueue(&q, createStudent(23102689, createName("Jio", "Delgado"), "BSCS", 'f'));
    // enqueue(&q, createStudent(21101024, createName("Josh", "Li"), "BSIT", 'm'));
    // visualize(q);
    
    // visualize(createNewQueue(q));
    
    // Name *list = getStudent(q, "BSIT", 'm');
    
    insertSorted(&q, createStudent(23102442, createName("Jansen", "Choi"), "BSIT", 'm'));
    //USING NEW DISPLAY FUNCTION THAT DOES NOT USE TRAVERSAL, ENQUEUE, DEQUEUE, FRONT
    display(q);
    insertSorted(&q, createStudent(23102689, createName("Jio", "Delgado"), "BSCS", 'f'));
    display(q);
    insertSorted(&q, createStudent(21101024, createName("Josh", "Ai"), "BSIT", 'm'));
    display(q);

}
