#ifndef MYHEADER_H
#define MYHEADER_H

#define MAX 100
#include <stdbool.h>

typedef struct {
    int elems[MAX];
    int count;
} Set;

Set createSet();
bool addElement(Set *s, int item);
bool removeElement(Set *s, int item);
void displaySet(Set s);

Set union1(Set A, Set B);
Set intersection(Set A, Set B);
Set differenceSet(Set A, Set B);
Set symmetricDifference(Set A, Set B);
int cardinality(Set A);
bool isElement(Set A, int item);

#endif