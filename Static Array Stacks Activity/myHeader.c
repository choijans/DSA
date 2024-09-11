#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "myStack.h"
#include "myHeader.h"

Name createName(String fName, String mName, String lName){
    Name n;
    strcpy(n.fName, fName);
    strcpy(n.mName, mName);
    strcpy(n.lName, lName);
    return n;
}

Student createStudent(int studID, Name studName, String program, int year){
    Student stud;
    stud.studID = studID;
    stud.studName = studName;
    strcpy(stud.program, program);
    stud.year = year;
    return stud;
}