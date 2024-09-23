#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hash.h"

//get number of bits in studID (count how many ones) + first three letters of name + entire program
int getHash(student s){
    int count1 = 0;
    while(s.studID){
        if(s.studID & 1){
            count1++;
        } 
        s.studID >>= 1;
    }
    
    for(int i = 0; i < 3; ++i){
        count1 += s.studName[i];
    }
    
    for(int i = 0; s.program[i] != '\0'; ++i){
        count1 += s.program[i];
    }
    return count1 % MAX; 
}

student createStudent(int studID, char studName[], bool sex, char program[8], int level){
    student s;
    s.studID = studID;
    strcpy(s.studName, studName);
    s.sex = sex;
    strcpy(s.program, program);
    s.level = level;
    return s; 
}

nodePtr createNode(student s){
    nodePtr temp = malloc(sizeof(nodeType));
    temp->stud = s;
    temp->link = NULL;
    return temp;
}

void initDict(dictionary *d){
    d->count = 0;
    for(int i = 0; i < MAX; ++i){
        d->elems[i] = NULL;
    }
}

bool addStudent(dictionary *d, student s){
    nodePtr newNode = createNode(s);
    int key = getHash(s);
    nodePtr *trav = &(d->elems[key]);
    for(; *trav != NULL && newNode->stud.studID > (*trav)->stud.studID; trav = &(*trav)->link){}
    if(*trav != NULL && newNode->stud.studID == (*trav)->stud.studID){
        printf("Student ID already exists\n");
        return false;
    } else {
        newNode->link = *trav;
        *trav = newNode;
    }
    d->count++;
    return true; 
}

bool removeStudent(dictionary *d, student s){
    int key = getHash(s);
    nodePtr *trav = &(d->elems[key]);
    for(; *trav != NULL && s.studID != (*trav)->stud.studID; trav = &(*trav)->link){}
    if(*trav != NULL){
        nodePtr temp = *trav; 
        *trav = temp->link;
        free(temp);
        return true;
    }
    return false; 
}

student getStudent(dictionary d, student s){
    int key = getHash(s);
    nodePtr trav = (d.elems[key]);
    for(;trav != NULL && trav->stud.studID != s.studID; trav = trav->link){}
    if(trav != NULL){
        return trav->stud;
    }
}

void visualize(dictionary d){
    nodePtr trav;
    printf("-----SET ELEMENTS-----\n");
    for(int i = 0; i < MAX; ++i){
        printf("[%d]: ", i);
        if(d.elems[i] == NULL){
            printf("List is Empty\n");
        } else {
            nodePtr trav; 
            for(trav = d.elems[i]; trav != NULL; trav = trav->link){
                printf("%d, %s\n", trav->stud.studID, trav->stud.studName);
            }
        }
    }
}