#ifndef MY_HEADER_H
#define MY_HEADER_H

typedef char String[20];

typedef struct {
    String fName, mName, lName;    
} Name;

typedef struct {
    int studID;
    Name studName;
    String program;
    int year;
} Student;

Name createName(String fName, String mName, String lName);
Student createStudent(int studID, Name studName, String program, int year);

#endif