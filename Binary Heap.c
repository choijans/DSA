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
    deleteHeap(&heap);
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
    int i = 0;
    heap->count--;
    for(; i*2+1 < heap->count;){
        if(i*2+2 < heap->count){
            if(heap->elems[heap->count] < heap->elems[2*i+1] && heap->elems[heap->count] < heap->elems[2*i+2]) {
                break;
            } else {
                if(heap->elems[2*i+1] < heap->elems[2*i+2]){
                    heap->elems[i] = heap->elems[2*i+1];
                    i = i*2+1;
                } else {
                    heap->elems[i] = heap->elems[2*i+2];
                    i = i*2+2;
                }
            }
        } else if(i*2+1 < heap->count){
            if(heap->elems[2*i+1] < heap->elems[heap->count]){
                heap->elems[i] = heap->elems[2*i+1];
                i = i*2+1;
            } else {
                break;
            }
        }
    }
    
    heap->elems[i] = heap->elems[heap->count];
}

void displayHeap(minHeap heap){
    printf("DATA {\n");
    for(int i = 0; i < heap.count; ++i){
        printf("%d ", heap.elems[i]);
    }
    printf("\n}\n");
}