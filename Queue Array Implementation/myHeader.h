#ifndef MYHEADER_H
#define MYHEADER_H

#include <stdbool.h>
#define MAX 8

typedef struct {
    int elems[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q);
Queue createQueue();
bool isEmpty(Queue q1);
bool isFull(Queue q1);
void displayQueue(Queue q1);
bool enqueue(Queue *q1, int item);
bool dequeue(Queue *q1);
int front(Queue q1);
int countElem(Queue q1);
Queue getEven1(Queue *q1);
Queue getEven2(Queue *q1);

#endif