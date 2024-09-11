#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "myHeader.h"
#define MAX 8

void initQueue(Queue *q1){
    q1->front = 1;
    q1->rear = 0;
    //front always ahead of rear by one
}

Queue createQueue(){
    Queue q1; 
    q1.front = 1;
    q1.rear = 0;
    return q1;
}

bool isEmpty(Queue q1){
    return q1.front == (q1.rear + 1) % MAX;
}

bool isFull(Queue q1){
    return q1.front == (q1.rear + 2) % MAX;
}

void displayQueue(Queue q1){
    while(!isEmpty(q1)){
        printf("%d ", front(q1));
        dequeue(&q1);
    }    
}

bool enqueue(Queue *q1, int item){
    if(!isFull(*q1)){
        q1->rear = (q1->rear + 1) % MAX;
        q1->elems[q1->rear] = item;
        return true;
    }
    return false;
}

bool dequeue(Queue *q1){
    if(!isEmpty(*q1)){
        q1->front = (q1->front + 1) % MAX;
        return true;
    }
    return false;
}

int front(Queue q1){
    return q1.elems[q1.front];
}

int countElem(Queue q1){
    int count = 0;
    while(!isEmpty(q1)){
        count++;
        dequeue(&q1);
    }
    return count; 
}

Queue getEven1(Queue *q1){
    Queue newQueue = createQueue();
    Queue temp = createQueue();
    while(!isEmpty(*q1)){
        if(front(*q1) % 2 == 0){
            enqueue(&newQueue, front(*q1));
        } else {
            enqueue(&temp, front(*q1));
        }
        dequeue(q1);
    }
    
    while(!isEmpty(temp)){
        enqueue(q1, front(temp));
        dequeue(&temp);
    }
    return newQueue;
}

Queue getEven2(Queue *q1){
    Queue newQueue = createQueue();
    int count = countElem(*q1);
    
    for(int i = 0; i < count; ++i){
        if(front(*q1) % 2 == 0){
            enqueue(&newQueue, front(*q1));
        } else {
            enqueue(q1, front(*q1));
        }
        dequeue(q1);
    }
    
    return newQueue;
}