#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "queue.h"

#define MAX 8

Name createName(char fName[], char lName[]){
    Name n;
    strcpy(n.fName, fName);
    strcpy(n.lName, lName);
    return n;
}

void initNQueue(NQueue *nq){
    nq->head = 1;
    nq->tail = 0;
}

bool isEmpty(NQueue nq){
    return (nq.head == (nq.tail + 1) % MAX) ? true : false; 
}

bool isFull(NQueue nq){
    return (nq.head == (nq.tail + 2) % MAX) ? true : false; 
}

void displayQueue(NQueue nq){
    printf("DATA: {\n");
    while(!isEmpty(nq)){
        Name n = front(nq);
        printf("%s, %s\n", n.lName, n.fName);
        dequeue(&nq);
    }
    printf("}\n");
}

bool enqueue(NQueue *nq, Name n){
    if(!isFull(*nq)){
        nq->tail = (nq->tail + 1) % MAX;
        nq->elems[nq->tail] = n;
        return true;
    }
    return false;
}

bool dequeue(NQueue *nq){
    if(!isEmpty(*nq)){
        nq->head = (nq->head + 1) % MAX;
        return true;
    }
    return false; 
}

Name front(NQueue nq){
    return nq.elems[nq.head]; 
}

int countElem(NQueue nq){
    int count = 0;
    while(!isEmpty(nq)){
       count++;
       dequeue(&nq);
    }
    return count;
}

/*Removes the names that matches the filterString to the lastname. 
  Returns the removed names. Use the concept of adding a sentinel
  at the end indicating the last item in list as empty strings for
  fname and lname. If there are no names that will match then the
  function should return the sentinel.*/
Name *filterNames(NQueue *nq, char *filterString){
    int count = 0;
    int sizeOfQueue = countElem(*nq);
    Name *nameArray = malloc(sizeof(Name)*sizeOfQueue+1);
    NQueue tempQueue;
    initNQueue(&tempQueue);
    
    while(!isEmpty(*nq)){
        Name n = front(*nq);
        if(strcmp(n.lName, filterString) == 0){
            nameArray[count++] = n;
            dequeue(nq);
        } else {
            enqueue(&tempQueue, n);
            dequeue(nq);
        }
    }
    
    strcpy(nameArray[count].fName, "");
    strcpy(nameArray[count++].lName, "");
    nameArray = realloc(nameArray, count * sizeof(Name));
    
    while(!isEmpty(tempQueue)){
        Name n = front(tempQueue);
        enqueue(nq, n);
        dequeue(&tempQueue);
    }
    return nameArray;
}

void displayNames(Name nameArray[]){
    printf("NAME DATA: {\n");
    for(int i = 0; strcmp(nameArray[i].fName, "") != 0; ++i){
        printf("%s, %s\n", nameArray[i].lName, nameArray[i].fName);
    }
    printf("}\n");
}

/*Insert sorted base on lastname. Remember to use the property 
  of the queue but without using the functions (enqueue, dequeue, front)*/
bool insertSorted(NQueue *nq, Name n){
    if(isFull(*nq)){
        return false;
    }
    int i;
    for(i = nq->tail; i >= nq->head && strcmp(nq->elems[i].lName, n.lName) > 0; --i){
        nq->elems[(i + 1) % MAX] = nq->elems[i];
    }
    nq->elems[(i + 1) % MAX] = n;
    nq->tail = (nq->tail + 1) % MAX;
    return true;
}