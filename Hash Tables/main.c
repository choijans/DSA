#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hash.h"

void main(){
    dictionary d;
    initDict(&d);
    
    addStudent(&d, createStudent(10001, "Jio3", true, "BSIT", 2));
    addStudent(&d, createStudent(10001, "Jio3", true, "BSIT", 2));
    addStudent(&d, createStudent(10003, "Jio2", true, "BSIS", 1));
    
    visualize(d);
    
    student temp = getStudent(d, createStudent(10002, "Josh", true, "BSCS", 3));
    printf("%d", temp.studID);
}
