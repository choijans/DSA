#include <stdio.h>
#include <stdlib.h>
#include "flight.h"

int main(){
    flightDetails flights[6];
    
    flights[0] = newFlight("IATA - 01", "Cathay Pacific", createTime(12, 30), "Bantayan Airport");
    flights[1] = newFlight("IBTB - 02", "Korea Air", createTime(10, 45), "Clark International Airport");
    flights[2] = newFlight("ICTC - 03", "AirAsia", createTime(16, 15), "Ninoy Aquino International Airport (NAIA)");
    flights[3] = newFlight("IDTD - 04", "Emirates", createTime(4, 20), "Panglao International Airport");
    flights[4] = newFlight("IETE - 05", "Air New Zealand", createTime(7, 50), "Manila");
    flights[5] = newFlight("IFTF - 06", "Delta Airlines", createTime(9, 05), "Bicol International Airport");
    
    // printf("%-12s|%-20s|%-10s|%-10s|%-10s\n", "FLIGHT CODE", "AIRCRAFT", "HOUR", "MINUTE", "DESTINATION");
    // for(int i = 0; i < 6; ++i){
    //     displayFlight(flights[i]);
    //     printf("\n");
    // }
    
    pot heap;
    heap.count = 0;
    for(int i = 0; i < 6; ++i){
        insertHeap(&heap, flights[i]);
    }
    
    FILE *fp; 
    fp = fopen("flight_details.dat", "wb");
    
    if(fp != NULL){
        fwrite(flights, sizeof(flightDetails), 6, fp);
    }
    
    fclose(fp);

    flightDetails f;
    
    fp = fopen("flight_details.dat", "rb");
    
    if(fp != NULL){
        while(fread(&f, sizeof(flightDetails), 1, fp)){
            displayFlight(f);
            printf("\n");
        }
    }
    
    fclose(fp);

    return 0;
}
