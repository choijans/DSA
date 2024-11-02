#include <stdio.h>
#include <stdlib.h>
#include "flight.h"

int main(){
    flightDetails flights[20];
    
    destination NAIA = newDest("NAIA", 1);
    destination Clark = newDest("Clark Airport", 2);
    destination Siquijor = newDest("Siquijor Airport", 3);
    destination Bicol = newDest("Bicol Airport", 4);
    destination Iba = newDest("Iba Airport", 5);
    destination Alto = newDest("Alto Airfield", 6);
    
    flights[0] = newFlight("IATA - 01", "Cathay Pacific", createTime(12, 30), Clark);
    flights[1] = newFlight("IBTB - 02", "Korea Air", createTime(10, 45), Alto);
    flights[2] = newFlight("ICTC - 03", "AirAsia", createTime(16, 15), Iba);
    flights[3] = newFlight("IDTD - 04", "Emirates", createTime(4, 20), Siquijor);
    flights[4] = newFlight("IETE - 05", "Qatar Airways", createTime(7, 50), NAIA);
    flights[5] = newFlight("IFTF - 06", "Delta Airlines", createTime(9, 05), Bicol);
    
    // printf("%-12s|%-20s|%-10s|%-10s|%-10s\n", "FLIGHT CODE", "AIRCRAFT", "HOUR", "MINUTE", "DESTINATION");
    // for(int i = 0; i < 6; ++i){
    //     displayFlight(flights[i]);
    //     printf("\n");
    // }
    
    FILE *fp; 
    fp = fopen("flight_details.dat", "wb");
    
    if(fp != NULL){
        fwrite(flights, sizeof(flightDetails), 6, fp);
    }
    
    fclose(fp);

    pot heap;
    heap.count = 0;
    flightDetails f;
    
    fp = fopen("flight_details.dat", "rb");
    
    if(fp != NULL){
        while(fread(&f, sizeof(flightDetails), 1, fp)){
            insertPot(&heap, f);
        }
    }
    
    displayPot(heap);
    fclose(fp);
    
    pot newHeap;
    newHeap.count = 0;
    getFlightsBefore(&heap, flights[5], &newHeap);
    displayPot(newHeap);

    return 0;
}