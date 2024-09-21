#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "myHeader.h"

void main(){
    Set s1 = createSet();
    Set s2 = createSet();
    
    addElement(&s1, 2);
    addElement(&s1, 69);
    addElement(&s1, 80);
    
    addElement(&s2, 2);
    addElement(&s2, 70);
    addElement(&s2, 80);
    
    Set s3 = symmetricDifference(s1, s2);
    int count = cardinality(s3);
    printf("%d\n", count);
    displaySet(s3);
}
