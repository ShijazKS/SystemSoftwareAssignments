#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "list.h"

Student* head = NULL;
Student* tail = NULL;

Student* createStudent(char* name, int ID, char* ISBN) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    strcpy(newStudent->name, name);
    newStudent->ID = ID;
    strcpy(newStudent->ISBN, ISBN);
    newStudent->prev = NULL;
    newStudent->next = NULL;
    return newStudent;
}

void addToReservationQueue(char* name, int ID, char* ISBN) {
    Book* bk=findBook(availableBooksList,ISBN);
    if(bk!=NULL){
        lendBook(ISBN);
    }else{

    Student* newStudent = createStudent(name, ID, ISBN);
    
    if (tail == NULL) { 
        head = tail = newStudent;
    } else {
        tail->next = newStudent;
        newStudent->prev = tail;
        tail = newStudent;
    }
    }
}

void removeFromReservationQueue(char* ISBN) {
    Student* current = head;
    
    while (current != NULL) {
        if (strcmp(current->ISBN, ISBN) == 0) {
            if (current == head) {
                head = current->next;
                if (head != NULL) {
                    head->prev = NULL;
                } else {
                    tail = NULL; 
                }
            }
            else if (current == tail) {
                tail = current->prev;
                tail->next = NULL;
            }
            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            
            lendBook(ISBN);
            free(current);
            return;
        }
        current = current->next;
    }
}

void viewReservationQueue() {
    Student* current = head;
    
    if (current == NULL) {
        printf("(empty)\n\n");
        return;
    }
    
    while (current != NULL) {
        printf("%s, %d, %s \n", current->name, current->ID, current->ISBN);
        current = current->next;
    }
    printf("\n");
}

