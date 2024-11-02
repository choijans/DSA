#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "flight.h"

time createTime(int hour, int min){
    time t;

    t.hour = hour;
    t.min = min;
    
    return t;
}

flightDetails newFlight(char flightCode[], char aircraft[], time timeStamp, destination flightDes){
    flightDetails flight;
    
    strcpy(flight.flightCode, flightCode);
    strcpy(flight.aircraft, aircraft);
    flight.timeStamp = timeStamp;
    flight.flightDes = flightDes;
    
    return flight;
}

destination newDest(char dest[], int priority){
    destination d1;
    
    strcpy(d1.dest, dest);
    d1.priority = priority; 
    
    return d1; 
}

void displayFlight(flightDetails flight){
    printf("%-12s|%-20s|%02d|%02d|%-10s\n", flight.flightCode, flight.aircraft, flight.timeStamp.hour, flight.timeStamp.min, flight.flightDes.dest);
}

void insertPot(pot *heap, flightDetails flight){
    if(heap->count >= 20){
        return; 
    }
    int i;
    for(i = heap->count; i > 0 && comprio(flight, heap->flight[(i-1)/2]) == 1; i = (i-1)/2){
        heap->flight[i] = heap->flight[(i-1)/2];
    }
    heap->flight[i] = flight;
    heap->count++;
}

int comprio(flightDetails a, flightDetails b){
    if(a.timeStamp.hour != b.timeStamp.hour){
        return a.timeStamp.hour < b.timeStamp.hour ? 1 : 0;
    }
    
    if(a.timeStamp.min != b.timeStamp.min){
        return a.timeStamp.min < b.timeStamp.min ? 1 : 0;
    }
    
    return a.flightDes.priority < b.flightDes.priority ? 1 : 0;
}

void displayPot(pot heap){
    for(int i = 0; i < heap.count; ++i){
        displayFlight(heap.flight[i]);
    }
    printf("\n");
}

void getFlightsBefore(pot *heap, flightDetails flight, pot *newHeap){
    FILE *fp;
    int newCount = heap->count;
    fp = fopen("new_file.dat", "wb");
    
    for(int i = 0; i < newCount; ++i){
        if(fp != NULL){
            flightDetails dequeuedFlight = dequeue(heap);
            if(strcmp(dequeuedFlight.flightCode, flight.flightCode) == 0){
                break;
            }
            fwrite(&dequeuedFlight, sizeof(flightDetails), 1, fp);
        }
    }
    
    fclose(fp);
    
    flightDetails f;
    
    fp = fopen("new_file.dat", "rb");
    
    if(fp != NULL){
        while(fread(&f, sizeof(flightDetails), 1, fp)){
            insertPot(newHeap, f);
        }
    }
    
    fclose(fp);
}

flightDetails dequeue(pot *heap){
    flightDetails f = heap->flight[0];
    heap->count--;
    int small = 0;
    int left = 0, right = 0;
    while(1){
        left = small*2+1;
        right = small*2+2;
        
        if (right < heap->count){
            if (comprio(heap->flight[heap->count],heap->flight[right])==1 && comprio(heap->flight[heap->count],heap->flight[left])==1){
                break;
            }
            if (comprio(heap->flight[left],heap->flight[right])==1){
                heap->flight[small] = heap->flight[left];
                small = left;
            } else {
                heap->flight[small] = heap->flight[right];
                small = right;
            }
        } else if (left < heap->count){
            if (comprio(heap->flight[heap->count],heap->flight[left])==1){
                break;
            } else {
                heap->flight[small] = heap->flight[left];
                small = left;
            }
        } else {
            break;
        }
    }
    heap->flight[small] = heap->flight[heap->count];
    return f;
}