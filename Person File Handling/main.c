#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){
    Person list[6];
    
    list[0] = newPerson("Choi", 12);
    list[1] = newPerson("Lui", 13);
    list[2] = newPerson("Del", 15);
    list[3] = newPerson("Maratas", 11);
    list[4] = newPerson("Salise", 19);
    
    // for(int i = 0; i < 5; ++i){
    //     displayPerson(list[i]);
    //     printf("\n");
    // }
    
    FILE *fp;
    
    fp = fopen("person_file.dat", "wb");
    
    if(fp != NULL){
        fwrite(list+1, sizeof(Person), 3, fp);
    }
    
    fclose(fp);
    
    Person p;
    
    fp = fopen("person_file.dat", "rb");
    
    if(fp != NULL){
        while(fread(&p, sizeof(Person), 1, fp)){
            displayPerson(p);
            printf("\n");
        }
    }
    
    fclose(fp);
    return 0;
}