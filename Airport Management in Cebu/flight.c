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

flightDetails newFlight(char flightCode[], char aircraft[], time timeStamp, char destination[]){
    flightDetails flight;
    
    strcpy(flight.flightCode, flightCode);
    strcpy(flight.aircraft, aircraft);
    flight.timeStamp = timeStamp;
    strcpy(flight.destination, destination);
    
    return flight;
}

void displayFlight(flightDetails flight){
    printf("%-12s|%-20s|%02d|%02d|%-10s", flight.flightCode, flight.aircraft, flight.timeStamp.hour, flight.timeStamp.min, flight.destination);
}

void insertPot(pot *heap, flightDetails flight){
    int i;
    for(i = heap->count; i > 0 && heap->flight[(i-1)/2].timeStamp.hour > flight.timeStamp.hour && heap->flight[(i-1)/2].timeStamp.min > flight.timeStamp.min; i = (i-1)/2){
        heap->flight[i] = heap->flight[(i-1)/2];
    }
    heap->flight[i] = flight;
    heap->count++;
}