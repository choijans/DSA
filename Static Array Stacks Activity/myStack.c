#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "myStack.h"
#include "myHeader.h"

void init (Stack *s){
    s->count = 0;
}

Stack createStack(){
    Stack s;
    s.count = 0; 
    return s;
}

bool isEmpty(Stack s){
    return s.count == 0;    
}

bool isFull(Stack s){
    return s.count >= MAX;
}

//not right to use
void visualize(Stack s){
    printf("List {");
    for(int i = 0; i < s.count; ++i){
        printf("%s", s.elems[i].studName.fName);
        if(i <s.count -1){
            printf(", ");
        }
    }
    printf("}\n");
}

bool push(Stack *s, Student stud){
    if(!isFull(*s)){
        s->elems[(s->count)++] = stud;
        return true;
    }    
    return false; 
}

bool pop(Stack *s){
    if(!isEmpty(*s)){
        (s->count)--;
        return true;
    }    
    return false; 
}

//call this if not empty
Student peek(Stack s){
    return s.elems[s.count-1];
}

// bool isFound(Stack s, int item){
//     bool found = false; 
    
//     while(!isEmpty(s)){
//         if(peek(s) == item){
//             return true;
//         }
//         pop(&s);
//     }
    
//     return found;
// }

// Stack remEven(Stack *s){
//     Stack s1 = createStack();
//     Stack s2 = createStack();
//     while(!isEmpty(*s)){
//         if(peek(*s) % 2 == 0){
//             push(&s1, peek(*s));
//         } else {
//             push(&s2, peek(*s));
//         }
//         pop(s);
//     }
    
//     while(!isEmpty(s2)){
//         push(s, peek(s2));
//         pop(&s2);
//     }
//     return s1;
// }

// Name* getStudentInProgram(Stack s, String program){
//     Name stud[s.count+1]; 

//     int count = 0;
//     while(!isEmpty(s)){
//         Student s1 = peek(s);
//         if(strcmp(s1.program, program) == 0){
//             stud[count++] = s1.studName;
//         }
//         pop(&s);
//     }
//     strcpy(stud[count].fName, "");
//     strcpy(stud[count].mName, "");
//     strcpy(stud[count++].lName, "");
//     Name *newStud = malloc(sizeof(Name)*count);
//     memcpy(newStud, stud, sizeof(Name)*count);
//     return newStud;
// }

Name* getStudentInProgram(Stack s, String program){
    Name *stud = malloc(sizeof(Name)*s.count+1); 

    int count = 0;
    while(!isEmpty(s)){
        Student s1 = peek(s);
        if(strcmp(s1.program, program) == 0){
            stud[count++] = s1.studName;
        }
        pop(&s);
    }
    strcpy(stud[count].fName, "");
    strcpy(stud[count].mName, "");
    strcpy(stud[count++].lName, "");
    stud = realloc(stud, sizeof(Name)*count);
    return stud;
}

void displayNames(Name list[]){
    printf("List {");
    for(int i = 0; strcmp(list[i].fName,"")!= 0; ++i){
        printf("%s", list[i].fName);
        if(strcmp(list[i+1].fName, "") != 0){
            printf(", ");
        }
    }
    printf("}\n");
}