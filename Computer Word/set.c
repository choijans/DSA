#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "set.h"

Set createSet(){
    Set x = 0;
    return x;
}

bool addElement(Set* s, int item){
    Set check = 1 << (item);
    
    if((*s & check) != 0){
        return false; 
    }
    
    *s = *s | check;
    return true; 
}

bool removeElement(Set* s, int item){
    Set check = 1 << (item);
    
    if((*s & check) == 0){
        return false; 
    }
    
    *s = *s & (~check);
    return true; 
}

void displaySet(Set s){
    Set temp = s;
    for (int i = 0; temp > 0; ++i, temp = temp >> 1){
        if (temp & 1){
            printf("%d ",i);
        }
    }
}

Set unionSet(Set a, Set b){
    Set temp = a | b;
    return temp;
}

Set intersectionSet(Set a, Set b){
    Set temp = a & b;
    return temp; 
}

Set differenceSet(Set a, Set b){
    Set temp = a & (~b);
    return temp;
}

//XOR
Set symmetricDifferenceSet(Set a, Set b){
    Set temp = a ^ b;
    return temp; 
}

int cardinality(Set s){
    int count = 0;
    
    while (s){
        if (s & 1){
            count++;
        }
        s >>= 1;
    }
    
    return count; 
}

bool isElement(Set s, int item){
    Set check = 1 << (item);
    
    if(s & check){
        return true;
    }
    
    return false; 
}