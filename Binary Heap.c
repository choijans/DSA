#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int elems[MAX];
    int count;
} minHeap;

void insertHeap(minHeap *heap, int item);
void deleteHeap(minHeap *heap);
void displayHeap(minHeap heap);

void main(){
    minHeap heap;
    heap.count = 0; 

    insertHeap(&heap, 10);

    insertHeap(&heap, 3);
    insertHeap(&heap, 1);
    insertHeap(&heap, 7);
    insertHeap(&heap, 24);
    
    displayHeap(heap);
}

void insertHeap(minHeap *heap, int item){
    int i;
    for(i = heap->count; i > 0 && heap->elems[(i-1)/2] > item; i = (i-1)/2){
        heap->elems[i] = heap->elems[(i-1)/2];
    }
    heap->elems[i] = item;
    heap->count++;
}

void deleteHeap(minHeap *heap){
    // int temp = heap->elems[heap->count];
    // heap->count--;
    // int i  = 0;
    // while(i < count){
    //     if(heap->elems[i])
    // }
}

void displayHeap(minHeap heap){
    printf("DATA {\n");
    for(int i = 0; i < heap.count; ++i){
        printf("%d ", heap.elems[i]);
    }
    printf("\n}\n");
}
