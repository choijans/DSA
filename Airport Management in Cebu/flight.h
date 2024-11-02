#ifndef FLIGHT_H
#define FLIGHT_H

typedef struct {
    int hour, min;
} time;

typedef struct {
    char dest[30];
    int priority;
} destination;

typedef struct {
    char flightCode[10];
    char aircraft[20];
    time timeStamp;
    destination flightDes;
} flightDetails; 

typedef struct{
    flightDetails flight[20];
    int count; 
} pot;

time createTime(int hour, int min);
flightDetails newFlight(char flightCode[], char aircraft[], time timeStamp, destination flightDes);
destination newDest(char dest[], int priority);
void displayFlight(flightDetails flight);
void insertPot(pot *heap, flightDetails flight);
int comprio(flightDetails a, flightDetails b);
void displayPot(pot heap);
void getFlightsBefore(pot *heap, flightDetails flight, pot *newHeap);
flightDetails dequeue(pot *list);

#endif