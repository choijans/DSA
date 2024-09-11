#ifndef MY_STACK_H
#define MY_STACK_H

#include <stdbool.h>
#include "myHeader.h"
#define MAX 5

typedef struct {
    Student elems[MAX];
    int count;
} Stack;

void init (Stack *s);
Stack createStack();
bool isEmpty(Stack s);
bool isFull(Stack s);
void visualize(Stack s);
void makeNull(Stack *s);

bool push(Stack *s, Student stud);
bool pop(Stack *s);
Student peek(Stack s);
bool isFound(Stack s, String lastName);

Stack remEven(Stack *s);
Name* getStudentInProgram(Stack s, String program);
void displayNames(Name list[]);

#endif