#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int studID;
    char studName[16];
    char program[8];
    bool sex; // true - male 
    int level;
} Student;

typedef struct {
    Student *data;
    int count;
    int max; 
} StudDict;

Student createStudent(int studID, char studName[16], char program[8], bool sex, int level);
int getHash(Student s); 
void initDict(StudDict *sd);
bool insertStudent(StudDict *sd, Student s);
bool removeStudent(StudDict *sd, Student s);
Student getStudent(StudDict sd, Student s);
void visualizeStudent(StudDict sd);

void main(){
    StudDict sd;
    initDict(&sd);
  
    insertStudent(&sd, createStudent(3, "jans", "bsit", true, 1));
    insertStudent(&sd, createStudent(4, "gran", "bsit", false, 2));
    insertStudent(&sd, createStudent(20, "josh", "bscs", false, 2));
    insertStudent(&sd, createStudent(25, "jio", "bsis", true, 3));
    visualizeStudent(sd);
    
    removeStudent(&sd, createStudent(4, "gran", "bsit", false, 2));
    visualizeStudent(sd);
    
    Student temp = getStudent(sd, createStudent(25, "jio", "bsis", true, 3));
    
    printf("%d", temp.studID);
}

Student createStudent(int studID, char studName[16], char program[8], bool sex, int level){
    Student s;
    s.studID = studID;
    strcpy(s.studName, studName);
    strcpy(s.program, program);
    s.sex = sex;
    s.level = level;
    return s;
}

int getHash(Student s){
    int count = 0, i = 0, mask = 1;
    while(i <= 31){
        if((s.studID>>i) & 1){
            count += i + 1;
        }
        ++i;
    }
    return count % MAX;
}

void initDict(StudDict *sd){
    sd->count = 0;
    sd->max = MAX;
    sd->data = malloc(sizeof(Student) * MAX);
    for(int i = 0; i < MAX; ++i){
        sd->data[i].studID = 0;
    }
}

bool insertStudent(StudDict *sd, Student s){
    int hash = getHash(s);
    
    if(sd->count > MAX * 0.8){
        return false;
    }
    
    if(sd->data[hash].studID == 0 || sd->data[hash].studID == -1){
        sd->data[hash] = s; 
    } else {
        while(sd->data[hash].studID != 0 && sd->data[hash].studID != -1){
            hash = (hash + 1) % MAX;
        }
        sd->data[hash] = s;
    }
    sd->count++;
    return true;
}

bool removeStudent(StudDict *sd, Student s){
    int hash = getHash(s), i;
    
    if(sd->data[hash].studID == 0){
        return false;
    }
    
    for(i = hash; sd->data[i].studID != -1 && sd->data[i].studID == s.studID; i = (i+1) % MAX){}
    sd->data[i].studID = -1;
    sd->count--; 
    return true;
}

Student getStudent(StudDict sd, Student s){
    int hash = getHash(s), i, flag = 0;
    
    for(i = hash; sd.data[i].studID != 0; i = (i+1) % MAX){
        if (s.studID == sd.data[i].studID){
            return s;
        } 
        if (i == hash && flag != 0){
            break;
        }
        flag = 1;
    }
}

void visualizeStudent(StudDict sd){
    printf("STUDENT ARRAY {\n");
    
    for(int i = 0; i < MAX; ++i){
        printf("[%d]: ", i);
        if(sd.data[i].studID == 0 || sd.data[i].studID == -1){
            printf("Empty\n");
        } else {
            printf("%d %s\n", sd.data[i].studID, sd.data[i].studName);
        }
    }
    
    printf("}\n");
}
