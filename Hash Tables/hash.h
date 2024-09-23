#ifndef HASH_H
#define HASH_H

#include <stdbool.h>
#define MAX 10

typedef struct {
    int studID;
    char studName[20];
    bool sex; //true = MALE
    char program[8];
    int level;
} student;

typedef struct node {
    student stud;
    struct node *link;
} nodeType, *nodePtr;

typedef struct {
    nodePtr elems[MAX];
    int count;
} dictionary;

int getHash(student s);
student createStudent(int studID, char studName[], bool sex, char program[8], int level);
nodePtr createNode(student s);
void initDict(dictionary *d);
bool addStudent(dictionary *d, student s);
bool removeStudent(dictionary *d, student s);
student getStudent(dictionary d, student s);
void visualize(dictionary d);

#endif