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

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 20

typedef struct {
    int data[MAX];
    int count;
} maxHeap;

void initHeap(maxHeap *heap);
void insertHeap(maxHeap *heap, int data);
bool deleteHeap(maxHeap *heap);
void displayHeap(maxHeap heap);

int main(){
    maxHeap heap;
    initHeap(&heap);
    
    insertHeap(&heap, 15);
    insertHeap(&heap, 10);
    insertHeap(&heap, 20);
    insertHeap(&heap, 17);
    insertHeap(&heap, 25);
    
    displayHeap(heap);
    
    printf("\n");
    deleteHeap(&heap);
    displayHeap(heap);
    
    return 0; 
}

void initHeap(maxHeap *heap){
    heap->count = 0;
}

void insertHeap(maxHeap *heap, int data){
    int i;
    for(i = heap->count; i > 0 && heap->data[(i-1)/2] < data; i = (i-1)/2){
        heap->data[i] = heap->data[(i-1)/2];
    }
    
    heap->data[i] = data;
    heap->count++;
}

bool deleteHeap(maxHeap *heap){
     if(heap->count == 0){
         return false;
     }
     
     heap->data[0] = heap->data[heap->count-1];
     heap->count--;
     
     int i = 0;
     while(i < heap->count){
         int left = i*2 + 1;
         int right = i*2 + 2;
         int large = i; 
         
         if(left < heap->count && heap->data[left] > heap->data[large]){
             large = left;
         } else if(right < heap->count && heap->data[left] > heap->data[large]){
             large = right; 
         }
         
         if(large != i){
             int temp = heap->data[i];
             heap->data[i] = heap->data[large];
             heap->data[large] = temp;
             i = large;
         } else {
             break;
         }
     }
}

void displayHeap(maxHeap heap){
    for(int i = 0; i < heap.count; ++i){
        printf("%d ", heap.data[i]);
    }
}
*/
