#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "set.h"

void main(){
    //GPT MADE THE PROMPT :D
    Set setA = createSet();
    Set setB = createSet();

    addElement(&setA, 1);  
    addElement(&setA, 3); 
    addElement(&setA, 5);  

    addElement(&setB, 2);  
    addElement(&setB, 3);  
    addElement(&setB, 6);  

    printf("Set A: ");
    displaySet(setA);
    printf("\n");

    printf("Set B: ");
    displaySet(setB);  
    printf("\n");
    
    printf("\n-----UNION SET-----\n");
    Set unionAB = unionSet(setA, setB);
    printf("Union of A and B: ");
    displaySet(unionAB);  
    printf("\n");
    
    printf("\n-----INTERSECTION SET-----\n");
    Set intersectionAB = intersectionSet(setA, setB);
    printf("Intersection of A and B: ");
    displaySet(intersectionAB);  
    printf("\n");
    
    printf("\n-----DIFFERENCE SET-----\n");
    Set differenceAB = differenceSet(setA, setB);
    printf("Difference of A and B (A - B): ");
    displaySet(differenceAB); 
    printf("\n");

    printf("\n-----SYMMETRIC DIFFERENCE SET-----\n");
    Set symmetricDiffAB = symmetricDifferenceSet(setA, setB);
    printf("Symmetric Difference of A and B: ");
    displaySet(symmetricDiffAB); 
    printf("\n");

    printf("Is element %d in setA? %s\n", 3, isElement(setA, 3) ? "Yes" : "No");

    printf("Is element %d in setA? %s\n", 4, isElement(setA, 4) ? "Yes" : "No");

    printf("Cardinality of setA: %d\n", cardinality(setA));  
    printf("Cardinality of setB: %d\n", cardinality(setB));
}