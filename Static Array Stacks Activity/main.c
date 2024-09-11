#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "myStack.h"
#include "myHeader.h"

void main(){
    Stack stackA;
    
    // init(&stackA);
    // visualize(stackA);
    // push(&stackA, 10);
    // visualize(stackA);
    // push(&stackA, 6);
    // visualize(stackA);
    // push(&stackA, 4);
    // visualize(stackA);
    // push(&stackA, 3);
    // visualize(stackA);
    // push(&stackA, 9);
    // visualize(stackA);
    // push(&stackA, 8);
    // int x = 9;
    // printf("Is %d in the stack? %d.\n", x, isFound(stackA, x));
    // for(int i = 0; i < 10; ++i){
    //     pop(&stackA);
    //     visualize(stackA);
    // }
    // Stack newStack = remEven(&stackA);
    // visualize(stackA);
    // visualize(newStack);
    
    Student s1 = createStudent(1001, createName("Jansen", "Kai Xuan", "Choi"), "BSIT", 2);
    Student s2 = createStudent(1002, createName("Jose", "Rafael", "Delgado"), "BSIT", 2);
    Student s3 = createStudent(1003, createName("Josh", "Edward", "Lui"), "BSIT", 2);
    Student s4 = createStudent(1004, createName("Kurt", "Zander", "Kaw"), "BSCS", 2);
    
    init(&stackA);
    visualize(stackA);
    push(&stackA, s1);
    visualize(stackA);
    push(&stackA, s2);
    visualize(stackA);
    push(&stackA, s3);
    visualize(stackA);
    push(&stackA, s4);
    visualize(stackA);
    
    Name *itStack = getStudentInProgram(stackA, "BSIT");
    displayNames(itStack);
}