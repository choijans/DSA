#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "myData.h"
#include "queue.h"

void initQueue(Queue *q){
    q->head = NULL;
    q->tail = NULL;
}

Queue createQueue(){
    Queue q;
    q.head = NULL;
    q.tail = NULL;
    return q;
}

NodePtr createNode(Data d){
    NodePtr temp = malloc(sizeof(NodeType));
    temp->elem = d;
    temp->link = NULL;
    return temp;
}

bool isEmpty(Queue q){
    if(q.head == NULL && q.tail == NULL){
        return true;
    }
    return false;
}

void display(Queue q){
    Queue tempQ;
    initQueue(&tempQ);
    printf("DATA: {");
    while(q.head != NULL){
        NodePtr temp = q.head;
        q.head = temp->link;
        printf("\n[\n\tStudent ID: %d\n", temp->elem.studID);
        printf("\tStudent Name: %s %s\n", temp->elem.studName.fName, temp->elem.studName.lName);
        printf("\tProgram: %s\n", temp->elem.program);
        printf("\tSex: %c\n]", temp->elem.sex);
        
        if(tempQ.head == NULL){
            tempQ.head = temp;
        } else {
            tempQ.tail->link = temp;
        }
        tempQ.tail = temp;
    }

    if (q.head != NULL){
        tempQ.tail->link = q.head;
    }
    q.head = tempQ.head;
    q.tail = tempQ.tail;
    printf("\n}\n");
}

void visualize(Queue q){
    NodePtr trav = q.head;
    printf("DATA: {");
    while(trav != NULL){
        printf("\n[\n\tStudent ID: %d\n", trav->elem.studID);
        printf("\tStudent Name: %s %s\n", trav->elem.studName.fName, trav->elem.studName.lName);
        printf("\tProgram: %s\n", trav->elem.program);
        printf("\tSex: %c\n]", trav->elem.sex);
        if(trav->link != NULL) {
            printf(",\n");
        }
        trav = trav->link;
    }
    printf("}\n");
}

void makeNull(Queue *q){
    q->head = NULL;
    q->tail = NULL;
}

bool enqueue(Queue *q, Data d){
    NodePtr temp = createNode(d);
    if(temp == NULL) {
        return false;
    }
    
    if(q->tail == NULL){
        q->head = temp;
        q->tail = temp;
        return true;
    }
    
    q->tail->link = temp;
    q->tail = temp;
    return true;
}

bool dequeue(Queue *q){
    if(!isEmpty(*q)){
        NodePtr temp = q->head;
        q->head = temp->link;
        
        if(q->head == NULL){
            q->tail = NULL;
        }
        
        free(temp);
        return true;
    }
    return false;
}

Data front(Queue q){
    if(!isEmpty(q)){
        return q.head->elem;
    }
}

Data back(Queue q){
    if(!isEmpty(q)){
        return q.tail->elem;
    }
}

int getCount(Queue q){
    int count = 0; 
    NodePtr trav = q.head;
    while(trav != NULL){
        count++;
        trav = trav->link;
    }
    return count;
}

Queue createNewQueue(Queue q){
    Queue new = createQueue();
    NodePtr trav = q.head;
    while(trav != NULL){
        enqueue(&new, trav->elem);
        trav = trav->link;
    }
    return new; 
}

Name *getStudent(Queue q, char *program, char sex){
    int count = getCount(q), i = 0;
    Queue newQ = createNewQueue(q);
    Name *n = malloc(sizeof(Name)*count+1);
    
    while(!isEmpty(newQ)){
        Data d = front(newQ);
        if(strcmp(program, "") == 0 && sex == ' '){
            n[i++] = d.studName;
        } else if(strcmp(program, "") == 0){
            if(d.sex == sex){
                n[i++] = d.studName;
            }
        } else if (sex == ' '){
            if(strcmp(d.program, program) == 0){
                n[i++] = d.studName;
            }
        } else if(strcmp(d.program, program) == 0 && d.sex == sex){
            n[i++] = d.studName;
        }
        dequeue(&newQ);
    }
    
    Name emptyName = {"", ' '};
    n[i]=emptyName;
    return n;
}

//WITHOUT ENQUEUE DEQUEUE N FRONT FUNCTION N NO TRAVERSAL
bool insertSorted(Queue *q, Data d) {
    Queue tempQ;
    initQueue(&tempQ);

    NodePtr newNode = createNode(d);
    if(newNode == NULL){
        return false;
    }
    
    while(q->head != NULL && strcmp(d.studName.lName, q->head->elem.studName.lName) > 0){
        NodePtr temp = q->head;
        q->head = temp->link;
        if(tempQ.head == NULL){
            tempQ.head = temp;
        } else {
            tempQ.tail->link = temp;
        }
        tempQ.tail = temp;
        
    }

    if(tempQ.head == NULL){
        tempQ.head = newNode;
    } else {
        tempQ.tail->link = newNode;
    }
    
    tempQ.tail = newNode;
    if (q->head != NULL){
        tempQ.tail->link = q->head;
    }
    
    q->head = tempQ.head;
    q->tail = tempQ.tail;
    return true;  
}
