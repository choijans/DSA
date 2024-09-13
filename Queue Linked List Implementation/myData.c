#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "myData.h"
#include "queue.h"

Name createName(char fName[20], char lName[20]){
    Name n; 
    strcpy(n.fName, fName);
    strcpy(n.lName, lName);
    return n;
}

Student createStudent(int studID, Name studName, char program[8], char sex){
    Student s;
    s.studID = studID;
    s.studName = studName;
    strcpy(s.program, program);
    s.sex = sex; 
    return s; 
}