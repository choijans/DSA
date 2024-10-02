#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

//CLOSED HASHING
typedef struct {
    int studID; //union studiD
    char name[20]; //first 5 bytes
    int age;
    bool sex; //male - true
} Student;

typedef struct {
    Student *arr;
    int count;
    int max; 
} dictionary;

int getHash(Student s); //first 3 letters of name + numbers of 0s in studID
Student createStudent(int studID, char name[], int age, bool sex);
void initDict(dictionary *d);
bool addStudent(dictionary *d, Student s);
bool removeStudent(dictionary *d, Student s);
Student getStudent(dictionary *d, Student s);
void showAllStud(dictionary d);
void resizeDictionary(dictionary *d);

void main(){
    dictionary ch;
    initDict(&ch);
    
    addStudent(&ch, createStudent(23102442, "Jans", 19, true));
    addStudent(&ch, createStudent(23102689, "Josh", 20, false));
    addStudent(&ch, createStudent(23101024, "Jio", 21, false));
    addStudent(&ch, createStudent(23100267, "Sep", 15, true));
    
    removeStudent(&ch, createStudent(23101024, "Jio", 21, false));
    showAllStud(ch);
    
    
}

void resizeDictionary(dictionary *d){
    dictionary temp; 
    
    Student* to_delete = d->arr; 
    
    temp.count = 0;
    temp.max = d->max * 2;
    temp.arr = malloc(sizeof(Student) * (temp.max * 2));
    
    for(int i = 0; i < temp.max; ++i){
        temp.arr[i].studID = 0; 
    }
    
    int hash;
    for(int i = 0; i < d->max; ++i){
        hash = getHash(d->arr[i]);
        for(hash = getHash(d->arr[i]); temp.arr[hash].studID != 0 && d->arr[i].studID != -1; hash = (hash+1) % temp.max){}
        temp.arr[hash] = d->arr[i];
        temp.count++;
    }
    *d = temp;
    free(to_delete);
}

//first 3 letters of name + numbers of 0s in studID
int getHash(Student s){
    int sum = 0;
    
    for(int i = 0; i < 3; ++i){
        sum += s.name[i];
    }
    
    for(int i = 0; i < 32; ++i){
        if(((s.studID >> i) & 1) == 0){
            sum++;
        }
    }
    
    return sum % MAX;
}

Student createStudent(int studID, char name[], int age, bool sex){
    Student s;
    s.studID = studID;
    strcpy(s.name, name);
    s.age = age;
    s.sex = sex;
    return s;
}

void initDict(dictionary *d){
    d->count = 0;
    d->max = MAX;
    d->arr = malloc(sizeof(Student) * d->max);
    
    if(d->arr == NULL){
        return; 
    }
    
    for(int i = 0; i < d->max; ++i){
        d->arr[i].studID = 0;
    }
}

bool addStudent(dictionary *d, Student s){
    int hash = getHash(s);
    
    if(d->arr[hash].studID == 0 || d->arr[hash].studID == -1){
        d->arr[hash] = s;
    } else {
        while(d->arr[hash].studID != 0 || d->arr[hash].studID != -1){
            hash = (hash+1) % d->max;
        }
        d->arr[hash] = s;
    }
    d->count++;
    return true; 
}

bool removeStudent(dictionary *d, Student s){
    int hash = getHash(s), i;
    
    if(d->arr[hash].studID == 0){
        return false; 
    } else {
        for(i = hash; d->arr[hash].studID != s.studID && d->arr[hash].studID != -1; i = (i+1) % MAX){}
        d->arr[i].studID = -1;
        d->count--; 
    }
    return true;
}

Student getStudent(dictionary *d, Student s){
    for(int i = getHash(s); d->arr[i].studID != 0; i = (i+1) % d->max){
        if(d->arr[i].studID == s.studID){
            return d->arr[i];
        }
    }
    return createStudent(0, "XXXX", 0, false);
}

void showAllStud(dictionary d){
    printf("STUDENT ARRAY {\n");
    
    for(int i = 0; i < d.max; ++i){
        printf("[%d]: ", i);
        if(d.arr[i].studID == 0 || d.arr[i].studID == -1){
            printf("Empty\n");
        } else {
            printf("%d %s\n", d.arr[i].studID, d.arr[i].name);
        }
    }
    
    printf("}\n");
}

