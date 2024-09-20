#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"

Person createPerson(char name[30], int age, char sex){
    Person p;
    strcpy(p.name, name);
    p.age = age;
    p.sex = sex;
    return p;
}

void initStack(Stack *s){
    *s = NULL;
}

bool isEmpty(Stack s){
    return (s == NULL);    
}

void displayStack(Stack s){
    printf("DATA: {\n");
    if(!isEmpty(s)){
        while(s != NULL){
            printf("%s", s->data.name);
            if(s->link != NULL){
                printf(", ");
            }
            s = s->link;
        }
    }
    printf("\n}\n");
}

NodePtr createNode(Person p){
    NodePtr temp = malloc(sizeof(NodeType));
    if(temp != NULL){
        temp->data = p;
        temp->link = NULL;
        return temp;
    }
}

bool push(Stack *s, Person p){
    NodePtr temp = createNode(p);
    temp->link = *s;
    *s = temp;
}

bool pop(Stack *s){
    if(!isEmpty(*s)){
        NodePtr temp = *s;
        *s = temp->link;
        free(temp);
    }    
}

Person peek(Stack s){
    if(!isEmpty(s)){
        return s->data;
    }
}

/*Insert sorted base on lastname. Remember to use the property 
  of the stack using push, pop, and peek functions.*/
bool insertSorted1(Stack *s, Person p) {
    Stack temp;
    initStack(&temp);
    
    while (!isEmpty(*s) && (strcmp(peek(*s).name, p.name) < 0)) {
        push(&temp, peek(*s));
        pop(s);
    }

    push(s, p);
    
    while (!isEmpty(temp)) {
        push(s, peek(temp));
        pop(&temp);
    }
    return true;
}


/*Insert sorted base on lastname. Remember to use the property 
  of the stack but without using push, pop, and peek functions.*/ //NO TRAVERSAL
bool insertSorted2(Stack *s, Person p){
    NodePtr node = createNode(p);
    Stack tempS;
    initStack(&tempS);
    
    if(node == NULL){
        return false; 
    }
    
    while(!isEmpty(*s) && strcmp(p.name, (*s)->data.name) > 0){
        NodePtr temp = *s;
        *s = temp->link;
        temp->link = tempS;
        tempS = temp; 
    }
    
    node->link = *s;
    *s = node;
    
    while(!isEmpty(tempS)){
        NodePtr temp = tempS;
        tempS = temp->link;
        temp->link = *s;
        *s = temp; 
    }
    return true;
}

/*Sort the values based on name. Use flag for ascending 
  or descending. */
void sortStack1(Stack *s, bool flag){
    Stack temp;
    initStack(&temp);
     
    while(!isEmpty(*s)){
        Person p = peek(*s);
        pop(s);
         
        while(!isEmpty(temp) && ((flag && strcmp(peek(temp).name, p.name) > 0) || (!flag && strcmp(peek(temp).name, p.name) < 0))){
            push(s, peek(temp));
            pop(&temp);
        }
         
        push(&temp, p);
    }
     
    while(!isEmpty(temp)){
        push(s, peek(temp));
        pop(&temp);
    }
}


//SORT STACK without push pop peek and NO TRAVERSAL
void sortStack2(Stack *s, bool flag) {
    Stack tempS;
    initStack(&tempS);
    
    while (!isEmpty(*s)) {
        NodePtr temp = *s;
        *s = (*s)->link;
        
        while (!isEmpty(tempS) && ((flag && strcmp(tempS->data.name, temp->data.name) > 0) || (!flag && strcmp(tempS->data.name, temp->data.name) < 0))){
            NodePtr tempTop = tempS;
            tempS = tempS->link;
            tempTop->link = *s;
            *s = tempTop;
        }
        
        temp->link = tempS;
        tempS = temp;
    }
    
    while (!isEmpty(tempS)) {
        NodePtr tempTop = tempS;
        tempS = tempS->link;
        tempTop->link = *s;
        *s = tempTop;
    }
}
