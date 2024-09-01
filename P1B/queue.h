#ifndef QUEUE_H
#define QUEUE_H

typedef struct Student {
    char name[50];
    int ID;
    char ISBN[20];
    struct Student* prev;
    struct Student* next;
} Student;


void addToReservationQueue(char* name, int ID, char* ISBN);
void removeFromReservationQueue(char* ISBN);
void viewReservationQueue();  

extern Student* head;
extern Student* tail;

#endif
