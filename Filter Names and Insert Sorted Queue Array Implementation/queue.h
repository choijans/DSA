#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#define MAX 8

typedef struct {
    char fName[30];
    char lName[30];
} Name;

typedef struct {
    Name elems[MAX];
    int head;
    int tail;
} NQueue;

Name createName(char fName[], char lName[]);

void initNQueue(NQueue *nq);
bool isEmpty(NQueue nq);
bool isFull(NQueue nq);
void displayQueue(NQueue nq);

bool enqueue(NQueue *nq, Name n);
bool dequeue(NQueue *nq);
Name front(NQueue nq);
int countElem(NQueue nq);

/*Removes the names that matches the filterString to the lastname. 
  Returns the removed names. Use the concept of adding a sentinel
  at the end indicating the last item in list as empty strings for
  fname and lname. If there are no names that will match then the
  function should return the sentinel.*/
Name *filterNames(NQueue *nq, char *filterString);
void displayNames(Name nameArray[]);

/*Insert soreted base on lastname. Rember to use the property 
  of the queue but without using the functions (enqueue, dequeue, front)*/
bool insertSorted(NQueue *nq, Name n);

#endif