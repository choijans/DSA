//QUEUE
//cannot traversal within the QUEUE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "myHeader.h"

void main(){
    Queue q1 = createQueue();
    
    displayQueue(q1);
    for(int i = 0; i < 6; ++i){
        enqueue(&q1, i);
        
    }
    displayQueue(q1);
    
    // for(int i = 0; i < 10; ++i){
    //     dequeue(&q1);
        
    // }
    // displayQueue(q1);
    
    // printf("\n");
    // Queue newQ = getEven1(&q1);
    // displayQueue(q1);
    // printf("\n");
    // displayQueue(newQ);
    
    // int num = countElem(q1);
    // printf("\n%d", num);
    
    printf("\n");
    Queue newQ = getEven2(&q1);
    displayQueue(q1);
    printf("\n");
    displayQueue(newQ);
}