#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "myHeader.h"

#define MAX 100
Set createSet(){
    Set a;
    for(int i = 0; i < MAX; ++i){
        a.elems[i] = 0;
    }
    a.count = 0;
    return a; 
}

bool addElement(Set *s, int item){
    if(s->elems[item] == 0){
        s->elems[item] = 1;
        s->count++;
        return true;
    }
    return false; 
}

bool removeElement(Set *s, int item){
    if(s->elems[item] == 1){
        s->elems[item] = 0;
        s->count--;
        return true;
    }
    return false; 
}

void displaySet(Set s){
    printf("{");
    for(int i = 0; i < MAX; ++i){
        if(s.elems[i] == 1){
            printf("%d ", i);
        }
    }
    printf("}\n");
}

Set union1(Set A, Set B){
    Set s = createSet();
    for(int i = 0; i < MAX; ++i){
        if(A.elems[i] == 1 || B.elems[i] == 1){
            bool success = addElement(&s, i);
        }
    }
    return s;
}

Set intersection(Set A, Set B){
    Set s = createSet();
    for(int i = 0; i < MAX; ++i){
        if(A.elems[i] == 1 && B.elems[i] == 1){
            bool success = addElement(&s, i);
        }
    }
    return s; 
}

Set differenceSet(Set A, Set B){
    Set s = createSet();
    for(int i = 0; i < MAX; ++i){
        if(A.elems[i] == 1 && B.elems[i] == 0){
            bool success = addElement(&s, i);
        }
    }
    return s; 
}

Set symmetricDifference(Set A, Set B){
    Set s = createSet();
    for(int i = 0; i < MAX; ++i){
        if(A.elems[i] != B.elems[i]){
            bool success = addElement(&s, i);
        }
    }
    return s; 
}

int cardinality(Set A){
    int card = 0; 
    for(int i = 0; i < MAX; ++i){
        if(A.elems[i] == 1){
            card++;
        }
    }
    return card;
}

bool isElement(Set A, int item){
    for(int i = 0; i < A.count; ++i){
        if(A.elems[i] == item){
            return true;
        }
    }
    return false;
}