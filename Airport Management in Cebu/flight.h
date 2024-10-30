#ifndef FLIGHT_H
#define FLIGHT_H

typedef struct {
    int hour, min;
} time;

typedef struct {
    char flightCode[10];
    char aircraft[20];
    time timeStamp;
    char destination[30];
} flightDetails; 

typedef struct{
    flightDetails flight[20];
    int count; 
} pot;

time createTime(int hour, int min);
flightDetails newFlight(char flightCode[], char aircraft[], time timeStamp, char destination[]);
void displayFlight(flightDetails flight);
void insertPot(pot *heap, flightDetails flight);

#endif